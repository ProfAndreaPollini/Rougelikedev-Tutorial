#pragma once

#include <iostream>
#include <fstream>


#include "Entity.h"
#include "json.h"

class EntityFactory
{
public:

	EntityFactory();

	Entity* CreateEntity(const std::string& entity_kind, const int x, const int y);


private:
	void RegisterComponentFactory();

	std::map<std::string, nlohmann::json> registry;
	std::map<std::string, std::function<void(nlohmann::json, const Entity*)>> component_registry_;

};

