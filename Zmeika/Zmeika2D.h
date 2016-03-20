#pragma once

#include "ZmeikaCell.h"
#include "Zmeika.h"
#include "ZmeikaMap.h"

#include <vector>
#include <chrono>
#include <map>

using namespace std::chrono;

class Zmeika2DStandardWall : public IZmeikaObject
{
private:
	std::vector<ZmeikaCell> data_;
public:
	Zmeika2DStandardWall(int x, int y, bool vertical, int length)
	{
		for (int i = 0; i < length; i++)
		{
			data_.push_back(ZmeikaCell(vertical ? x : (x + i), vertical ? (y + i) : y));
		}
	};
	void interact(Zmeika* zmeika)
	{
		zmeika->die();
	};
	std::vector<ZmeikaCell> getCells()
	{
		return data_;
	};
};

class Zmeika2DStandardFood : public IZmeikaObject
{
private:
	ZmeikaCell cell_;
public:
	Zmeika2DStandardFood(ZmeikaCell cell)
	{
		cell_ = cell;
	};
	void interact(Zmeika* zmeika)
	{
		zmeika->eat();
	};
	std::vector<ZmeikaCell> getCells()
	{
		return{ cell_ };
	};
};

class Zmeika2DStandard : public Zmeika
{
private:
	std::vector<ZmeikaCell> cells_;
	bool isDead_;
	int axis_; // 0 = x, 1 = y
	bool direction_;
	milliseconds speed_ = milliseconds(500);
	milliseconds timer_;
public:
	Zmeika2DStandard();
	~Zmeika2DStandard();
	void move(ZmeikaMap *pMap);
	void eat();
	void die()
	{
		isDead_ = true;
	};
	bool isDead()
	{
		return isDead_;
	};
	void changeDirection(int axis, bool direction)
	{
		axis_ = axis;
		direction_ = direction;
	};
	std::vector<ZmeikaCell> getCells()
	{
		return cells_;
	};
};