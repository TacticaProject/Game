#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

enum STATE{
	Free = 0,
	Block,
	SwordMan,
	Archer,
	Shilder,
	Monster
};

typedef struct map{
	Point location;
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
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

};



#endif