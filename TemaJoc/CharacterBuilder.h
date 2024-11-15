#pragma once
#include "Character.h"

class CharacterBuilder
{
public:
	virtual void buildAtribute() = 0;
	virtual void buildName() = 0;
	virtual void buildRasa() = 0;
	virtual void buildClasa() = 0;
	virtual void buildTrecut() = 0;
	virtual void buildAbilities() = 0;
};

