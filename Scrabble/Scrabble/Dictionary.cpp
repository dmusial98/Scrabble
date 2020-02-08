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
	std::ifstream file_in;
	file_in.open("Dictionary/Collins Scrabble Words (2015).txt");

	if (!file_in.is_open())
		std::cout << "cannot open dictionary file :(";

	std::string bufor_str;
	std::wstring bufor_wstr;
	while (!file_in.eof()) 
	{
		file_in >> bufor_str;
		bufor_wstr = wstring_from_bytes_d(bufor_str); //converting string to wstring

		words.insert(bufor_wstr);
	}  //loading words to dictionary
}

bool Dictionary::correct_word(std::wstring word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	std::set<std::wstring>::iterator iter = words.find(word);

	if (iter == words.end()) 
	{
		return false;
	}
	else return true;
}
