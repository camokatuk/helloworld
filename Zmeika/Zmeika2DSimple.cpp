#include "Zmeika2D.h"

#include <chrono>

using namespace std::chrono;

Zmeika2DStandard::Zmeika2DStandard()
{
	cells_.push_back(ZmeikaCell(0, 0));
	cells_.push_back(ZmeikaCell(-1, 0));
	cells_.push_back(ZmeikaCell(1, 0));

	direction_ = 1;
	axis_ = 0;

	isDead_ = false;

	timer_ = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
	);
}

Zmeika2DStandard::~Zmeika2DStandard()
{

}

void Zmeika2DStandard::move(ZmeikaMap * pMap)
{
	milliseconds now = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
	);

	if (now - timer_ < speed_)
	{
		return;
	}

	timer_ += speed_ * ((now - timer_) / speed_);

	for (auto &cell : cells_)
	{
		cell.move(axis_, direction_ ? +1 : -1);
	}
	
	IZmeikaObject* object = pMap->getObject(cells_[0]);
	object->interact(this);
}

void Zmeika2DStandard::eat()
{
}

