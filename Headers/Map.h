#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "Enemy.h"
#include "Skeleton.h"
#include "Heretic.h"
#include "Necromancer.h"
#include "Diablo.h"
#include "Character.h"

enum MOVE_DIRECTION 
{
	UP, DOWN, LEFT, RIGHT
};

class Map 
{
public:
	Map(size_t, Character* &);
	~Map();
	void printMap();
	bool moveCharacter(MOVE_DIRECTION);
	Enemy* getEnemyAtPosition(size_t, size_t);
	std::vector<size_t> getCharacterPosition() const;
	bool enemyAndCharacterAreOnSameTile();
	bool allEnemiesAreDead() const;

	static MOVE_DIRECTION getMoveDirection();
private:
	Character* &character;

	size_t map_size; //AxA size where A can range from 5-8
	std::vector<std::vector<bool>> boolean_map; //1-there is an enemy on the tile, 0-the tile is mepty
	std::vector<std::string> enemy_names; //Available names for the current map
	std::vector<Enemy*> enemies; //Enemies on the map
	std::vector<std::vector<size_t>> enemy_positions; //Enemies positions on the current map
	size_t character_position[2] = { 0,0 };

	void generateMap();
	void spawnEnemy(size_t, size_t);
};

#endif

