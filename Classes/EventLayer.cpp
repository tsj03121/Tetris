//
//  EventLayer.cpp
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/25.
//

#include <stdio.h>
#include "EventLayer.h"
#include "GameLayer.h"

USING_NS_CC;

//생성자 부르고 init에서 다해주고 layer를 리턴해줘서 씬에 추가해주기만 하면됨!

EventLayer* EventLayer::createLayer()
{
    return EventLayer::create();
}

bool EventLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto K_listenr = EventListenerKeyboard::create();
    K_listenr->onKeyPressed = CC_CALLBACK_2(EventLayer::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(K_listenr, this);
    
    return true;
}

void EventLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    switch (keyCode)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_1:
        {
            this->removeAllChildren();
            auto pLayer = GameLayer::createLayer();
            pLayer->UI_StageName(1);
            addChild(pLayer,1,"Stage1");
            break;
        }
        case cocos2d::EventKeyboard::KeyCode::KEY_2:
        {
            this->removeAllChildren();
            auto pLayer = GameLayer::createLayer();
            pLayer->UI_StageName(2);
            addChild(pLayer,1,"Stage2");
            break;
        }
        case cocos2d::EventKeyboard::KeyCode::KEY_3:
        {
            this->removeAllChildren();
            auto pLayer = GameLayer::createLayer();
            pLayer->UI_StageName(3);
            addChild(pLayer,1,"Stage3");
            break;
        }
    }
    
}
