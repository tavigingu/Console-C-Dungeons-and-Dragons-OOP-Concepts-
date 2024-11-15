#include "Character.h"
#include "Dice.h"

void Character::backgroundInfluences()
{
	if (trecut == SOLDAT)
		atribute.increaseDexterity(2);
	if (trecut == CRIMINAL)
		atribute.increaseIntellgicence(2);
	if (trecut == HOT)
		atribute.increaseStrength(2);
}

void Character::setDiffClass(string atr, int diffc)
{
	pair<string, int> diff_class = make_pair(atr, diffc);
	difficulty_class = diff_class;
}


void Character::showAtribute() const
{
	atribute.show();
}

void Character::showAbilities() const
{
	for (auto ab : abilitati)
	{
		ab.show();
	}

}

void Character::addAbility(const Ability& a)
{
	abilitati.push_back(a);
}

void Character::takeDamage(int hp)
{
	this->hp -= hp;
}

void Character::attack(Character* enemy, int ability)
{
	enemy->takeDamage(abilitati[ability].getDamage());
}



void Character::show() const
{
	cout << "   ~~~~~~~~~~Character info~~~~~~~~~~~~~~~" << endl << endl;

	cout << "          ~<@|   " << name << "   |@>~" << endl << endl;
	atribute.show();
	cout << endl;
	cout << "     Rasa: ";
	rasa->showRasa();
	cout << "     Clasa: ";
	clasa->showClasa();
	cout << "     Trecut: ";
	if (trecut == SOLDAT)
		cout << "Soldat" << endl;
	else if (trecut == CRIMINAL)
		cout << "Criminal" << endl;
	else if (trecut == HOT)
		cout << "Hot" << endl;
	cout << endl;
	for (auto ab : abilitati)
	{
		ab.show();
	}

	cout << endl<< "          ~<@|    " << hp << "hp    |@>~" << endl;
	cout << endl << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}

void Character::showName() const
{
	cout << name << " ";
	if (difficulty_class.second)
		cout <<"( Difficulty class: "<< difficulty_class.first << " " << difficulty_class.second <<" ) "<< endl;

}




