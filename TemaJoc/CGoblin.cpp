#include "CGoblin.h"

void CGoblin::modifyAttributes(Atribute& atribute)
{
	atribute.increaseDexterity(3);
	atribute.decreaseStrength(2);

}

void CGoblin::showRasa() const
{
	cout << "Goblin" << endl;
}
