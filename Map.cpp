#include "Map.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "LowerCaseString.h"

using namespace std;

Map::Map(size_t map_size, Character* &character) : map_size(map_size), character(character)
{
	//Reset enemy names with every new map
	enemy_names = { "Balzhak", "Ashek", "Crabbs", "Haxxor",
		"Hellion", "Krusk", "Ghezrim", "Dragus", "Gholash", "Fezuul",
		"Brakan", "Busaw", "Celik", "Ekthul", "Enkidu", "Erach", "Ghas",
		"Grimmaw", "Growler", "Haures", "Hurax", "Jezeb", "Jhorum",
		"Kamyr", "Kao'Ahn", "Khatun", "Kroisos", "Lacuni", "Lucious",
		"Lummock", "Caustus", "Misgen", "Skomara", "Lamiel", "Malfeas",
		"Mange", "Manning", "Mehshak", "Merrium", "Morlu", "Almash",
		"Arsect", "Ashangu", "Axgore" };
	
	srand(time(0)); //Seed for rand()
	generateMap();
}

Map::~Map()
{
	for (size_t i = 0; i < enemies.size(); i++)
		delete enemies[i]; //Free enemies memory after work with map is done
}

//Print the map
void Map::printMap()
{
	cout << endl << "Current map (Empty fields are marked with -):" << endl << endl;

	for (size_t i = 0; i < map_size * 25 + 3; i++)
		cout << "#"; //Upper border

	cout << endl;

	for (size_t i = 0; i < map_size; i++)
	{
		cout << "# "; //Left border
		for (size_t j = 0; j < map_size; j++)
		{
			cout << setw(25) << std::left; //Some formatting

			if (character_position[0] == i && character_position[1] == j)
				cout << character->getName(); //Where our character is at
			else if (!boolean_map[i][j]) //Empty field
				cout << "-";
			else
			{
				for (size_t k = 0; k < enemy_positions.size(); k++) //Find our monster from the list
				{
					vector<size_t> position = enemy_positions[k];

					if (position[0] == i && position[1] == j)
					{
						Enemy* &enemy = enemies[k];

						if (!enemy->isDead())
						{
							string enemy_name_type = enemy->getName() + "(" + enemy->getType() + ")";
							cout << enemy_name_type;
						}
						else //Dead monster
							cout << "-";
					}
				}
			}
		}
		cout << "#" << endl; //Right border
	}

	for (size_t i = 0; i < map_size * 25 + 3; i++)
		cout << "#"; //Lower border

	cout << endl << endl;
}

//Shift the character location on the map. False - the move was unsuccessful, True - the move was successful
bool Map::moveCharacter(MOVE_DIRECTION direction)
{
	//Temporary position, to check if all is ok
	int altered_character_position[2] = { character_position[0], character_position[1] };

	switch(direction) 
	{
	case UP:
		altered_character_position[0]--;
		break;
	case DOWN:
		altered_character_position[0]++;
		break;
	case LEFT:
		altered_character_position[1]--;
		break;
	case RIGHT:
		altered_character_position[1]++;
		break;
	}

	//Trying to exit map
	if (altered_character_position[0] < 0 || altered_character_position[0]>map_size - 1
		|| altered_character_position[1]<0 || altered_character_position[1]>map_size - 1)
	{
		cout << "You are trying to exit the map! Please pick another direction to move in!" << endl;
		return false;
	}
	else 
	{ //Check if there's an enemy on the tile we're moving to
		for (size_t i = 0; i < enemy_positions.size(); i++)
		{
			vector<size_t> &enemy_position = enemy_positions[i];

			//Make sure the player wants to move here
			if (altered_character_position[0] == enemy_position[0] && altered_character_position[1] == enemy_position[1])
			{
				string proceed_answer;
				Enemy* &enemy = enemies[i];

				cout << "Take caution, if you move here you will engage "
					<< enemy->getName() << " the " << enemy->getType() << endl;

				do
				{
					cout << "Are you sure that you want to proceed? (Y/N): ";
					getline(cin, proceed_answer);
					proceed_answer = getLowerCase(proceed_answer);
				} while (!(!proceed_answer.compare("y") || !proceed_answer.compare("n")));

				if (!proceed_answer.compare("n"))
					return false;
			}
		}

		//Finalize the move
		character_position[0] = altered_character_position[0];
		character_position[1] = altered_character_position[1];

		return true;
	}
}

//Find the enemy and return it
Enemy* Map::getEnemyAtPosition(size_t i, size_t j)
{
	for (size_t m = 0; m < enemy_positions.size(); m++)
	{
		vector<size_t> position = enemy_positions[m];

		if (position[0] == i && position[1] == j)
		{
			Enemy* &enemy = enemies[m];

			if (!enemy->isDead())
				return enemy;
			else
				return 0;
		}
	}

	return 0;
}

//Return character position
vector<size_t> Map::getCharacterPosition() const
{
	vector<size_t> position;
	position.push_back(character_position[0]);
	position.push_back(character_position[1]);

	return position;
}

//Called after every move, to make sure we don't skip a battle
bool Map::enemyAndCharacterAreOnSameTile()
{
	for (size_t i = 0; i < enemy_positions.size(); i++)
	{
		vector<size_t> &enemy_position = enemy_positions[i];

		if (character_position[0] == enemy_position[0] && character_position[1] == enemy_position[1])
		{
			Enemy* &enemy = enemies[i];

			if (!enemy->isDead())
				return true;
		}
	}

	return false;
}

//To know if the player has won
bool Map::allEnemiesAreDead() const
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i]->isDead())
			return false;
	}

	return true;
}

//Return a MOVE_DIRECTION enum object, based on player input
MOVE_DIRECTION Map::getMoveDirection()
{
	string direction;

	do {
		cout << "Pick a direction to move in (L/l-left, R/r-right, U/u-up, D/d-down): ";
		getline(cin, direction);
		direction = getLowerCase(direction);
	} while (!(!direction.compare("l") || !direction.compare("r") || !direction.compare("u") || !direction.compare("d")));

	MOVE_DIRECTION move_direction = UP;

	if (!direction.compare("l"))
		move_direction = LEFT;
	else  if (!direction.compare("r"))
		move_direction = RIGHT;
	else if (!direction.compare("u"))
		move_direction = UP;
	else if (!direction.compare("d"))
		move_direction = DOWN;

	return move_direction;
}

//Generate a random map
void Map::generateMap()
{
	for (size_t i = 0; i < map_size; i++)
	{
		vector<bool> line;
		for (size_t j = 0; j < map_size; j++)
		{
			//Character always starts at (0,0), so no monsters can be there.
			if (i == 0 && j == 0)
			{
				line.push_back(0);
				continue;
			}

			bool contains_enemy = !(rand() % 3); //33% chance to spawn enemy on tile

			line.push_back(contains_enemy);

			if (contains_enemy)
				spawnEnemy(i, j);
		}
		boolean_map.push_back(line);
	}
}

//Spawn a random enemy
void Map::spawnEnemy(size_t i, size_t j)
{
	unsigned short enemy_type = rand() % 4; //This game has 4 enemies, so a 25% chance to spawn each one
	string name = Enemy::getRandomEnemyName(enemy_names); //Get a random name for the monster. A name can only appear once on the current map

	Enemy* enemy;

	switch (enemy_type)
	{
	case 0:
		enemy = new Skeleton(name);
		break;
	case 1:
		enemy = new Heretic(name);
		break;
	case 2:
		enemy = new Necromancer(name);
		break;
	case 3:
		enemy = new Diablo(name);
		break;
	}

	enemies.push_back(enemy);
	enemy_positions.push_back({ i, j });
}
