#ifndef __PLAYER_CHARACTER__
#define __PLAYER_CHARACTER__

#include "Character.h"
#include "cocos2d.h"

class PlayerCharacter : public Character
{
public:
	PlayerCharacter();
	bool usingSkill();
private:
	bool setSkill();
}

#endif __PLAYER_CHARACTER__