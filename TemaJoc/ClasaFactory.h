#pragma once
#include "CFighter.h"
#include "CArcher.h"
#include "CWizard.h"


class ClasaFactory
{
public:

	enum c_type { FIGHTER, ARCHER, WIZARD};

	static IClasa* chooseClasa(int nr)
	{
		switch(nr)
		{
		case 1:
			return new CFighter();
		case 2:
			return new CArcher();
		case 3:
			return new CWizard();

		default:
			cout << "Clasa incorecta!" << endl;
			return nullptr;

		}
	}

};

