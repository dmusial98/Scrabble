#include "Normal_Field.h"

Normal_Field::Normal_Field(int _x, int _y)
{
	x = _x;
	y = _y;
}

Normal_Field::~Normal_Field()
{
	if (tile)
		delete tile;
}

Normal_Field::Normal_Field(Normal_Field & orig)
{
	int x = orig.x;
	y = orig.y;;
	tile = new Tile{ orig.get_tile()->get_letter(), orig.get_tile()->get_value(), orig.get_tile()->get_language() };

}
