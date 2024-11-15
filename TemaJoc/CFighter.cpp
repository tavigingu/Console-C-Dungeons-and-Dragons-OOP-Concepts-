#include "CFighter.h"

void CFighter::modifyAttributes(Atribute& atribute)
{
	atribute.increaseStrength(6);
	atribute.decreaseIntellgicence(3);
	atribute.decreaseDexterity(2);

}

void CFighter::showClasa() const
{
	cout << "Fighter" << endl;
}
