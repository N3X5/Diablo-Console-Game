#ifndef BATTLE_H
#define BATTLE_H

class Character;
class Enemy;

class Battle 
{
public:
	Battle(Character* &, Enemy* &);
	~Battle();

	Character* &getCharacter() const;
	Enemy* &getEnemy() const;
	unsigned short getTurn() const;

	bool isWon() const;
	bool isLost() const;

	void nextTurn();

private:
	Character* &character;
	Enemy* &enemy;
	unsigned short turn;
};

#endif 

