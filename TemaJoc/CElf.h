#pragma once
#include "ARasa.h"
class CElf : public ARasa
{
public:
	CElf() { initializeAbilities("ElfAb.txt"); }

	void modifyAttributes(Atribute& atribute) override;
	void showRasa() const override;

};

