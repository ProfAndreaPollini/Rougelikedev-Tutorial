#include "Entity.h"

#include "Game.h"

bool Entity::CanMove()
{
	auto& turn_energy =  Game::registry.get<TurnStats>(entity_).turn_energy;
	if (turn_energy > Game::min_turn_energy_level_)
	{
		turn_energy -= Game::energy_loss_per_turn_;
		return true;
	}
	turn_energy += Game::energy_charge_per_turn_;
	return false;

}

void Entity::Move(const int dx, const int dy) const
{
	//x_ += dx;
	//y_ += dy;
	auto& pos = Game::registry.get<Position>(entity_);
	pos.x += dx;
	pos.y += dy;
}

Entity::~Entity()
{
	Game::registry.destroy(entity_);
}
