#pragma once
#include "AClasa.h"
class CArcher : public AClasa
{
public:

	CArcher() { initializeAbilities("ArcherAb.txt"); }

	void modifyAttributes(Atribute& atribute) override;
	void showClasa() const override;
};

