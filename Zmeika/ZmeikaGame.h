#pragma once

#include "ZmeikaMap.h"
#include "Zmeika2D.h"

class ZmeikaGame
{
private:
	ZmeikaMap* map_;
	Zmeika2DStandard* zmeika_;
public:
	ZmeikaGame();
	~ZmeikaGame();

	void start();
	void update();
	void onKeyEvent(int key);
	void end();

	ZmeikaMap* getMap()
	{
		return map_;
	}
	Zmeika* getZmeika()
	{
		return zmeika_;
	}
};
