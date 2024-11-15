#pragma once
#include "ARasa.h"
class CGoblin : public ARasa
{
public:
	CGoblin() { initializeAbilities("GoblinAb.txt"); }

	void modifyAttributes(Atribute& atribute) override;
	void showRasa() const override;
};

