#ifndef HERETIC_H
#define HERETIC_H

#include "Enemy.h"

class Heretic : public Enemy
{
public:
	Heretic(std::string, double = 20, double = 1, double = 4);
	virtual ~Heretic();
	void attack(const Battle &);
	std::string getType() const;
};

#endif
