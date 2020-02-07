#include "Double_Letter_Score.h"

Double_Letter_Score::Double_Letter_Score(int _x, int _y)
{
	x = _x;
	y = _y;
}

Double_Letter_Score::~Double_Letter_Score()
{
	if (tile)
	{
		delete tile;
	}
}

Double_Letter_Score::Double_Letter_Score(Double_Letter_Score & orig)
{
	int x = orig.x; 
	y = orig.y;;
	tile = new Tile{ orig.get_tile()->get_letter(), orig.get_tile()->get_value(), orig.get_tile()->get_language()};

}
