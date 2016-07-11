#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "proj.win32\PlayerCharacter.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

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

class HelloWorld : public cocos2d::Layer, public ScrollViewDelegate
{
private:
	CCTMXTiledMap *_tileMap;
	CCTMXLayer *_background; 
	CCTMXLayer *_respawn;
	CCTMXLayer *_tree;
	CCTMXLayer *_item;
	CCTMXLayer *_object;
	CCTMXLayer *_cliff_2;
	CCTMXLayer *_base_2;
	CCTMXLayer *_cliff_bridge;
	CCTMXLayer *_base;
	MAP GameMap[45][38];

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	void availableMove(PlayerCharacter player);

	void scrollViewDidScroll(ScrollView* view);

	void scrollViewDidZoom(ScrollView* view);

	ScrollView* scrollView;



    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

};



#endif 