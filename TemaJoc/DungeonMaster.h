#pragma once
#include "Character.h"
#include <vector>
#include "MyException.h"
#include "CHuman.h"
#include "Atribute.h"
#include "Ability.h"
#include <cstdlib>
#include "MainCharacterBuilder.h"
#include "EnemyBuilder.h"
#include "Room.h"


class DungeonMaster
{
private:
	static DungeonMaster* instance;
	
	vector<Room*> rooms;
	Character* player;

	DungeonMaster() {  };
	~DungeonMaster() {};
	
public:
	static DungeonMaster* getInstance()
	{
		if (!instance)
			instance = new DungeonMaster();
			
		return instance;
	}

	DungeonMaster(const DungeonMaster&) = delete;
	DungeonMaster operator=(const DungeonMaster&) = delete;
	
	void createMyHero();
	void createMap(const string& filename);
	void goAdventure();
	
	void addRoom(Room* room);
	Room* getRoomByName(const string& room_name);
	bool isEnemiesAlive() const;
};

