#include "Dictionary.h"

std::wstring wstring_from_bytes_d(std::string const& str)
{
	size_t requiredSize = 0;
	std::wstring answer;
	wchar_t *pWTempString = NULL;

	/*
	* Call the conversion function without the output buffer to get the required size
	*  - Add one to leave room for the NULL terminator
	*/
	requiredSize = mbstowcs(NULL, str.c_str(), 0) + 1;

	/* Allocate the output string (Add one to leave room for the NULL terminator) */
	pWTempString = (wchar_t *)malloc(requiredSize * sizeof(wchar_t));
	if (pWTempString == NULL)
	{
		printf("Memory allocation failure.\n");
	}
	else
	{
		// Call the conversion function with the output buffer
		size_t size = mbstowcs(pWTempString, str.c_str(), requiredSize);
		if (size == (size_t)(-1))
		{
			printf("Couldn't convert string\n");
		}
		else
		{
			answer = pWTempString;
		}
	}


	if (pWTempString != NULL)
	{
		delete[] pWTempString;
	}

	return answer;
}

Dictionary::Dictionary()
{
	std::wifstream file_in;
	//file_in.open("Dictionary/Collins Scrabble Words (2015).txt");

	file_in.open("Dictionary/s³ownik.txt");


	if (!file_in.is_open())
		std::cout << "cannot open dictionary file :(";

	std::wstring bufor_wstr;
	
	while (!file_in.eof()) 
	{
		file_in.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
		//setting up input from file in UTF-8 format encoding

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
