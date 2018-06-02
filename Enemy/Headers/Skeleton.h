#ifndef SKELETON_H
#define SKELETON_H

#include "Enemy.h"

class Skeleton : public Enemy
{
public:
	Skeleton(std::string, double = 32, double = 3, double = 0);
	virtual ~Skeleton();
	void attack(const Battle &);
	double getHP() const;
	std::string getType() const;
};

#endif

