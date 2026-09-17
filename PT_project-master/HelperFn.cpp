
#include "HelperFn.h"
#include <string>
#include <cstddef>
#include <cctype>
bool isDouble(const string& s)
{
	try {
		size_t pos;        //pos will store the index of the first character wasn't converted
		stod(s, &pos);    //stod try to convert s to double  
		return (pos == s.size());
		/*if the index found is equal to the size that
		meanes that stod found that the end of the string
		coudn't convert which has index = the size  */
	}
	catch (...)
	{
		return false;
	}
}

bool isCppKeyword(const string& input) {
	// Array of C++ keywords
	const string cppKeywords[] = {
		"alignas","alignof","and","and_eq","asm","auto",
		"bitand","bitor","bool","break","case","catch",
		"char","char16_t","char32_t","class","const",
		"constexpr","const_cast","continue","decltype",
		"default","delete","do","double","dynamic_cast",
		"else","enum","explicit","export","extern","false",
		"float","for","friend","goto","if","inline",
		"int","long","mutable","namespace","new","noexcept",
		"not","not_eq","nullptr","operator","or","or_eq",
		"private","protected","public","register","reinterpret_cast",
		"return","short","signed","sizeof","static","static_assert",
		"static_cast","struct","switch","template","this",
		"thread_local","throw","true","try","typedef",
		"typeid","typename","union","unsigned","using",
		"virtual","void","volatile","wchar_t","while","xor","xor_eq"
	};

	// Number of keywords
	int n = sizeof(cppKeywords) / sizeof(cppKeywords[0]);

	// Check each keyword
	for (int i = 0; i < n; i++) {
		if (input == cppKeywords[i])
			return true;  // found a keyword
	}

	return false;  // not a keyword
}



bool IsValue(string input)
{
	// checks if the input string is a double value
	// return true if it's double value, false otherwise
	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.
	//TODO: complete this function

	return isDouble(input);
}

bool IsVariable(string input)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise
	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.
	//TODO: complete this function
	int size = input.size();

	if (size == 0) return false;
	if (!isalpha(input[0]) && input[0] != '_') return false;
	if (isCppKeyword(input)) return false;
	for (int i = 0; i < size; i++)
	{
		if (input[i] == '_') continue;
		if (isalnum(input[i])) continue;
		return false;

	}

	return true;
}

OpType ValueOrVariable(string input)
{
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)
	//TODO: complete this function
	if (IsValue(input)) return VALUE_OP;
	if (IsVariable(input)) return VARIABLE_OP;
	return INVALID_OP;
}
