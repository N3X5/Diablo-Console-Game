#include "BountyHunter.h"
#include <iostream>

using namespace std;

BountyHunter::BountyHunter(string name) : Character(name, 1, 80, 9, 6), agility(10) {}

BountyHunter::~BountyHunter() {}

void BountyHunter::attack(const Battle & battle)
{
	double attackPts = 0;

	if (battle.getTurn() == 5 || (battle.getTurn() + 1) % 6 == 0)
		attackPts = agility + 0.4*intelligence + 0.6*strength;
	else
		attackPts = 0.8*agility;

	battle.getEnemy()->defend(attackPts);
}

void BountyHunter::levelUp()
{
	Character::levelUp();

	agility += 4;
	cout << "Agility: " << round(agility) << endl;
}

std::vector<double> BountyHunter::getAttributes() const
{
	vector<double> attributes = Character::getAttributes();
	attributes.push_back(agility);

	return attributes;
}
