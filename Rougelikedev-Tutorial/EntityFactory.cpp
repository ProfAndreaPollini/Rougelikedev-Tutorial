#include "EntityFactory.h"

void EntityFactory::RegisterComponentFactory()
{
	component_registry_["kind"] = [](nlohmann::json params, const Entity* entity)
	{
		std::cout << params << std::endl;
		std::string kind = params["/kind_id"_json_pointer];
		Game::registry.assign<Kind>(entity->id(), kind);
	};
}

EntityFactory::EntityFactory(): registry(), component_registry_()
{
	std::ifstream i("file.json");

	RegisterComponentFactory();


	nlohmann::json j;
	i >> j;
	std::cout << j;
	for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it)
	{
		std::cout << it.key() << " : " << it.value() << "\n";
		registry.emplace(it.key(), it.value());
	}
}

Entity* EntityFactory::CreateEntity(const std::string& entity_kind, const int x, const int y)
{
	const auto pos = registry.find(entity_kind);
	if (pos != registry.end())
	{
		auto recipe = pos->second;
		const wchar_t glyph = recipe["/glyph"_json_pointer];
		auto components = recipe["/components"_json_pointer];
		auto* entity = new Entity(x, y, glyph);
		for (nlohmann::json::iterator it = components.begin(); it != components.end(); ++it)
		{
			std::cout << it.key() << " " << typeid(it.key()).name() << " : " << it.value() << "\n";
			auto component_pos = component_registry_.find(it.key());
			if (component_pos != component_registry_.end())
			{
				component_pos->second(it.value(), entity);
			}
		}
		return entity;
	}
	return nullptr;
}
