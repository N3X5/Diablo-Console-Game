#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
#include "Battle.h"

class Enemy
{
public:
	Enemy(std::string, double, double, double);
	virtual ~Enemy();

	virtual void attack(const Battle &) = 0;
	virtual void defend(double);
	virtual std::string getType() const = 0;
	virtual void printBattleStats();

	bool isDead() const;

	double getHP() const;
	double getStrength() const;
	double getIntelligence() const;
	
	std::string getName() const;

	static std::string getRandomEnemyName(std::vector<std::string> &);

protected:
	std::string name;
	double HP;
	double strength;
	double intelligence;
};

#endif
