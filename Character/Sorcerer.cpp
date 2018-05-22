#include "Sorcerer.h"
#include <iostream>

using namespace std;

Sorcerer::Sorcerer(std::string name) : Character(name, 1, 70, 4, 12), mana(100), mana_max(100) {}

Sorcerer::~Sorcerer() {}

void Sorcerer::attack(const Battle & battle)
{
	//Placeholder
	double attackPts = 5; //To implement

	battle.getEnemy()->defend(attackPts);

	mana -= 0.1*mana_max;
	if (mana < 0)
		mana = 0;
}

void Sorcerer::levelUp()
{
	Character::levelUp();

	mana_max += mana_max / 10;
	mana = mana_max;
	cout << "Mana: " << mana << "/" << mana_max << endl;
}

void Sorcerer::printBattleStats()
{
	Character::printBattleStats();
	cout << "Mana: " << mana << "/" << mana_max << endl;
}

void Sorcerer::addKill()
{
	mana = mana_max;
	Character::addKill();
}
