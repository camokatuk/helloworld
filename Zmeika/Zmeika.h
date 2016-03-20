#pragma once

#include "ZmeikaCell.h"

class ZmeikaMap;

class Zmeika
{

public:
	virtual void eat() = 0;
	virtual void move(ZmeikaMap* pMap) = 0;
	virtual void die() = 0;
	virtual bool isDead() = 0;
	virtual void changeDirection(int axis, bool direction) = 0;
	virtual std::vector<ZmeikaCell> getCells() = 0;
};



