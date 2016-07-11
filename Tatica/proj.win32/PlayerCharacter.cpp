#include "PlayerCharacter.h"
#include <time.h>

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
		srand((unsigned)time(NULL));
	}
}

//스킬 사용하면 스킬 포인트가 올라가 해당 턴에 적용된다.
//사용하지 않을 때에는 0, 이번턴에 적용되는 것은 1, 다음턴은 2이다.
//스킬 포인트가 0보다 크면 다음 자신의 턴이 돌아올 때 1이 줄어든다.
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

//방패병의 스킬을 적용하기 위해 오버라이딩하였다.
//방패병은 스킬이 적용중인 때에 받는 데미지를 반으로 줄인다.
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

//궁수 스킬을 적용하기 위해 오버라이딩 하였다.
//궁수는 스킬이 적용되는 턴에 3퍼센트의 확률로 즉사,
//97퍼센트의 확률로 1.5배의 데미지를 준다.
int PlayerCharacter::Attack()
{
	if(getClass() == 1 && SkillPoint == 1)
	{
		if(rand() % 100 < 97)
		{
			return (int)(getAttackPoint() * 1.5);
		}
		else
		{
			return 100;
		}
	}
	else
	{
		return getAttackPoint();
	}
}