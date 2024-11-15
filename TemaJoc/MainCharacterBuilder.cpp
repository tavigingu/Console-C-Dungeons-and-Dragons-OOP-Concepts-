#include "MainCharacterBuilder.h"

void MainCharacterBuilder::buildAtribute()
{

	Atribute new_atr;
	int points_left = new_atr.getMaxPoints();
	int int_points = 0;
	int str_points = 0;
	int dex_points = 0;

	cout << "SELECTEAZA INTELIGENTA, PUTEREA SI DEXTERITATEA EROULUI TAU>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>" << endl;
	cout << "Attribute points: " << points_left << endl;

	cout << "Intellect: ";
	cin >> int_points;
	points_left -= int_points;
	new_atr.setIntellect(int_points);
	cout << "Attribute points left: " << points_left << endl;

	cout << "Strength: ";
	cin >> str_points;
	points_left -= str_points;
	new_atr.setStrenth(str_points);
	cout << "Attribute points left: " << points_left << endl;

	cout << "Dexterity: ";
	cin >> dex_points;
	points_left -= dex_points;
	new_atr.setDexterity(dex_points);
	//cout << "Attribute points left: " << points_left << endl;
	cout << endl;

	if (points_left < 0)
		throw MyException("Numarul maxim de puncte este 50!");

	character.setAtribute(new_atr);
	
}

void MainCharacterBuilder::buildName()
{
	cout << "SETEAZA NUMELE EROULUI>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>" << endl;
	string name;
	cin >> name;

	character.setName(name);
	cout << endl;
}

void MainCharacterBuilder::buildRasa()
{
	cout << "SELECTEAZA CIFRA CORESPUNZATOARE RASEI DORITE>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>" << endl;
	cout << "[1] HUMAN   |   [2] ELF   |   [3] GOBLIN" << endl;

	int number = 0;
	cin >> number;

	character.setRasa(RasaFactory::chooseRasa(number));
}

void MainCharacterBuilder::buildClasa()
{
	cout << "SELECTEAZA CIFRA CORESPUNZATOARE CLASEI DORITE>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>" << endl;
	cout << "[1] FIGHTER   |   [2] ARCHER   |   [3] WIZARD" << endl;

	int number = 0;
	cin >> number;

	character.setClasa(ClasaFactory::chooseClasa(number));
}

void MainCharacterBuilder::buildTrecut()
{
	cout << "SELECTEAZA CIFRA CORESPUNZATOARE TRECUTULUI EROULUI TAU>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>" << endl;
	cout << "[1] SOLDAT   |   [2] CRIMINAL   |   [3] HOT" << endl;

	int number;
	cin >> number;

	background bg = SOLDAT;
	if (number == 1)
		bg = SOLDAT;
	if (number == 2)
		bg = CRIMINAL;
	if (number == 3)
		bg = HOT;

	character.setBackground(bg);
}

void MainCharacterBuilder::buildAbilities()
{
	int ab1 = 0;
	int ab2 = 0;

	cout << "TASTEAZA NUMERELE CORESPUNZATOARE A DOUA ABILITATI PE CARE LE DORESTI" << endl;
	character.getRasa()->showAbilities();
	
	cin >> ab1 >> ab2;
	if (ab1 == ab2)
		throw MyException("Abilitatile selectate trebuie sa fie diferite!");

	character.addAbility(character.getRasa()->getAbility(ab1 - 1));
	character.addAbility(character.getRasa()->getAbility(ab2 - 1));


	cout << "TASTEAZA NUMERELE CORESPUNZATOARE A DOUA ABILITATI PE CARE LE DORESTI" << endl;
	character.getClasa()->showAbilities();
	
	cin >> ab1 >> ab2;
	if (ab1 == ab2)
		throw MyException("Abilitatile selectate trebuie sa fie diferite!");

	character.addAbility(character.getClasa()->getAbility(ab1 - 1));
	character.addAbility(character.getClasa()->getAbility(ab2 - 1));


	/*cout << "ACESTEA VOR FI ABILITATILE TALE IN NOUA AVENTURA" << endl;
	character.showAbilities();*/
}
