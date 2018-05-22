#include "InitialSetup.h"
#include "LowerCaseString.h"
#include "Barbarian.h"
#include "Sorcerer.h"
#include "BountyHunter.h"
#include <iostream>
#include <string>

using namespace std;

//Get name and type
Character * setupCharacter()
{
	Character* character;

	string character_type;

	do {
		cout << "Pick a character type - B/b for Barbarian, S/s for Sorcerer, BH/bh for Bounty Hunter: ";

		getline(cin, character_type);

		character_type = getLowerCase(character_type);
	} while (!(!character_type.compare("b") || !character_type.compare("s") || !character_type.compare("bh")));

	string name;

	do
	{
		cout << "Pick a name for your character, with a max length of 20 characters: ";

		getline(cin, name);
	} while (name.length() == 0 || name.length()>20);

	if (!character_type.compare("b"))
		character = new Barbarian(name);
	else if (!character_type.compare("s"))
		character = new Sorcerer(name);
	else
		character = new BountyHunter(name);

	return character;
}

//Setup a map with a specific size, and place a character on it
Map* setupMap(Character* &character)
{
	Map* map;

	int map_size = 0;

	do
	{
		string map_size_str;

		cout << "Pick a map size AxA where A can range from 5 to 8: ";

		getline(cin, map_size_str);
		try { //In case the player decides to use something other than a number
			map_size = stoi(map_size_str);
		}
		catch (exception e) {}

	} while (!(map_size >= 5 && map_size <= 8));

	map = new Map(map_size, character);

	return map;
}

//Ask if the player wants to try again
bool playAgainQuery()
{	
	string answer;

	do
	{
		cout << "Do you want to play again? (Y/N): ";

		getline(cin, answer);
		answer = getLowerCase(answer);
	} while (!(!answer.compare("y") || !answer.compare("n")));


	if (!answer.compare("y"))
		return true;
	else
		return false;
}
