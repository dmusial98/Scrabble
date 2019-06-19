#ifndef TRIPLE_WORD_SCORE_H
#define TRIPLE_WORD_SCORE_H

#include "Field.h"

class Triple_Word_Score : public Field {


public:
	Triple_Word_Score(int _x, int _y);
	~Triple_Word_Score();
	Triple_Word_Score(Triple_Word_Score &);

};

#endif