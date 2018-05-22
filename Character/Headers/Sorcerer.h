#ifndef SORCERER_H
#define SORCERER_H

#include "Character.h"

class Sorcerer : public Character
{
public:
	Sorcerer(std::string);
	~Sorcerer();
	void attack(const Battle &);
	void levelUp();
	void printBattleStats();
	void addKill();
private:
	double mana;

	double mana_max;
};

#endif

