#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Character.h"

class Barbarian : public Character 
{
public:
	Barbarian(std::string);
	~Barbarian();
	void attack(const Battle &enemy);
	void defend(double);
	void printBattleStats();
private:
	double rage;
	double battle_rage_modifier;

	const double RAGE_MAX = 100;
};

#endif

