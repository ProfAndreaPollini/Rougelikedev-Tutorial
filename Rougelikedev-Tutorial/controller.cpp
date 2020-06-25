#include "controller.h"

#include "MoveCommand.h"

Controller::Controller() : key_to_command_({})
{
	key_to_command_.emplace(TK_A,std::make_shared<MoveCommand>());
	key_to_command_.emplace(TK_D,std::make_shared<MoveCommand>());
	key_to_command_.emplace(TK_W,std::make_shared<MoveCommand>());
	key_to_command_.emplace(TK_S,std::make_shared<MoveCommand>());
}
