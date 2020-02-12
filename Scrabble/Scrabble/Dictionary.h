#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <codecvt>
#include <vector>
#include <thread>
#include <locale>

class Dictionary {

	std::set<std::wstring> words;

public:
	Dictionary(int language);
	~Dictionary() = default;
	bool correct_word(std::wstring word, int language);


};