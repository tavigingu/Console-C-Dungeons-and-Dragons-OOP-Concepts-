#include "CWizard.h"

void CWizard::modifyAttributes(Atribute& atribute)
{
	atribute.decreaseStrength(6);
	atribute.increaseIntellgicence(4);
	atribute.increaseDexterity(3);

}

void CWizard::showClasa() const
{
	cout << "Wizard" << endl;
}
