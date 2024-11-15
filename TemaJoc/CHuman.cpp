#include "CHuman.h"

void CHuman::modifyAttributes(Atribute& atribute)
{
		atribute.increaseIntellgicence(5);
		atribute.decreaseStrength(4);
}

void CHuman::showRasa() const
{
	cout << "Human" << endl;
}
