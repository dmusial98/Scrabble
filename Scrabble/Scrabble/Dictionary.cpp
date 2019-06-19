#include "Dictionary.h"

Dictionary::Dictionary()
{
	std::ifstream file_in;
	file_in.open("Dictionary/Collins Scrabble Words (2015).txt");

	if (!file_in.is_open())
		std::cout << "cannot open dictionary file :(";

	std::string bufor;
	while (!file_in.eof()) 
	{
		file_in >> bufor;
		words.insert(bufor);
	}  //loading words to dictionary
}

bool Dictionary::correct_word(std::string word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	std::set<std::string>::iterator iter = words.find(word);

	if (iter == words.end()) 
	{
		return false;
	}
	else return true;
}
