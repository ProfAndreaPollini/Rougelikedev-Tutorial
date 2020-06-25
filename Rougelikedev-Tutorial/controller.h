#pragma once
#include <BearLibTerminal.h>
#include <map>

#include "Command.h"

class Controller
{
public:
	Controller();

	static int ReadKey() { return  terminal_read();}
	static bool QuitPressed(const int key)  { return key == TK_ESCAPE;}

	std::shared_ptr<Command> FromKey(const int key)
	{
		auto it = key_to_command_.find(key);
		if (it == key_to_command_.end())
		{
			return nullptr;
		}

		return it->second;
		
	}
	
	std::map<wchar_t,std::shared_ptr<Command>> key_to_command_;
};

