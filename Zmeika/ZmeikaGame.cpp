#include "systemclass.h"
#include "Zmeika.h"
#include "Zmeika2D.h"
#include "ZmeikaGame.h"

ZmeikaGame::ZmeikaGame()
{
	zmeika_ = new Zmeika2DStandard;
	map_ = new ZmeikaMap;
	map_->addObject(new Zmeika2DStandardWall(-10, -10, true, 20));
	map_->addObject(new Zmeika2DStandardWall(10, 10, true, -20));
	map_->addObject(new Zmeika2DStandardWall(-10, 10, false, 20));
	map_->addObject(new Zmeika2DStandardWall(10, -10, false, -20));
}

ZmeikaGame::~ZmeikaGame()
{
	delete map_;
	delete zmeika_;
}

void ZmeikaGame::start()
{

}

void ZmeikaGame::onKeyEvent(int key)
{
	if (key == VK_NUMPAD4)
	{
		zmeika_->changeDirection(0, false);
	}

	if (key == VK_NUMPAD5)
	{
		zmeika_->changeDirection(1, false);
	}

	if (key == VK_NUMPAD6)
	{
		zmeika_->changeDirection(0, true);
	}

	if (key == VK_NUMPAD8)
	{
		zmeika_->changeDirection(1, true);
	}
}

void ZmeikaGame::end()
{

}
