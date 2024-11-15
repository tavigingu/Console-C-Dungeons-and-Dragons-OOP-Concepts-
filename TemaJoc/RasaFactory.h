#pragma once
#include "CHuman.h"
#include "CElf.h"
#include "CGoblin.h"


class RasaFactory
{
public:
	enum r_type{ HUMAN, ELF, GOBLIN};

	static IRasa* chooseRasa(int nr )
	{
		switch (nr)
		{
		case 1:
			return new CHuman();
		case 2:
			return new CElf();
		case 3:
			return new CGoblin();

		default:
			cout << "Rasa invalida!" << endl;
			return nullptr;
		
		}
	}

};

