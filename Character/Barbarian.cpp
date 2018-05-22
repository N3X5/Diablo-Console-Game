#include "Barbarian.h"
#include <iostream>

using namespace std;

Barbarian::Barbarian(string name) : Character(name, 1, 100, 10, 3),
	rage(0), battle_rage_modifier(0) {}

Barbarian::~Barbarian() {}

void Barbarian::attack(const Battle & battle)
{
	if(battle.getTurn()==1) 
	{
		battle_rage_modifier = (rage / 5) / 100;
		rage = 0;
	}

	rage += 2;
	if (rage > RAGE_MAX)
		rage = 100;

	double attackPts = strength + 0.2*intelligence;

	battle.getEnemy()->defend(attackPts + attackPts*battle_rage_modifier);
}

void Barbarian::defend(double attackPts)
{
	rage += 3;
	if (rage > RAGE_MAX)
		rage = 100;

	Character::defend(attackPts);
}

void Barbarian::printBattleStats()
{
	Character::printBattleStats();
	cout << "Rage: " << rage << "/" << RAGE_MAX << endl;
}
