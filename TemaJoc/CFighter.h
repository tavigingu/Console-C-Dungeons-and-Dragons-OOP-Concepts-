#pragma once
#include "AClasa.h"
class CFighter : public AClasa
{
public:

	CFighter() { initializeAbilities("FighterAb.txt"); }

	void modifyAttributes(Atribute& atribute) override;
	void showClasa() const override;
};

