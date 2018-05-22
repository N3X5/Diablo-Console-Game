#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Enemy.h"
#include "Skeleton.h"

class Necromancer : public Enemy
{
public:
	Necromancer(std::string);
	~Necromancer();
	void attack(const Battle &);
	void defend(double);
	std::string getType() const;
	void printBattleStats();
private:
	Skeleton servant;
};

#endif

