#include "Heretic.h"
#include "Character.h"
#include <iostream>

using namespace std;

Heretic::Heretic(std::string name, double HP, double strength, double intelligence) : Enemy(name, HP, strength, intelligence) {}

Heretic::~Heretic() {}

void Heretic::attack(const Battle &battle)
{
	Character* &character = battle.getCharacter();

	vector<double> attributes = character->getAttributes();
	double lowest_attribute = INT_MAX;

	for (size_t i = 0; i < attributes.size(); i++) 
	{
		if (attributes[i] < lowest_attribute)
			lowest_attribute = attributes[i];
	}


	cout << lowest_attribute << endl;
	character->defend(lowest_attribute);
}

string Heretic::getType() const
{
	return "Heretic";
}
