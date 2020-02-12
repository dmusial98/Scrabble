#include "Dictionary.h"


Dictionary::Dictionary(int language)
{
	std::wifstream file_in;

	if(language != 0)
		file_in.open("Dictionary/Collins Scrabble Words (2015).txt");
	else
		file_in.open("Dictionary/slownik.txt");


	if (!file_in.is_open())
		std::cout << "cannot open dictionary file :(";

	file_in.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	//setting up input from file in UTF-8 format encoding

	std::wstring bufor_wstr;
	
	while (!file_in.eof()) 
	{
		std::getline(file_in, bufor_wstr);

		words.insert(bufor_wstr);
	}  //loading words into dictionary
}

bool Dictionary::correct_word(std::wstring word, int language)
//language - 0 -> polish  1 -> english
{
	if(language)
		std::transform(word.begin(), word.end(), word.begin(), ::toupper);

	std::set<std::wstring>::iterator iter = words.find(word);

	if (iter == words.end()) 
	{
		return false;
	}
	else return true;
}
