#include "MonsterCharacter.h"

MonsterCharacter::MonsterCharacter(CLASS Class, Point point)
{
	if(Class <= 3)
	{
		printf("에러다!!에러다!!에러다!!");
	}
}

bool MonsterCharacter::MonsterAI()
{
	return true;
}
bool MonsterCharacter::checkRange()
{
	return true;
}

bool MonsterCharacter::isMove()
{
	return true;
}

bool MonsterCharacter::isAttack()
{
	return true;
}

bool MonsterCharacter::checkPriorityEnemy()
{
	return true;
}