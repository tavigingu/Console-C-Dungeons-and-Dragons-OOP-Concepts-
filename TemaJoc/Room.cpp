#include "Room.h"

string Room::getName() const
{
    return name;
}

void Room::addObj(Object obj)
{
    objects.push_back(obj);
}

void Room::addWay(Way way)
{
    ways.push_back(way);
}

void Room::setEnemy(Character* enemy)
{
    this->enemy = enemy;
}

void Room::show() const
{
    cout << "Room: " << name << endl;
    int i = 0;
    for (auto obj : objects)
    {
        cout << "[" << ++i << "] ";
        obj.show();
    }
    for (auto way : ways)
    {
        cout << "[" << ++i << "] ";
        way.show();
    }
    if (enemy != nullptr)
    {
        cout << "[" << ++i << "] ";
        cout << "Fight -> Enemy ";
        enemy->showName();
    }

}

void Room::chooseObjectToInterract(Character* player, int nr)
{
    if (nr > objects.size() + ways.size() + 1)
        throw MyException("Optiunea aleasa nu exista");

    if (nr <= objects.size())
    {
   
        int diffc_obtained=Dice::calculateDifficultyClass(Dice::throwDice(), objects[nr - 1].getDiiffc().first, player);
        cout << " => Difficulty class obtained: " << diffc_obtained << endl;

        if (objects[nr - 1].getVisited() == 1)
            cout << "Interactiunea a fost deja efectuata! Alegeti alt obiect." << endl;
        else if (diffc_obtained >= objects[nr - 1].getDiiffc().second)
            interractToObject(player, &objects[nr - 1]);
        else
            cout << "Interactiunea nu a reusit! (" <<diffc_obtained<<" < "<< objects[nr - 1].getDiiffc().second <<")" << endl;
    
    }
    else if (nr > objects.size() && nr<= objects.size()+ways.size())
    {
       
        int diffc_obtained = Dice::calculateDifficultyClass(Dice::throwDice(), ways[nr-objects.size() - 1].getDiffClass().first, player);
        cout << " => Difficulty class obtained: " << diffc_obtained << endl;

        if (diffc_obtained >= ways[nr - objects.size() - 1].getDiffClass().second)
            interractToWay(player, ways[nr - objects.size() - 1]);
        else
            cout << "Interactiunea nu a reusit! (" << diffc_obtained << " < " << ways[nr - objects.size() - 1].getDiffClass().second<<")" << endl;
    
    }
    else
    {
        int diffc_obtained = Dice::calculateDifficultyClass(Dice::throwDice(), enemy->getDifficultyClass().first, player);

        if (diffc_obtained >= enemy->getDifficultyClass().second)
            fight(player);
        else
            cout << "Interactiunea nu a reusit! (" << diffc_obtained << " < " << enemy->getDifficultyClass().second<<")" << endl;
    }

}

void Room::interractToObject(Character* player, Object* obj)
{
    player->getAtribute().increaseAnAtribute(obj->getGains().first, obj->getGains().second);
    cout << "+" << obj->getGains().second <<obj->getGains().first<< endl;
    obj->setVisited();
}

void Room::interractToWay(Character* player, Way way)
{
    player->setCurrentRoom(way.getNextRoom());
}

int RandomNumber(int min, int max)
{
    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> distribution(min, max);

    int random_number = distribution(mt);
    return random_number;
}

void Room::fight(Character* player)
{
    if (enemy->getHP() < 0)
    {
        cout << "Inamicul a fost deja infrant!" << endl;
    }
    else
    {
        while (1)
        {
            cout << "Alege abilitatea cu care ataci! [1-4]" << endl;

            int nr_ab = 0;
            cin >> nr_ab;
            if (nr_ab > 4)
                throw MyException("Dispuneti de numai 4 abilitati!");


            int diffc_obbtained= Dice::calculateDifficultyClass(Dice::throwDice(), player->getAbility(nr_ab - 1).getDiffClass().first, player);
            if (diffc_obbtained < player->getAbility(nr_ab - 1).getDiffClass().second) {
                cout << ". You miss the enemy. Diff Class required: " << player->getAbility(nr_ab - 1).getDiffClass().second << " ";
                cout << "Diff Class obtained: " << diffc_obbtained << endl;
            }
            else 
            {
                player->attack(enemy, nr_ab - 1);
                cout << "Ai atacat cu ";
                player->getAbility(nr_ab - 1).showName();
                cout << "(" << player->getAbility(nr_ab - 1).getDamage() << ") ";
                cout << "Enemy HP: " << enemy->getHP() << endl;
                
                if (enemy->getHP() <= 0)
                    break;
              
            }

            int nr_ab_enemy = RandomNumber(1, 4);

            diffc_obbtained = Dice::calculateDifficultyClass(Dice::throwDice(), enemy->getAbility(nr_ab_enemy - 1).getDiffClass().first, player);
            if (diffc_obbtained < enemy->getAbility(nr_ab_enemy - 1).getDiffClass().second)
                cout << "Enemy miss the shot" << endl;
            else
            {
                enemy->attack(player, nr_ab_enemy - 1);
                cout << "Ai fost atacat cu ";
                enemy->getAbility(nr_ab_enemy - 1).showName();
                cout << "(" << enemy->getAbility(nr_ab_enemy - 1).getDamage() << ") ";
                cout << "Your HP: " << player->getHP() << endl;
               
                
            }

            if (player->getHP() <= 0)
                throw MyException("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGAME OVER");
         
        }
    }

    cout << "YOU WIN!" << endl;
    enemy->setName(enemy->getName() + "(~DEAD~)");
    player->setHP(100);

}

bool Room::enemyIsDead() const
{
    if (enemy)
        return enemy->getHP() <= 0;
    else
        return true;
}

