#pragma once
class Position2
{
public:
	Position2(const int x, const int y)
		: x_(x),
		  y_(y)
	{
	}

	[[nodiscard]] int x() const {return x_;}
	[[nodiscard]] int y() const {return y_;}

	
private:
	int x_;
	int y_;
};

using Size2 = Position2;


inline bool operator==(const Position2& lhs, const Position2& rhs)
{
    return lhs.x() == rhs.x() && lhs.y() == rhs.y();
}
