#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

enum CLASS {
	SwordMan = 1,
	Archer,
	Shilder,
	Snake,
	Skeleton,
	Centauros,
	anticardium,
	TheRed
};

//ĳ���� �θ� Ŭ����. ��� ĳ����Ŭ������ �� Ŭ������ ��ӹ޴´�.
class Character
{
public:
	Character();
	bool getDamage();
	bool isAttack();
	bool setClass(CLASS Class);
private:
	int HealthPoint, ManaPoint, AttackPoint, DefensePoint, AttackRange, Stemina;
	bool AttackAvailable;
	CLASS Class;
	Point Location;
	enum Rotation;
};
#endif __CHARACTER_H__
