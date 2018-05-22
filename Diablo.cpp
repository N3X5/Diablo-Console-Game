#include "stdafx.h"
#include "Diablo.h"

using namespace std;

Diablo::Diablo(string name) : Enemy(name, 350, 8, 4), Heretic(name, 350, 8, 4), Skeleton(name, 350, 8, 4), metamorphosis(0) {}

Diablo::~Diablo() {}

void Diablo::attack(const Battle &battle)
{
	if (!metamorphosis)
	{
		Skeleton::attack(battle);
		metamorphosis = 1;
	}
	else
	{
		Heretic::attack(battle);
		metamorphosis = 0;
	}
}

string Diablo::getType() const
{
	return "Dialbo";
}


