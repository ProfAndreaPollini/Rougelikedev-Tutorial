#include "Room.h"

#include "Display.h"

void Room::Display() const
{
	for(auto j = pos_.y(); j < pos_.y() + h_; j++)
	{
		Display::Put(pos_.x(), j,0xE030 );
		Display::Put(pos_.x() + w_-1, j,0xE030 );
	}

	for(auto i = pos_.x()+1; i < pos_.x() + w_-1; i++)
	{
		Display::Put(i, pos_.y(),0xE030 );
		Display::Put(i, pos_.y()+ h_ -1,0xE030 );
	}

	for(auto j = pos_.y()+1; j < pos_.y() + h_-1; j++)
	{
		for(auto i = pos_.x()+1; i < pos_.x() + w_-1; i++)
		{
			Display::Put(i, j,0xE040 );
		}
	}
}
