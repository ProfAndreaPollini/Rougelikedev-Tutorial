#pragma once
#include <iostream>
#include <random>
#include <vector>


#include "GrassTile.h"
#include "Ground.h"
#include "PerlinNoise.h"
#include "BasicTile.h"
#include "Rng.h"
#include "Room.h"

class Map
{
public:
	Map() : noise_(std::random_device{}), tiles_()
	{
	noise_.reseed(12345);
		
	}


	~Map()
	{
		for (auto*tile : tiles_)
		{
			delete tile;
		}
		tiles_.clear();
	}
	
	void Generate(int w, int h)
	{
		tiles_.clear();

		int n_rooms = 10;
		//bool placed = false;
		for(auto i = 0; i < n_rooms; ++i)
		{
			auto room_size = Rng::Instance().RandomIntInRange(5,8);
			auto room_x = Rng::Instance().RandomIntInRange(1,70);
			auto room_y = Rng::Instance().RandomIntInRange(1,30);
			std::cout << room_size<< std::endl;
			auto* room = new Room{room_x,room_y,room_size,room_size};
			
			//for(auto j = 0; j < 10;++j)
			//{
				auto toReplace = std::any_of(tiles_.begin(), tiles_.end(),
					[room](auto tile)
					{
						return room->overlaps(*dynamic_cast<Room*>(tile));
					});
				if (!toReplace)
					tiles_.push_back(room);
				
			//}
		}
		//tiles_.resize(w*h,' ');
		/*for (auto y = 0; y < h; y++) {
			for (auto x = 0; x < w; x++) {
				const auto v = noise_.accumulatedOctaveNoise2D_0_1(x/(w*1.0),y/(h*1.0),8);
				if (v > 0.5) {
					std::cout << " ";
					tiles_.push_back(new Ground{x,y});
				} else
				{
					std::cout << "#";
					tiles_.push_back(new GrassTile{x,y});
				}
			}
			std::cout << std::endl;
		}

		tiles_.push_back(new Room{10,10,10,10});*/
	}

	//const BasicTile* TileAt(const int x, const int y) const;
	bool IsWalkable(const int x, const int y) const;
	[[nodiscard]] std::vector<TileObject*> Tiles() const { return tiles_;}

	void Display() const ;
	
private:
	siv::PerlinNoise noise_;
	std::vector<TileObject*> tiles_;
	
};

