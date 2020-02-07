#include "Double_Word_Score.h"

Double_Word_Score::Double_Word_Score(int _x, int _y)
{
	x = _x;
	y = _y;
}

Double_Word_Score::~Double_Word_Score()
{
	if (tile)
	{
		delete tile;
	}
}

Double_Word_Score::Double_Word_Score(Double_Word_Score & orig)
{
	int x = orig.x;
	y = orig.y;;
	tile = new Tile{ orig.get_tile()->get_letter(), orig.get_tile()->get_value(), orig.get_tile()->get_language() };
}
