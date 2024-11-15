#include "EnemyBuilder.h"

int generateRandomNumber(int min, int max)
{
    random_device rd; 
    mt19937 mt(rd());  

    uniform_int_distribution<int> distribution(min, max);

    int random_number = distribution(mt);
    return random_number;
}

void EnemyBuilder::buildAtribute()
{
	Atribute new_atr;
	int left_points = new_atr.getMaxPoints();

    int intell = generateRandomNumber(left_points/5, left_points / 2); //modificari a.i. atributele sa aiba valori decente fara diferente mari
    new_atr.setIntellect(intell);
    left_points -= intell;

    int strength = generateRandomNumber(0, left_points - 5);
    new_atr.setStrenth(strength);

    int dext = left_points - strength;
    new_atr.setDexterity(dext);

    character.setAtribute(new_atr);

}

void EnemyBuilder::buildName()
{
    character.setName("enemy");

}

void EnemyBuilder::buildRasa()
{
    int number = generateRandomNumber(1, 3);

    character.setRasa(RasaFactory::chooseRasa(number));
}

void EnemyBuilder::buildClasa()
{
    int number = generateRandomNumber(1, 3);

    character.setClasa(ClasaFactory::chooseClasa(number));

}

void EnemyBuilder::buildTrecut()
{
    int number = generateRandomNumber(1, 3);

    background bg = SOLDAT;
    if (number == 1)
        bg = SOLDAT;
    if (number == 2)
        bg = CRIMINAL;
    if (number == 3)
        bg = HOT;

    character.setBackground(bg);
}

void EnemyBuilder::buildAbilities()
{
    int ab1 = generateRandomNumber(1, 3);
    int ab2 = generateRandomNumber(1, 3);
    while (ab2 == ab1)
        ab2 = generateRandomNumber(1, 3);

    int ab3 = generateRandomNumber(1, 3);
    int ab4 = generateRandomNumber(1, 3);
    while (ab3 == ab4)
        ab3 = generateRandomNumber(1, 3);

    character.addAbility(character.getRasa()->getAbility(ab1-1));
    character.addAbility(character.getRasa()->getAbility(ab2-1));
    character.addAbility(character.getClasa()->getAbility(ab3-1));
    character.addAbility(character.getClasa()->getAbility(ab4-1));

}
