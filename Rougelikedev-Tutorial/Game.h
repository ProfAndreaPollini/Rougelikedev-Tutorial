#pragma once
#include <iostream>
#include <vector>

#include <entt/entt.hpp>

#include "Map.h"

class Entity;


class Game
{
public:
	static int energy_charge_per_turn_;
	static int energy_loss_per_turn_;
	static int min_turn_energy_level_;

	static Game& GetInstance()
	{
		static Game instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}

	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	void Init();

	void Run();

	static entt::registry registry;

private:
	Game() : entities_()
	{
		std::cout << "Entities = " << entities_.size() << std::endl;
	}

	friend class MoveCommand;

	
	
	std::unique_ptr<Map> map_;
	std::vector<Entity*> entities_;
	bool game_should_end_ = false;
	
};
