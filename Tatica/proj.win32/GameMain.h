#ifndef __MENU_H__
#define __MENU_H__

#include "cocos2d.h"
USING_NS_CC;

//����ȭ��� Ŭ����
class GameMain : public cocos2d::Layer
{
private:
	//���콺 ����Ŭ�� �̺�Ʈ
	void onMouseLeft(Event *event);

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	bool startGame();
	bool exitGame();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameMain);
};



#endif 