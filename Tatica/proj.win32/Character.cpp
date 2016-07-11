#include "Character.h"


bool Character::getDamage()
{
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