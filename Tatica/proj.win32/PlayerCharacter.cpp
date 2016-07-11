#include "PlayerCharacter.h"

// Position = 캐릭터가 존재할 위치
PlayerCharacter::PlayerCharacter(CLASS Class, Point Position)
{
	setStat(Class);
	setLocation(Position);
	auto character = Sprite::create(spriteName[Class]);
	character->setAnchorPoint(Point(0.5, 0.5));
	character->setPosition(Position);

}
