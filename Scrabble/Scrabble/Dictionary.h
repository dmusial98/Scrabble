#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include<locale>

class Dictionary {

	std::set<std::wstring> words;

public:
	Dictionary();
	~Dictionary() = default;
	bool correct_word(std::wstring word, int language);


};