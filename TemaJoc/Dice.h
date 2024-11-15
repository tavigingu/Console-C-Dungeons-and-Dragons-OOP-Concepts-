#pragma once
#include <random>
#include <iostream>
#include "Character.h"
using namespace std;

namespace Dice
{
	static int throwDice()
	{
		random_device rd;
		mt19937 mt(rd());

		uniform_int_distribution<int> distribution(1, 20);

		int random_number = distribution(mt);
		cout << "Zarul a aratat: " << random_number<< " ";
		return random_number;
	}

	static int getAtrValue(Character* player, const string& atribut)
	{
		if (atribut == "intellect")
		{
			return player->getAtribute().getIntelligence();
		}
		else if (atribut == "strength")
		{
			return player->getAtribute().getStrength();
		}
		else if (atribut == "dexterity")
		{
			return player->getAtribute().getDexterity();
		}
	}

	static int calculateDifficultyClass(int dice_value, const string& atribut, Character* player)
	{
		int a_value = getAtrValue(player, atribut);
		if (a_value == 1)
			return dice_value - 5;
		if (a_value == 2 || a_value == 3)
			return dice_value - 4;
		if (a_value == 4 || a_value == 5)
			return dice_value - 3;
		if (a_value == 6 || a_value == 7)
			return dice_value - 2;
		if (a_value == 8 || a_value == 9)
			return dice_value - 1;
		if (a_value == 10 || a_value == 11)
			return dice_value;
		if (a_value == 12 || a_value == 13)
			return dice_value + 1;
		if (a_value == 14 || a_value == 15)
			return dice_value + 2;
		if (a_value == 16 || a_value == 17)
			return dice_value + 3;
		if (a_value == 18 || a_value == 19)
			return dice_value + 4;
		if (a_value == 20 || a_value == 21)
			return dice_value + 5;
		if (a_value == 22 || a_value == 23)
			return dice_value + 6;
		if (a_value == 24 || a_value == 25)
			return dice_value + 7;
		if (a_value == 26 || a_value == 27)
			return dice_value + 8;
		if (a_value == 28 || a_value == 29)
			return dice_value + 9;
		if (a_value == 30)
			return dice_value + 10;

	}

};

