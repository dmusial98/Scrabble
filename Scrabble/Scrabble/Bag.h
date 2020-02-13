#ifndef BAG_H
#define BAG_H

#include "Constexpr.h"
#include "Tile.h"
#include <random>
#include <iostream>
#include <chrono>

class Bag {

public:
	struct EX_empty_bag {};

private:
	Tile* eng_tiles[no_of_tiles_in_bag];
	Tile* pl_tiles[no_of_tiles_in_bag];
	int no_of_free_tiles = no_of_tiles_in_bag - 1;
	Tile::Language_ver lang_ver = Tile::Language_ver::Polish;
	Tile** tiles = pl_tiles;

public:		
	Bag();
	~Bag();
	void set_language(Tile::Language_ver lv);
	Tile::Language_ver get_language();
	Tile* give_tile();
	int get_number_of_free_tiles();
	Tile* exchange_tile(Tile* old_tile);


};

#endif