#ifndef FIELD_H
#define FIELD_H

#include "Constexpr.h"
#include "Tile.h"

class Field {

protected:
	int x = -1, y = -1;
	Tile* tile = nullptr;	

public:
	virtual void display(sf::RenderWindow &window, float scale_x, float scale_y);

	virtual void set_tile(Tile *t);
	virtual Tile * get_tile();
	virtual void set_x(int s);
	virtual void set_y(int s);
	virtual int get_x();
	virtual int get_y();
};

#endif 