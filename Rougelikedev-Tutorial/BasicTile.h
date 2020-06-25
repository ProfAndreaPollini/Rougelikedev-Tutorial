#pragma once
#include "Position2.h"



class Tile
{
public:
	virtual ~Tile() = default;
	virtual void Display() const  = 0;
};

class TileObject : public Tile
{
public:
	TileObject(const Position2& pos, const int w, const int h): pos_(pos),
		  w_(w),
		  h_(h) {}
	virtual bool contains(const Position2& pos) = 0;
	virtual bool is_walkable(const Position2& pos) = 0;
protected:
	const Position2 pos_;
	int w_=1;
	int h_=1;
};


class BasicTile : public TileObject
{
public:


	BasicTile(const int x, const int y, const wchar_t glyph)
		:TileObject{{x,y},1,1},
		  glyph_(glyph)
	{
	}

	virtual ~BasicTile() = default;
	[[nodiscard]] wchar_t glyph() const {return glyph_;}
	[[nodiscard]] virtual bool IsWalkable() const = 0;
	[[nodiscard]] int x() const { return pos_.x(); }
	[[nodiscard]] int y() const { return pos_.y(); }

	void Display() const  override;
	bool contains(const Position2& pos) override
	{
		return pos == pos_;
	}

	bool is_walkable(const Position2& pos) override
	{
		return contains(pos) && IsWalkable();
	}
private:
	 
	wchar_t glyph_;
};

