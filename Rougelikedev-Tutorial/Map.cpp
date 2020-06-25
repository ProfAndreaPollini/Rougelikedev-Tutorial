#include "Map.h"



//const TileObject* Map::TileAt(const int x, const int y) const
//{
//	const Position2 tilePos{x,y};
//	const auto pos = std::find_if(tiles_.begin(),
//	                              tiles_.end(),
//	                              [tilePos](auto* el) -> bool
//	                              {
//		                              return el->contains(tilePos);
//	                              });
//	if (pos != tiles_.end()) return *pos;
//	return nullptr;
//}

bool Map::IsWalkable(const int x, const int y) const
{
	const Position2 tile_pos{x,y};

	const auto pos = std::find_if(tiles_.begin(),
	                              tiles_.end(),
	                              [tile_pos](auto* el) -> bool
	                              {
		                              return el->contains(tile_pos);
	                              });
	if (pos != tiles_.end() && (*pos)->is_walkable({x,y})) return true;
	return false;
}

void Map::Display() const
{
	for (const auto* tile : tiles_)
	{
		tile->Display();
	}
}
