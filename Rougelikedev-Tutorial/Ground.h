#pragma once
#include "BasicTile.h"
class Ground :
    public BasicTile
{
public:
		Ground(const int x, const int y) :BasicTile {x,y,0xB7} {}
	Ground() : Ground(0,0) {  }

	[[nodiscard]] bool IsWalkable() const override { return true;}
};

