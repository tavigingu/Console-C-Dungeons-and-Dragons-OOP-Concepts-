#include "Atribute.h"


//Atribute::Atribute(int h, int w, int a)
//{
//	height = h;
//	weight = w;
//	age = a;
//	int decrease_value = 0;
//
//	if (h < 170)
//	{
//		decrease_value=generateRandom
//	}
//	else if (h < 200 && h>170)
//	{
//		dexterity = generateRandom(10, 20);
//		strength = generateRandom(10, 20);
//	}
//	else if (h > 200)
//	{
//		dexterity = generateRandom(1, 10);
//		strength = generateRandom(20, 30);
//	}
//
//	
//
//
//}

int generateRandom(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> distribution(min, max);
	int random_number = distribution(gen);

	return random_number;
}

void Atribute::show() const
{
	cout << "     Intellect: " << intelligence << endl;
	cout << "     Strength: " << strength << endl;
	cout<<  "     Dexterity: " << dexterity << endl;
}

void Atribute::increaseAnAtribute(const string& atr, int value)
{
	if (atr == "intellect")
		increaseIntellgicence(value);
	else if (atr == "strength")
		increaseStrength(value);
	else if (atr == "dexterity")
		increaseDexterity(value);
}
