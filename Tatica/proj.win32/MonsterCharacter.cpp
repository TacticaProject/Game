#include "MonsterCharacter.h"

MonsterCharacter::MonsterCharacter(CLASS Class, Point point)
{
	if(Class <= 3)
	{
		printf("������!!������!!������!!");
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