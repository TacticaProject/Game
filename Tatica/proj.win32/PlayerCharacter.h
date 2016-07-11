#ifndef __PLAYER_CHARACTER__
#define __PLAYER_CHARACTER__

#include "Character.h"
#include "cocos2d.h"


class PlayerCharacter : public Character
{
public:
	PlayerCharacter(CLASS Class, Point Position);
	bool getDamage(int Damage);
	bool usingSkill();
private:
	int SkillPoint;
};

#endif 