#include "AClasa.h"


void AClasa::initializeAbilities(const string& filename)
{
	ifstream file(filename);
	
	string ab;
	int damage;
	string atrib;
	int minim;

	while (file >> ab >> damage >> atrib >> minim)
	{
		pair<string, int> diffc = make_pair(atrib, minim);

		Ability new_ability(ab, damage, diffc);


		abilities.push_back(new_ability);
	}
}


Ability AClasa::getAbility(int number) const
{
	if (number > abilities.size())
		throw MyException("Numarul de abilitati este mai mic decat cel ales!");
	else
		return abilities[number];

}

void AClasa::showAbilities() const
{
	int i = 0;
	for (auto ab : abilities)
	{
		cout <<"["<< ++i <<"]" << " ";
		ab.show();
	}
}
