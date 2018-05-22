#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(std::string name, double HP, double strength, double intelligence) : name(name), HP(HP),
strength(strength), intelligence(intelligence) {}

Enemy::~Enemy() {}

void Enemy::defend(double attackPts)
{
	HP -= (attackPts - (attackPts*(strength / 100)));
}

void Enemy::printBattleStats()
{
	cout << "HP: " << HP << endl;
}

bool Enemy::isDead() const
{
	return HP<=0;
}

double Enemy::getHP() const
{
	return HP;
}

double Enemy::getStrength() const
{
	return strength;
}

double Enemy::getIntelligence() const
{
	return intelligence;
}

string Enemy::getName() const
{
	return name;
}

string Enemy::getRandomEnemyName(vector<string> &enemy_names)
{
	string name = "no_name";

	size_t number_of_names = enemy_names.size();
	cout << number_of_names << endl;
	if (number_of_names != 0)
	{
		size_t name_index = rand() % number_of_names;
		name = enemy_names[name_index];
		enemy_names.erase(enemy_names.begin() + name_index);
	}

	return name;
}
