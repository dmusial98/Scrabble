#ifndef NORMAL_FIELD_H
#define NORMAL_FIELD_H

#include "Field.h"

class Normal_Field : public Field {
public:
	Normal_Field(int _x, int _y);
	~Normal_Field();
	Normal_Field(Normal_Field &);
};

#endif