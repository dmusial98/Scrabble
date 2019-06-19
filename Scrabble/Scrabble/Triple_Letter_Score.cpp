#include "Triple_Letter_Score.h"

Triple_Letter_Score::Triple_Letter_Score(int _x, int _y)
{
	x = _x;
	y = _y;
}

Triple_Letter_Score::~Triple_Letter_Score()
{
	if (tile)
	{
		delete tile;
	}
}

Triple_Letter_Score::Triple_Letter_Score(Triple_Letter_Score & orig)
{
	int x = orig.x;
	y = orig.y;;
	tile = new Tile{ orig.get_tile()->get_letter(), orig.get_tile()->get_value() };
}
