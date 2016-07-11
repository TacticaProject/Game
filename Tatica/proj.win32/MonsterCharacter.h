#ifndef __MONSTER_CHARACTER__
#define __MONSTER_CHARACTER__

#include "Character.h"

class MonsterCharacter : public Character
{
public:
	MonsterCharacter(CLASS Class, Point location);
	//적 행동 결정
	bool MonsterAI();
private:
	//공격 우선 순위 변수
	enum priorityEnemy;
	//감지 범위 안에 적이 있는지 확인
	bool checkRange();
	//이동
	bool isMove();
	bool isAttack();
	bool checkPriorityEnemy();
};

#endif 