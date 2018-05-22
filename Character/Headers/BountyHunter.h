#ifndef BOUNTYHUNTER_H
#define BOUNTYHUNTER_H

#include "Character.h"

class BountyHunter : public Character 
{
public:
	BountyHunter(std::string);
	~BountyHunter();
	void attack(const Battle &);
	void levelUp();
private:
	double agility;
};

#endif

