#include "Field.h"

void Field::display(sf::RenderWindow &window)
{
	if (tile) {
		if(tile->get_tick())
			tile->display(window);
		else
			tile->display(left_border_pix + tile_size_pix * x, up_border_pix + tile_size_pix * y, window);
	}
}

void Field::set_x(int s)
{
	x = s;
}

void Field::set_y(int s)
{
	y = s;
}

int Field::get_x()
{
	return x;
}

int Field::get_y()
{
	return y;
}

void Field::set_tile(Tile *t)
{
	tile = t;
}

Tile * Field::get_tile()
{
	return tile;
}
