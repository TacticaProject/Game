#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

enum CLASS {
	SwordMan = 0,
	Archer,
	Shielder,
	Snake,
	Skeleton,
	Centauros,
	anticardium,
	TheRed
};

extern std::string spriteName[8];
	


typedef struct status{
	int HealthPoint;
	int ManaPoint;
	int AttackPoint;
	int DefencePoint;
	int Stamina;
	int AttackRange;
	
}status;

extern status ClassStat[8];

//ĳ���� �θ� Ŭ����. ��� ĳ����Ŭ������ �� Ŭ������ ��ӹ޴´�.
class Character
{
public:
	Character();
	bool getDamage(int Damage);
	bool isAttack();
	bool setClass(CLASS Class);
	bool setStat(CLASS Class);
	bool setHealthPoint(int HealthPoint);
	Point getLocation();
	bool setLocation(Point input);
	int getStemina();
	int getHealthPoint();
	int getManaPoint();
	int getAttackPoint();
	int	getDefensePoint();
	int getAttackRange();
	CLASS getClass();
private:
	int HealthPoint, ManaPoint, AttackPoint, DefensePoint, AttackRange, Stemina;
	bool AttackAvailable;
	CLASS Class;
	Point Location;
	enum Rotation;
};
#endif 