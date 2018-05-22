#include "Skeleton.h"
#include "Character.h"

using namespace std;

Skeleton::Skeleton(string name, double HP , double strength, double intelligence) : Enemy(name, HP, strength, intelligence) {}

Skeleton::~Skeleton() {}

void Skeleton::attack(const Battle &battle)
{
	Character* &c = battle.getCharacter();

	c->defend(strength + 0.1*c->getIntelligence());
}

double Skeleton::getHP() const
{
	return HP;
}

string Skeleton::getType() const
{
	return "Skeleton";
}
