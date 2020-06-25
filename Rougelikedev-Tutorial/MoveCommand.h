#pragma once
#include <BearLibTerminal.h>
#include <iostream>

#include "Command.h"
#include "Entity.h"
#include "Game.h"

class MoveCommand final : public Command
{
	bool Allowed(wchar_t key) override
	{
		auto x = entity_->x();
		auto y = entity_->y();

		switch (key)
		{
		case TK_A: x -= 1;
			break;
		case TK_D: x += 1;
			break;
		case TK_W: y -= 1;
			break;
		case TK_S: y += 1;
			break;
		}

		//const auto* tile = Game::GetInstance().map_->TileAt(x, y);

		return Game::GetInstance().map_->IsWalkable(x,y);
	}

	void Execute(wchar_t key) override
	{
		std::cout << "MOVE!\n";
		switch (key)
		{
		case TK_A: entity_->Move(-1, 0);
			break;
		case TK_D: entity_->Move(1, 0);
			break;
		case TK_W: entity_->Move(0, -1);
			break;
		case TK_S: entity_->Move(0, 1);
			break;
		}
	}
};
