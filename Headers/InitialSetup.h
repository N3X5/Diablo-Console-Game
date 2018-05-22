#ifndef INITIAL_SETUP_H
#define INITIAL_SETUP_H

#include "Character.h"
#include "Map.h"

Character* setupCharacter();
Map* setupMap(Character* &);
bool playAgainQuery();

#endif

