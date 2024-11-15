#pragma once
#include <iostream>
#include <random>
#include "MyException.h"
using namespace std;



class Atribute
{
protected:
	int intelligence;
	int strength;
	int dexterity;

	int max_points; //numarul maxim de puncte ce poate fi impartit atributelor

public:
	Atribute() { max_points = 60; }
	Atribute(int intell, int str, int dext)
		:max_points(50), intelligence(intell), strength(str), dexterity(dext)
	{
		if (intell + str + dext > max_points)
			throw MyException("Numarul maxim de puncte pentru atribute este 50!");

	};



	inline void increaseIntellgicence(int value) { intelligence += value; }
	inline void increaseStrength(int value) { strength += value; }
	inline void increaseDexterity(int value) { dexterity += value; }
	inline void decreaseIntellgicence(int value) { intelligence -= value; }
	inline void decreaseStrength(int value) { strength -= value; }
	inline void decreaseDexterity(int value) { dexterity -= value; }

	inline int getMaxPoints() const { return max_points; }
	inline int getIntelligence() const { return intelligence; }
	inline int getStrength() const { return strength; }
	inline int getDexterity() const { return dexterity; }
	inline void setIntellect(int value) { intelligence = value; }
	inline void setStrenth(int value) { strength = value; }
	inline void setDexterity(int value) { dexterity = value; }

	void show() const;
	void increaseAnAtribute(const string& atr, int value);
};



