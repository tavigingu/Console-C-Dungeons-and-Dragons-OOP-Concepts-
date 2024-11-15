#include "CElf.h"

void CElf::modifyAttributes(Atribute& atribute)
{
	atribute.increaseDexterity(4);
	atribute.decreaseStrength(3);
}

void CElf::showRasa() const
{
	cout << "Elf" << endl;
}
