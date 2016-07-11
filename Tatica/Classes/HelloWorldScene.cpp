#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	_tileMap = TMXTiledMap::create("untitled.tmx");
/*	_background = _tileMap->layerNamed("base");
	_respawn = _tileMap->layerNamed("respawn");
	_tree = _tileMap->layerNamed("tree");
	_item = _tileMap->layerNamed("item");
	_object = _tileMap->layerNamed("object");
	_cliff_2 = _tileMap->layerNamed("cliff");
	_base_2 = _tileMap->layerNamed("base_s");
	_cliff_bridge = _tileMap->layerNamed("cliff&bridge");*/
	


	//this->addChild(_tileMap);
	
	Size winsize = Director::getInstance()->getWinSize();
	auto scroll = ScrollView::create(winsize);
	scroll->setDirection(ScrollView::Direction::BOTH);
	scroll->setBounceable(false);
	scroll->setContainer(_tileMap);
	scroll->setContentSize(_tileMap->getContentSize());

	auto containorNode = scroll->getContainer();
	this->addChild(scroll, 1, 1);

	
	return true;
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::scrollViewDidScroll(ScrollView* view)

{

	log("scrollViewDidScroll....");

}




void HelloWorld::scrollViewDidZoom(ScrollView* view)

{

	log("scrollViewDidZoom....");

}



void HelloWorld::availableMove(PlayerCharacter player)
{
	int TempMap[45][38];
	for(int width = 0; width < 45; width++)
	{
		for(int height = 0; height < 38; height++)
		{
			TempMap[width][height] = -1;
		}
	}
	TempMap[(int)player.getLocation().x][(int)player.getLocation().y] = 0;
	for(int i = 0; i < player.getStemina(); i++)
	{
		for(int width = 0; width < 45; width++)
		{
			for(int height = 0; height < 38; height++)
			{
				//갈 수 있는 곳과 거리 저장
				if(player.getStemina() > 0)
				{
					if(width > 0 && GameMap[width-1][height].State == 0 
						&& (TempMap[width-1][height] > TempMap[width][height] || TempMap[width-1][height] == -1))
					{
						TempMap[width-1][height] = TempMap[width][height] + 1;
					}
					if(width < 44 && GameMap[width+1][height].State == 0 
						&& (TempMap[width+1][height] > TempMap[width][height] || TempMap[width+1][height] == -1))
					{
						TempMap[width+1][height] = TempMap[width][height] + 1;
					}
					if(height > 0 && GameMap[width][height-1].State == 0 
						&& (TempMap[width][height-1] > TempMap[width][height] || TempMap[width][height-1] == -1))
					{
						TempMap[width][height-1] = TempMap[width][height] + 1;
					}
					if(height < 37 && GameMap[width][height+1].State == 0 
						&& (TempMap[width][height+1] > TempMap[width][height] || TempMap[width][height+1] == -1))
					{
						TempMap[width][height+1] = TempMap[width][height] + 1;
					}
				}
			}
		}
	}
}