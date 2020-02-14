#ifndef PLAYER_H
#define PLAYER_H

#include "Tile.h"
#include "string"
#include "Bag.h"



class Player {

	Tile* own_tiles[no_of_tiles_for_player]{ nullptr };
	int points = 0;
	std::wstring name;
	bool empty_tiles = true;

	float scale_x = 1;
	float scale_y = 1;

public:
	struct EX_exchange_lack_of_tiles {};
	
	Player(Bag &bag, std::wstring name);
	~Player() = default;

	void exchange_tiles(Bag &bag);
	void get_tiles(Bag &bag);
	
	std::wstring get_name();
	int get_points();
	
	void set_points(int p);
	void set_name(std::wstring n);
	Tile * get_tile(int index);
	void set_tile(int index, Tile *t);
	void set_empty_tiles(bool s);

	void display_own_tiles(sf::RenderWindow &window);
	
	Player & operator+=(int points);
	Player & operator-=(int points);

	bool any_last_used();
	void reset_all_last_used_and_outline();
	int get_no_free_tiles();

	int count_points_from_tiles();

};

#endif