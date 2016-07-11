#ifndef __MONSTER_CHARACTER__
#define __MONSTER_CHARACTER__

#include "Character.h"

class MonsterCharacter : public Character
{
public:
	MonsterCharacter();
	//�� �ൿ ����
	bool MonsterAI();
private:
	//���� �켱 ���� ����
	enum priorityEnemy;
	//���� ���� �ȿ� ���� �ִ��� Ȯ��
	bool checkRange();
	//�̵�
	bool isMove();
	bool isAttack();
	bool checkPriorityEnemy();
}

#endif __MONSTER_CHARACTER__