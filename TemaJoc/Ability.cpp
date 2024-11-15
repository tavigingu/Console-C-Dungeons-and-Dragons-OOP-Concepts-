#include "Ability.h"

void Ability::show()
{
	cout <<"     " << name << " Damage: " << damage << "( Difficulty class: " << difficulty_class.first << " " << difficulty_class.second<<" )" << endl;
}

void Ability::showName()
{
	cout << name;
}

int Ability::getDamage()
{
	return damage;
}

pair<string, int> Ability::getDiffClass() const
{
	return difficulty_class;
}
