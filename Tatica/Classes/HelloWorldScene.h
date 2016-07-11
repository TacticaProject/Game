#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "proj.win32\PlayerCharacter.h"
USING_NS_CC;

enum STATE{
	Free = 0,
	Block,
	pSwordMan,
	pArcher,
	pShilder,
	Monster
};

typedef struct map{
	int Layer;
	STATE State;
}MAP;

class HelloWorld : public cocos2d::Layer
{
private:
	CCTMXTiledMap *_tileMap;
	CCTMXLayer *_background; 
	MAP GameMap[45][38];

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	void availableMove(PlayerCharacter player);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

};



#endif 