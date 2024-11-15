#pragma once
#include "IClasa.h"
#include <vector>
#include "Ability.h"
#include <fstream>
#include "MyException.h"
using namespace std;

class AClasa : public IClasa
{
protected:
	vector<Ability> abilities;

public:

	void initializeAbilities(const string& filename) override;
	Ability getAbility(int number) const override;
	void showAbilities() const override;

	virtual void modifyAttributes(Atribute& atribute) = 0;

};

