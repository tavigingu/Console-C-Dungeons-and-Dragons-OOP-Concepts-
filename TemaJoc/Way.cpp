#include "Way.h"
#include "Room.h"



void Way::setNextRoom(Room* r)
{
	next_room = r;
}

void Way::setDifficultyClass(pair<string, int> diffc)
{
	this->diff_class = diffc;
}

void Way::show()
{
	if (type == DOOR)
		cout << "Open -> Door to ";
	if (type == PORTAL)
		cout << "Open -> Portal to ";
	cout << next_room->getName() << " ( Difficulty class: ";
	cout << diff_class.first << " " << diff_class.second<<")" << endl;
}
