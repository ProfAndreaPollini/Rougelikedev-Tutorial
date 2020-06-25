#pragma once
#include <algorithm>

#include "BasicTile.h"
#include "Position2.h"


class Room : public TileObject
{
public:
	Room(const int x, const int y, const int w, const int h)
		:TileObject{{x,y},w,h}
	{
	}

	Room(const Position2& pos, const Size2&size)
	:TileObject{pos,size.x(),size.y()}
	{
		
	}


	void Display() const override;
	bool contains(const Position2& pos)  override
	{
		return (pos_.x() <= pos.x() && pos.x() < pos_.x() + w_) &&
			(pos_.y() <= pos.y() && pos.y() < pos_.y() + h_);
	}

	bool overlaps(Room room) const
	{
		Position2 vertices[] = {{pos_.x()+w_,pos_.y()},
			{pos_.x()+w_,pos_.y()},
			{pos_.x(),pos_.y()+h_},
			{pos_.x()+w_,pos_.y()+h_},
		}; 
		return std::any_of(std::begin(vertices), std::end(vertices),
			[&room]( auto vertex)
		{
			return room.contains(vertex);
		});
	}
	
	bool is_walkable(const Position2& pos) override
	{
		return true;
	}
private:
	
};

