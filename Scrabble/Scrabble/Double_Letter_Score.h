#ifndef DOUBLE_LETTER_SCORE_H
#define DOUBLE_LETTER_SCORE_H

#include "Field.h"

class Double_Letter_Score : public Field {

public:
	Double_Letter_Score(int _x, int _y);
	~Double_Letter_Score();
	Double_Letter_Score(Double_Letter_Score &);
};

#endif