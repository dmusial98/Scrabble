#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

class Dictionary {

	std::set<std::string> words;

public:
	Dictionary();
	~Dictionary() = default;
	bool correct_word(std::string word);


};