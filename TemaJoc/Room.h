#pragma once
#include "Object.h"
#include "Way.h"
#include <vector>
#include "Dice.h"
#include "Character.h"


class Room
{
private:
	string name;
	vector<Object> objects;
	vector<Way> ways;
	Character* enemy;

public:
	Room(const string& name)
		:name(name) { }

	string getName() const;
	void addObj(Object obj);
	void addWay(Way way);
	void setEnemy(Character* enemy);

	void show() const;
	void chooseObjectToInterract(Character* player, int nr);
	void interractToObject(Character* player, Object* obj);
	void interractToWay(Character* player, Way way);
	void fight(Character* player);
	bool enemyIsDead() const;

};

