#include "DungeonMaster.h"

DungeonMaster* DungeonMaster::instance = nullptr;

void DungeonMaster::createMyHero()
{
	cout << "                                      CONSTRUIESTE-TI PRORPIUL EROU!                                                    " << endl;

	MainCharacterBuilder myhero_builder;

	myhero_builder.buildName();
	myhero_builder.buildAtribute();
	myhero_builder.buildTrecut();
	myhero_builder.buildRasa();
	myhero_builder.buildClasa();
	myhero_builder.buildAbilities();

	player = myhero_builder.getResult();
	system("cls");
	player->show();
}

void DungeonMaster::addRoom(Room* room)
{
	rooms.push_back(room);
}

Room* DungeonMaster::getRoomByName(const string& room_name)
{
	for (Room* r : rooms)
	{
		if (r->getName() == room_name)
			return r;
	}
}

bool DungeonMaster::isEnemiesAlive() const
{
	for (auto room : rooms)
	{
		if (!room->enemyIsDead())
			return true;
	}
	return false;
}


void DungeonMaster::createMap(const string& filename)
{
	ifstream file(filename);
	string room_name;

	while (file >> room_name)
	{
		Room* new_room = new Room(room_name);
		rooms.push_back(new_room);
	}
	file.close();

	string object_type; //door, statue etc
	string name;
	string atr1;
	int diff1;
	string atr2;
	int diff2;

	for (Room* room : rooms)
	{
		string filename2 = room->getName() + ".txt";
		ifstream f(filename2);

		while (f >> object_type >> name >> atr1 >> diff1)
		{
			pair<string, int> diff_class = make_pair(atr1, diff1);

			if (object_type == "Book" || object_type == "Statue")
			{
				string atr2;
				int gains = 0;
				f >> atr2 >> gains;
				pair<string, int> new_gains = make_pair(atr2, gains);


				if (object_type == "Book")
					room->addObj(Object(BOOK, name, diff_class, new_gains));
				else
					room->addObj(Object(STATUE, name, diff_class, new_gains));
			}
			else if (object_type == "Door")
			{
				Way new_way = Way(DOOR);
				new_way.setNextRoom(getRoomByName(name));
				new_way.setDifficultyClass(diff_class);
				room->addWay(new_way);
			}
			else if (object_type == "Portal")
			{
				Way new_way = Way(PORTAL);
				new_way.setNextRoom(getRoomByName(name));
				new_way.setDifficultyClass(diff_class);
				room->addWay(new_way);
			}
			else if (object_type == "Enemy")
			{
				EnemyBuilder builder;
				EnemyDirector director;
				Character* enemy = director.buildCharacter(builder);
				enemy->setName(name);
				enemy->setDiffClass(atr1, diff1);

				room->setEnemy(enemy);
			}
		}
	}
}

void DungeonMaster::goAdventure()
{
	cout << "\n\n JOCUL A INCEPUT!\n\n";
	player->setCurrentRoom(rooms[0]);
	int interract_object = 1;
	

	while (interract_object)
	{
		cout << "Alegeti obiectul cu care interactionati" << endl<< endl;
		Room* curr = player->getCurrentRoom();
		curr->show();

		cin >> interract_object;
		curr->chooseObjectToInterract(player, interract_object);

		if (!isEnemiesAlive())
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t YOU WIN THE GAME";
			break;
		}
	}
	
}