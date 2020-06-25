#pragma once
#include "BasicTile.h"

class GrassTile : public BasicTile
{
	
public:
	GrassTile(const int x, const int y) :BasicTile {x,y,0xE005} {}
	GrassTile() : GrassTile(0,0) {  }

	[[nodiscard]] bool IsWalkable() const override { return false;}
};
