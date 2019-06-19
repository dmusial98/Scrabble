#ifndef DOUBLE_WORD_SCORE
#define DOUBLE_WORD_SCORE

#include "Field.h"

class Double_Word_Score : public Field {


public:
	Double_Word_Score(int _x, int _y);
	~Double_Word_Score();
	Double_Word_Score(Double_Word_Score &);
};

#endif