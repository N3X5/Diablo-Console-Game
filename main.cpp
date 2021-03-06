#include <iostream>
#include <vector>

#include "Character.h"
#include "Enemy.h"
#include "Map.h"
#include "InitialSetup.h"
#include "LowerCaseString.h"

using namespace std;

Character* character; //Character for current game
Map* map; //Map for current game
bool play_again = true;

int main()
{
	cout << "Welcome to Diablo v0.5!"
		<< endl
		<< "In this game you will fight and kill monsters and develop your character!";

	while (play_again) { //Loop as many times as the player wants
		cout << endl << endl << endl;

		character = setupCharacter();
		map = setupMap(character);

		map->printMap();

		while (!character->isDead() && !map->allEnemiesAreDead()) //Keep the game going
		{
			MOVE_DIRECTION move_direction = Map::getMoveDirection();

			if (!map->moveCharacter(move_direction)) //If invalid don't print map and retry in another direction
				continue;

			if (map->enemyAndCharacterAreOnSameTile()) //Start a battle
			{
				vector<size_t> character_position = map->getCharacterPosition();

				Enemy* enemy = map->getEnemyAtPosition(character_position[0], character_position[1]); //Get the right enemy

				Battle b(character, enemy); //New battle

				while (!b.isWon() && !character->isDead()) //Keep going until someone dies
					b.nextTurn();

				if (b.isLost())
					break; //Break the loop and print death message
				else
				{
					cout << endl << "Congratulations, you have won the battle!" << endl;
					character->addKill(); //Add kills until we level up the character
				}
			}

			map->printMap();
		}

		if (character->isDead())
			cout << endl << "You have died!" << endl;
		if (map->allEnemiesAreDead())
			cout << endl << "Congratulations, you have won the game!" << endl;

		//Free memory
		delete character;
		delete map;

		play_again = playAgainQuery();
	}

    return 0;
}

