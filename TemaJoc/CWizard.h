#pragma once
#include "AClasa.h"
class CWizard : public AClasa
{
public:

	CWizard() { initializeAbilities("WizardAb.txt"); }

	void modifyAttributes(Atribute& atribute) override;
	void showClasa() const override;
};

