#pragma once
#include "Game.h"

struct Position
{
	int x;
	int y;
};

struct Renderable
{
	wchar_t glyph;
};

struct TurnStats
{
	int turn_energy;
};

struct Stats
{
	float health;
};

struct Kind
{
	std::string type;
};


class Entity
{
public:
	Entity(const int x, const int y, const wchar_t glyph):
	x_{x}, y_{y},glyph_{glyph}//, turn_energy_{0}
	{
		entity_ = Game::registry.create();
		Game::registry.assign<Position>(entity_,x,y);
		Game::registry.assign<Renderable>(entity_,glyph);
		Game::registry.assign<TurnStats>(entity_,0);
		Game::registry.assign<Stats>(entity_,100.0f);
	}

	const int x() const
	{
		const auto pos = Game::registry.get<Position>(entity_);
		return pos.x;
	}
	const int y() const {
		const auto pos = Game::registry.get<Position>(entity_);
		return pos.y;
	}
	
	int glyph() const
	{
		const auto renderable = Game::registry.get<Renderable>(entity_);
		return renderable.glyph;
	}

	[[nodiscard]] auto id() const {return entity_;}

	bool CanMove();
	void Move(const int dx, const int dy) const;

	~Entity();

private:
	int x_;
	int y_;
	wchar_t glyph_;
	//int turn_energy_;
	entt::registry::entity_type entity_;
};

