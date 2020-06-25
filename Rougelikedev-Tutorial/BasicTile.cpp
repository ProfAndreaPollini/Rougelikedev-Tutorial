#include "BasicTile.h"

#include "Display.h"

void BasicTile::Display() const
{
	Display::Put(pos_.x(),pos_.y(), glyph_);
}


