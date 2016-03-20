#pragma once

#include <vector>

class ZmeikaCell
{
private:
	std::vector<int> coords_;
public:
	ZmeikaCell(int x, int y)
	{
		coords_.push_back(x);
		coords_.push_back(y);
	};
	ZmeikaCell()
	{
		ZmeikaCell(0, 0);
	};
	ZmeikaCell(int x, int y, int z)
	{
		coords_.push_back(x);
		coords_.push_back(y);
		coords_.push_back(z);
	};
	int getCoord(int axis)
	{
		return coords_[axis];
	};
	void move(int axis, int amount)
	{
		coords_[axis] += amount;
	};
};

namespace std
{
	template<> struct less<ZmeikaCell>
	{
		bool operator() (ZmeikaCell lhs, ZmeikaCell rhs) const
		{
			return lhs.getCoord(0) < rhs.getCoord(0);
		}
	};
};
