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
	std::vector<double> getAttributes() const;
private:
	double agility;
};

#endif

