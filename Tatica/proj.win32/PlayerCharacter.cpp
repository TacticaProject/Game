#include "PlayerCharacter.h"
#include <time.h>

// Position = ĳ���Ͱ� ������ ��ġ
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

//��ų ����ϸ� ��ų ����Ʈ�� �ö� �ش� �Ͽ� ����ȴ�.
//������� ���� ������ 0, �̹��Ͽ� ����Ǵ� ���� 1, �������� 2�̴�.
//��ų ����Ʈ�� 0���� ũ�� ���� �ڽ��� ���� ���ƿ� �� 1�� �پ���.
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

//���к��� ��ų�� �����ϱ� ���� �������̵��Ͽ���.
//���к��� ��ų�� �������� ���� �޴� �������� ������ ���δ�.
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

//�ü� ��ų�� �����ϱ� ���� �������̵� �Ͽ���.
//�ü��� ��ų�� ����Ǵ� �Ͽ� 3�ۼ�Ʈ�� Ȯ���� ���,
//97�ۼ�Ʈ�� Ȯ���� 1.5���� �������� �ش�.
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