#pragma once
#include <iostream>
using namespace std;
#include "Atribute.h"
#include "Ability.h"

__interface IClasa
{
	virtual void initializeAbilities(const string& filename) = 0;
	virtual void modifyAttributes(Atribute& atribute) = 0;
	virtual Ability getAbility(int number) const = 0;
	virtual void showAbilities() const = 0;
	virtual void showClasa() const = 0;
};

