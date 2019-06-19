#ifndef TRIPLE_LETTER_H
#define TRIPLE_LETTER_H

#include "Field.h"

class Triple_Letter_Score : public Field {

public:

	Triple_Letter_Score(int _x, int _y);
	~Triple_Letter_Score();
	Triple_Letter_Score(Triple_Letter_Score &);
};

#endif