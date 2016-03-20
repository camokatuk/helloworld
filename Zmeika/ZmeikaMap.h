#pragma once

#include "ZmeikaCell.h"
#include "Zmeika.h"

#include <vector>
#include <map>

class IZmeikaObject
{
public:
	virtual void interact(Zmeika* zmeika) = 0;
	virtual std::vector<ZmeikaCell> getCells() = 0;
};

class ZmeikaMap
{
private:
	std::map<ZmeikaCell, IZmeikaObject*> objects_;
public:
	ZmeikaMap()
	{
	};
	~ZmeikaMap()
	{
		objects_.clear();
	}
	void addObject(IZmeikaObject* object)
	{
		for (auto &cell : object->getCells())
		{
			objects_[cell] = object;
		}
	}
	IZmeikaObject* getObject(ZmeikaCell zmeikaHeadCell)
	{
		return objects_[zmeikaHeadCell];
	}
};