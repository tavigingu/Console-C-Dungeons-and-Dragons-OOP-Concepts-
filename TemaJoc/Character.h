#pragma once
#include "Atribute.h"
#include "ARasa.h"
#include "Ability.h"
#include "IClasa.h"
//#include "Dice.h"

class Room;

typedef enum background
{
	SOLDAT, CRIMINAL, HOT
};

class Character
{
private:
	string name;
	IRasa* rasa;
	IClasa* clasa;
	background trecut;
	vector<Ability> abilitati;
	Atribute atribute;
	int hp;
	Room* current_room;
	pair<string, int> difficulty_class;

public:
	Character() { hp = 100; };
	

	inline void setName(const string& name) { this->name = name; }
	inline void setRasa(IRasa* r) { rasa = r; r->modifyAttributes(atribute); }
	inline void setClasa(IClasa* c) { clasa = c; c->modifyAttributes(atribute); }
	inline void setBackground(background b) { trecut = b; backgroundInfluences(); }
	inline void setAtribute(Atribute a) { atribute = a; }
	inline void setCurrentRoom(Room* r) { current_room = r; }
	inline void setHP(int hp) { this->hp = hp; }
	void setDiffClass(string atr, int diffc);

	inline IRasa* getRasa() const { return rasa; }
	inline IClasa* getClasa() const { return clasa; }
	inline Atribute& getAtribute() { return atribute; }
	inline Room* getCurrentRoom() const { return current_room; }
	inline int getHP() const { return hp; }
	inline Ability getAbility(int nr_ab) const { return abilitati[nr_ab]; }
	inline pair<string, int> getDifficultyClass() const { return difficulty_class; }
	inline string getName() const { return name; }

	void showAtribute() const;
	void showAbilities() const;
	void show() const;
	void showName() const;
	
	void backgroundInfluences();
	void addAbility(const Ability& a);
	void takeDamage(int hp);
	void attack(Character* enemy, int ability);
	

	
};

