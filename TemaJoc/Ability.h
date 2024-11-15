#pragma once
#include <iostream>
using namespace std;

class Ability
{
private:
	string name;
	int damage;
	pair<string, int> difficulty_class;

public:
	Ability(const string& name, int& damage, const pair<string,int>& diffc )
		:name(name), damage(damage), difficulty_class(diffc) { };

	void show();
	void showName();
	int getDamage();
	pair<string, int> getDiffClass() const;
};

