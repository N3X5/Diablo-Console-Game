#include "LowerCaseString.h"
#include <locale>

using namespace std;

//Used for convenience when the player inputs a string
string getLowerCase(string baseString)
{
	string lower_case = "";

	locale loc;

	for (string::size_type i = 0; i < baseString.length(); i++)
		lower_case += tolower(baseString[i], loc);

	return lower_case;
}