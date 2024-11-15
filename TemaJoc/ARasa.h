#pragma once
#include "IRasa.h"
#include <vector>
#include "Ability.h"
#include <fstream>
#include "Atribute.h"
#include "MyException.h"


class ARasa : public IRasa
{
protected:
	vector<Ability> abilities;

public:

	void initializeAbilities(const string& filename) override;
	Ability getAbility(int number) const override;
	void showAbilities() const override;

	virtual void modifyAttributes(Atribute& atribute) = 0;
};

