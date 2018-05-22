#include <iostream>
#include "Battle.h"
#include "Character.h"
#include "Enemy.h"

using namespace std;

//Some informational messages for the player, before we start
Battle::Battle(Character* &character, Enemy* &enemy) : character(character), enemy(enemy), turn(0)
{ 
	cout << endl
		<< "You(" << character->getName()
		<< ") are now going to fight "
		<< enemy->getName() << " the "
		<< enemy->getType() << endl
		<< "You have the following stats" << endl;
	character->printBattleStats();

	vector<double> attributes = character->getAttributes();

	for (size_t i = 0; i < attributes.size(); i++) 
	{
		switch(i) 
		{
		case 0:
			cout << "Strength: ";
			break;
		case 1:
			cout << "Intelligence: ";
			break;
		case 2:
			cout << "Agility: ";
			break;
		}
		cout << attributes[i] << endl;
	}

	cout << "This monster has the following stats:" << endl
		<< "HP: " << enemy->getHP() << endl
		<< "Strength: " << enemy->getStrength() << endl
		<< "Intelligence: " << enemy->getIntelligence() << endl
		<< "Good luck!" << endl << endl;
}

Battle::~Battle() {}

Character* & Battle::getCharacter() const
{
	return character;
}

Enemy* & Battle::getEnemy() const
{
	return enemy;
}

unsigned short Battle::getTurn() const
{
	return turn;
}

bool Battle::isWon() const
{
	return enemy->isDead();
}

bool Battle::isLost() const
{
	return character->isDead();
}

void Battle::nextTurn()
{
	turn++;

	if (turn != 1) //Print stats for every turn, after the first one has finished
	{
		if ((turn - 1) % 2 == 0) //Stats for player
		{
			cout << "Results after turn " << turn - 1 << " for " << character->getName() << " :" << endl;
			character->printBattleStats();
		}
		else //Stats for enemy
		{
			cout << "Results after turn " << turn - 1 << " for " << enemy->getName() << " the " << enemy->getType() << " :" << endl;
			enemy->printBattleStats();
		}

		cout << endl;
	}

	cout << "Turn " << turn << ". ";

	if (turn % 2 != 0) //Player attacks
	{
		cout << character->getName() << " attacks." << endl;
		character->attack(*this);
	}
	else //Enemy attacks
	{
		cout << enemy->getName() << " the " << enemy->getType() << " attacks." << endl;
		enemy->attack(*this);
	}
}
