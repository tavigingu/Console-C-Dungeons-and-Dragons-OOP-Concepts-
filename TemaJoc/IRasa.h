#pragma once
#include <iostream>
using namespace std;
#include "Atribute.h"
#include "Ability.h"

__interface IRasa
{
	virtual void initializeAbilities(const string& filename) = 0;
	virtual void modifyAttributes(Atribute& atribute) = 0;
	virtual Ability getAbility(int number) const = 0;
	virtual void showAbilities() const = 0;
	virtual void showRasa() const= 0;
};

