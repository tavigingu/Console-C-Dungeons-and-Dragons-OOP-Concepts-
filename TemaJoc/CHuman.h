#pragma once
#include "ARasa.h"
#include "Atribute.h"

class CHuman : public ARasa
{
public:
	CHuman() { initializeAbilities("HumanAb.txt"); }
	
	void modifyAttributes(Atribute& atribute) override;
	void showRasa() const override;
};

