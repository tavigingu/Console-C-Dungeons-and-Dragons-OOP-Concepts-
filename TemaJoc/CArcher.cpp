#include "CArcher.h"

void CArcher::modifyAttributes(Atribute& atribute)
{
	atribute.increaseDexterity(5);
	atribute.decreaseStrength(3);
	atribute.decreaseIntellgicence(1);

}

void CArcher::showClasa() const
{
	cout << "Archer" << endl;
}
