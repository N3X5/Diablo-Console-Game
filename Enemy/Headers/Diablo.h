#ifndef DIABLO_H
#define DIABLO_H

#include "Heretic.h"
#include "Skeleton.h"

class Diablo : public Heretic, public Skeleton
{
public:
	Diablo(std::string);
	~Diablo();
	void attack(const Battle &);
	std::string getType() const;
private:
	//0 - Skeleton, 1 - Heretic
	bool metamorphosis;
};

#endif
