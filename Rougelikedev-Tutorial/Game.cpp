#include "Game.h"

#include "controller.h"
#include "Display.h"
#include "EntityFactory.h"
#include "Map.h"


int Game::energy_charge_per_turn_ = 1;
int Game::energy_loss_per_turn_ = 1;
int Game::min_turn_energy_level_ = 3;
entt::registry Game::registry = {};

void Game::Init()
{
	map_ = std::make_unique<Map>();

	map_->Generate(80,25);
}

void Game::Run()
{
	//Entity hero{5, 5, 0x5E};
	//entities_.push_back(new Entity{5, 5, 0xE01A});
	Display::Open();
	Controller controller{};

	EntityFactory factory;

	entities_.push_back(factory.CreateEntity("hero",5,5));
	entities_.push_back(factory.CreateEntity("orc",15,15));
	while (!game_should_end_)
	{
		Display::Clear();
		Display::EnableLayer(0);
		map_->Display();
		
		Display::EnableLayer(1);
		for (auto* entity : entities_)
		{
			if (entity->CanMove())
			{
				const auto key = Controller::ReadKey();
				if (Controller::QuitPressed(key))
				{  
					game_should_end_ = true;
					break;
				}
				auto cmd = controller.FromKey(key);
				if (cmd)
				{
					cmd->ActOn(entity);
					if (cmd->Allowed(key))
						cmd->Execute(key);
				}
			}
			Display::PrintEntity(entity);
		}
		
		Display::Blit();
	}
	Display::Dispose();
}
