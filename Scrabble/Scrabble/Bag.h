#ifndef BAG_H
#define BAG_H

#include "Constexpr.h"
#include "Tile.h"
#include <random>
#include <ctime>
#include <iostream>

class Bag {

	Tile* tiles[no_of_tiles_in_bag];
	int no_of_free_tiles = no_of_tiles_in_bag - 1;

public: 
	struct EX_empty_bag {};

	Bag();
	~Bag();
	Tile* give_tile();
	int get_number_of_free_tiles();
	Tile* exchange_tile(Tile* old_tile);

};

#endif