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

//캐릭터 부모 클래스. 모든 캐릭터클래스는 이 클래스를 상속받는다.
class Character
{
public:
	Character();
	bool getDamage();
	bool isAttack();
private:
	int HealthPoint, ManaPoint, AttackPoint, DefensePoint, AttackRange, Stemina;
	bool AttackAvailable;
	CLASS Class;
	Point Location;
	enum Rotation;
	
	bool setClass();
};
#endif __CHARACTER_H__
