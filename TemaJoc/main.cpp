#include "DungeonMaster.h"

int main()
{

	try
	{
		cout << "<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<DUNGEONS AND DRAGONS>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>" << endl << endl;
		
		DungeonMaster::getInstance()->createMyHero();
		DungeonMaster::getInstance()->createMap("Rooms.txt");
		DungeonMaster::getInstance()->goAdventure();	


	}
	catch (MyException& exc)
	{
		cout << exc;
	}


	return 0;
}