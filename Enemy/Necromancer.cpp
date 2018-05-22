#include "Necromancer.h"
#include "Character.h"
#include <iostream>

using namespace std;

Necromancer::Necromancer(std::string name) : Enemy(name, 65, 2, 7), servant("Servant") {}

Necromancer::~Necromancer() {}

void Necromancer::attack(const Battle &battle)
{
	Character* &c = battle.getCharacter();

	if (!servant.isDead())
		c->defend(servant.getHP() / 10 + intelligence);
	else if ((battle.getTurn() - 2) % 6 == 0)
	{
		servant = { "Servant" };
		c->defend(servant.getHP() / 10 + intelligence);
	}
	else
		c->defend(intelligence);
}

void Necromancer::defend(double attackPts)
{
	if (!servant.isDead())
		servant.defend(attackPts);
	else
		Enemy::defend(attackPts);
}

std::string Necromancer::getType() const
{
	return "Necromancer";
}

void Necromancer::printBattleStats()
{
	Enemy::printBattleStats();

	if (!servant.isDead())
	{
		cout << "Necromancer servant stats: " << endl;
		servant.printBattleStats();
	}
	else
		cout << "This necromancer does not have a living servant." << endl;
}
