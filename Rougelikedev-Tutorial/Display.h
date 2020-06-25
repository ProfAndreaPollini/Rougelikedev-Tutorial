#pragma once

#include "BearLibTerminal.h"
#include "Entity.h"

class Display
{
public:
	static void Open()
	{
		terminal_open();
		terminal_set("window: size=80x25, cellsize=auto, title='Omni: menu';"
			"font: D:\\dev\\rougelikedev-tutorial\\Rougelikedev-Tutorial\\x64\\Debug\\UbuntuMono-R.ttf ,size=28;"
		"0xE000: D:\\dev\\rougelikedev-tutorial\\Rougelikedev-Tutorial\\assets\\onebitpackkenney\\Tilesheet\\colored_packed.png, size=16x16, spacing=1x1");
	}

	static void Clear()
	{
		terminal_clear();
	}

	static void PrintEntity(const Entity* hero)
	{
		const auto pos= Game::registry.get<Position>(hero->id());
		const auto renderable = Game::registry.get<Renderable>(hero->id());
		
		terminal_put(pos.x,pos.y,renderable.glyph);
	}

	static void Put(int x, int y, wchar_t glyph)
	{
		terminal_put(x,y,glyph);
	}

	static void EnableLayer(int n_layer)
	{
		terminal_layer(n_layer);
	}

	static void Blit()
	{
		terminal_refresh();
	}

	static void Dispose()
	{
		terminal_close();
	}
};
