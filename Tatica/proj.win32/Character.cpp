#include "Character.h"

std::string spriteName[8] = { "SwordMan.png",
"Archer.png",
"Shilder.png",
"Snake.png",
"Skeleton.png",
"Centauros.png",
"Anticardium.png",
"TheRed.png" };


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



Character::Character()
{

}

bool Character::getDamage(int Damage)
{
	if(Damage - DefensePoint > 0)
	{
		HealthPoint = HealthPoint - Damage + DefensePoint;
	}
	return true;
}

bool Character::isAttack()
{
	return true;
}

bool Character::setClass(CLASS Class)
{
	this->Class = Class;
	return true;
};

bool Character::setStat(CLASS Class)
{
	HealthPoint = ClassStat[Class].HealthPoint;
	AttackPoint = ClassStat[Class].AttackPoint;
	ManaPoint = ClassStat[Class].ManaPoint;
	DefensePoint = ClassStat[Class].DefencePoint;
	Stemina = ClassStat[Class].Stamina;
	AttackRange = ClassStat[Class].AttackRange;
	
	return true;
}

Point Character::getLocation()
{
	return Location;
}

bool Character::setLocation(Point input)
{
	Location = input;
	return true;
}

bool Character::setHealthPoint(int HealthPoint)
{
	this->HealthPoint = HealthPoint;
	return true;
}

int Character::getStemina()
{
	return Stemina;
}

int Character::getHealthPoint()
{
	return HealthPoint;
}

int Character::getAttackPoint()
{
	return AttackPoint;
}

int Character::getAttackRange()
{
	return AttackRange;
}

int Character::getManaPoint()
{
	return ManaPoint;
}

int Character::getDefensePoint()
{
	return DefensePoint;
}

CLASS Character::getClass()
{
	return Class;
}