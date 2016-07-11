#include "PlayerCharacter.h"

// Position = 캐릭터가 존재할 위치
PlayerCharacter::PlayerCharacter(CLASS Class, Point Position)
{
	if (Class < 3)
	{
		setStat(Class);
		setLocation(Position);
		auto character = Sprite::create(spriteName[Class]);
		character->setAnchorPoint(Point(0.5, 0.5));
		character->setPosition(Position);
		SkillPoint = 0;
	}
}

bool PlayerCharacter::usingSkill()
{
	switch (getClass())
	{
	case 0:
		SkillPoint = 1;
		break;
	case 1:
		SkillPoint = 2;
		break;
	case 2:
		SkillPoint = 2;
		break;
	default:
		break;
	}
	return true;
}

bool PlayerCharacter::getDamage(int Damage)
{
	if(Damage - getDefensePoint() > 0)
	{
		if(getClass() == 2 && SkillPoint > 0)
		{
			setHealthPoint(getHealthPoint() + (- Damage + getDefensePoint()) / 2);
		}
		else
		{
			setHealthPoint(getHealthPoint() - Damage + getDefensePoint());
		}
	}
	return true;
}