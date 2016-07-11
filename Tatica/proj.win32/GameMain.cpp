#include "GameMain.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


Scene* GameMain::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameMain::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameMain::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto item_1 = MenuItemFont::create("���ӽ���",CC_CALLBACK_1(GameMain::menuCloseCallback, this));
	auto item_2 = MenuItemFont::create("��������",CC_CALLBACK_1(GameMain::menuCloseCallback, this));

	item_1->setTag(1);
	item_2->setTag(2);

	auto menu = Menu::create(item_1, item_2, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);
 

	return true;
}

//���콺 ���� ��ư Ŭ��
void GameMain::onMouseLeft(Event *event)
{
	EventMouse* e = (EventMouse*)event;

	if(e->getMouseButton() == MOUSE_BUTTON_LEFT)
	{
	}
}

//���� ��ŸƮ ��ư�� �������� �� ����
//�ΰ��� ������ ���� �ѱ��
bool GameMain::startGame()
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}

//���� ���� ��ư�� �������� ��
//Ŭ���̾�Ʈ�� �����Ѵ�
bool GameMain::exitGame()
{
	CCDirector::sharedDirector()->end();
}

void GameMain::menuCloseCallback(Ref* pSender)
{
    CCMenuItem* pTempItem = (CCMenuItem*)pSender;
    
    int i = pTempItem->getTag();
    
    CCScene* pScene;
    CCTransitionScene* pTran;
    
    switch (i) {
        case 1 :
            startGame();
            break;
        case 2 :
            exitGame();
            break;            
        default:
            break;
    }
    
    CCLog("%d Menu Clicked\n", i);
}