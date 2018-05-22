#include "Heretic.h"
#include "Character.h"

using namespace std;

Heretic::Heretic(std::string name, double HP, double strength, double intelligence) : Enemy(name, HP, strength, intelligence) {}

Heretic::~Heretic() {}

void Heretic::attack(const Battle &battle)
{
	//TODO: Implement attack
	
	//Placeholder
	battle.getCharacter()->defend(2);
}

string Heretic::getType() const
{
	return "Heretic";
}
