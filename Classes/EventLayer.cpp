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
    GameLayer* gameLayer = (GameLayer*) getParent()->getChildByName("Stage");
    switch (keyCode)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_1:
        {
            getParent()->removeChildByName("Stage");
            auto pLayer = GameLayer::createLayer();
            pLayer->UI_StageName(1);
            getParent()->addChild(pLayer,1,"Stage");
            break;
        }
        case cocos2d::EventKeyboard::KeyCode::KEY_2:
        {
            getParent()->removeChildByName("Stage");
            auto pLayer = GameLayer::createLayer();
            pLayer->UI_StageName(2);
            getParent()->addChild(pLayer,1,"Stage");
            break;
        }
        case cocos2d::EventKeyboard::KeyCode::KEY_3:
        {
            getParent()->removeChildByName("Stage");
            auto pLayer = GameLayer::createLayer();
            pLayer->UI_StageName(3);
            getParent()->addChild(pLayer,1,"Stage");
            break;
        }
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        {
            if(gameLayer == nullptr)
                return;
            
            gameLayer->pMyCTR_->MoveLeft(gameLayer->pMyNode_);
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        {
            if(gameLayer == nullptr)
                return;
            
            gameLayer->pMyCTR_->MoveRight(gameLayer->pMyNode_);
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        {
            if(gameLayer == nullptr)
                return;
             
            gameLayer->pMyCTR_->MoveUp(gameLayer->pMyNode_);
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        {
            if(gameLayer == nullptr)
                return;
            
            gameLayer->pMyCTR_->MoveDown(gameLayer->pMyNode_);
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
        {
            if(gameLayer == nullptr)
                return;
            
            gameLayer->pMyCTR_->Rotation(gameLayer->pMyNode_);
            break;
        }
        
        case cocos2d::EventKeyboard::KeyCode::KEY_ENTER:
        {
            if(gameLayer == nullptr)
                return;
            
            gameLayer->pMyCTR_->InputBlock(gameLayer->pMyNode_, gameLayer->grid_);
            gameLayer->GridUpdate();
            gameLayer->RandomNodeCreate();
            break;
        }
    }   
}
