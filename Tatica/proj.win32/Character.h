#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

enum CLASS {
	SwordMan = 0,
	Archer,
	Shilder,
	Snake,
	Skeleton,
	Centauros,
	anticardium,
	TheRed
};

std::string spriteName[8] = {
	"SwordMan.png",
	"Archer.png",
	"Shilder.png",
	"Snake.png",
	"Skeleton.png",
	"Centauros.png",
	"anticardium.png",
	"TheRed" 
};

typedef struct status{
	int HealthPoint;
	int ManaPoint;
	int AttackPoint;
	int DefencePoint;
	int Stamina;
	int AttackRange;
	
}status;

status ClassStat[8] = {
	{ 100, 100, 30, 5, 10, 1 },
	{ 100, 100, 20, 3, 12, 4 },
	{ 120, 100, 15, 10, 9, 1 },
	{ 35, 0, 38, 0, 10, 1 },
	{ 70, 0, 15, 4, 7, 1 },
	{ 45, 0, 25, 2, 10, 4 },
	{ 60, 0, 55, 4, 5, 1 },
	{ 50, 0, 30, 2, 8, 1 }
};

//캐릭터 부모 클래스. 모든 캐릭터클래스는 이 클래스를 상속받는다.
class Character
{
public:
	Character();
	bool getDamage();
	bool isAttack();
	bool setClass(CLASS Class);
	bool setStat(CLASS Class);
	Point getLocation();
	bool setLocation(Point input);
	int getStemina();
	int getHealthPoint();
	int getManaPoint();
	int getAttackPoint();
	int	getDefensePoint();
	int getAttackRange();
private:
	int HealthPoint, ManaPoint, AttackPoint, DefensePoint, AttackRange, Stemina;
	bool AttackAvailable;
	CLASS Class;
	Point Location;
	enum Rotation;
};
#endif __CHARACTER_H__
