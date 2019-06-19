#include "Triple_Word_Score.h"

Triple_Word_Score::Triple_Word_Score(int _x, int _y)
{
	x = _x;
	y = _y;

}

Triple_Word_Score::~Triple_Word_Score()
{
	if (tile)
	{
		delete tile;
	}
}

Triple_Word_Score::Triple_Word_Score(Triple_Word_Score & orig)
{
	int x = orig.x;
	y = orig.y;;
	tile = new Tile{ orig.get_tile()->get_letter(), orig.get_tile()->get_value() };
}
