#pragma once
#include <iostream>
using namespace std;

typedef enum way_type { DOOR, PORTAL};
class Room;

class Way
{
private:
	way_type type;
	Room* next_room;
	pair<string, int> diff_class;
	bool visited;

public:
	Way(way_type type)
		:type(type) { visited = 0;}

	void setNextRoom(Room* r);
	void setDifficultyClass(pair<string, int> diffc);
	
	inline Room* getNextRoom() const { return next_room; }
	inline pair<string, int> getDiffClass() { return diff_class; }
	void show();

};

