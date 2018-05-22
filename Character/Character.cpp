#include "Character.h"
#include <math.h>
#include <iostream>

using namespace std;

Character::Character(std::string name, unsigned short level, 
	double HP, double strength,
	double intelligence) : name(name), level(level),
	HP(HP), strength(strength), 
	intelligence(intelligence),
	strength_initial(strength),
	intelligence_initial(intelligence),
	killed_enemies(0) {}

Character::~Character() {}

void Character::defend(double attackPts)
{
	HP -= (attackPts-(attackPts*(strength/100)));
}

void Character::levelUp()
{
	level++;
	killed_enemies = 0;
	cout << endl << "Congratulations, you are now level " << level << "!" << endl;

	HP += round(HP*0.1);

	double initial_points = strength_initial + intelligence_initial;

	strength += round((strength_initial / initial_points) * 5);
	intelligence += round((intelligence_initial / initial_points) * 5);

	cout << "Updated stats:" << endl
		<< "HP: " << round(HP) << endl
		<< "Strength: " << round(strength) << endl
		<< "Intelligence: " << round(intelligence) << endl;
}

void Character::printBattleStats()
{
	cout << "HP: " << round(HP) << endl;
}

void Character::addKill()
{
	killed_enemies++;

	if (killed_enemies == std::pow(2, level))
		levelUp();
}

bool Character::isDead() const
{
	return round(HP)<=0;
}

string Character::getName() const
{
	return name;
}

double Character::getHP() const
{
	return HP;
}

double Character::getIntelligence() const
{
	return intelligence;
}

double Character::getStrength() const
{
	return strength;
}

std::vector<double> Character::getAttributes() const
{
	vector<double> attributes = { strength, intelligence };

	return attributes;
}
