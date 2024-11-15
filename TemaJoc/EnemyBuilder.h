#pragma once
#include "CharacterBuilder.h"
#include "Atribute.h"
#include "RasaFactory.h"
#include "ClasaFactory.h"

class EnemyBuilder : public CharacterBuilder
{
private:
	Character character;

public:

	void buildAtribute() override;
	void buildName() override;
	void buildRasa() override;
	void buildClasa() override;
	void buildTrecut() override;
	void buildAbilities() override;

	inline Character* getResult() { return new Character(character); }
};

class EnemyDirector : public EnemyBuilder
{
public:
	Character* buildCharacter(EnemyBuilder builder)
	{
		builder.buildName();
		builder.buildAtribute();
		builder.buildTrecut();
		builder.buildRasa();
		builder.buildClasa();
		builder.buildAbilities();

		return builder.getResult();
	}

};
