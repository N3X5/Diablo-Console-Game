#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Enemy.h"
#include "Battle.h"


class Character
{
public:
	Character(std::string, unsigned short,
		double, double,
		double);

	~Character();

	virtual void attack(const Battle &) = 0;
	virtual void defend(double);
	virtual void levelUp();
	virtual void printBattleStats();

	virtual void addKill();
	
	bool isDead() const;

	std::string getName() const;
	double getHP() const;
	double getIntelligence() const;
	double getStrength() const;

protected:
	std::string name;
	unsigned short level;
	unsigned short killed_enemies;

	//Current values
	double HP;
	double strength;
	double intelligence;

private:
	double strength_initial;
	double intelligence_initial;
};

#endif