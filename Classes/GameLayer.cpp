//
//  GameLayer.cpp
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#include <stdio.h>
#include "GameLayer.h"
#include "MyNode.h"

USING_NS_CC;

//생성자 부르고 init에서 다해주고 layer를 리턴해줘서 씬에 추가해주기만 하면됨!

GameLayer* GameLayer::createLayer()
{
    return GameLayer::create();
}

GameLayer::GameLayer()
{
    stageLevel_ = 0;
    lineClear_ = 0;
    row_ = 20;
    col_ = 10;
    
    pMyCTR_ = new MyCTR();
    
    for(int i_row = 0; i_row < row_; ++i_row)
    {
        for(int t_col = 0; t_col < col_; ++t_col)
        {
            grid_[i_row][t_col] = 0;
        }
    }
}

GameLayer::~GameLayer()
{

    delete pMyCTR_;
}

bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    int width = Director::getInstance()->getWinSize().width;
    int height = Director::getInstance()->getWinSize().height;
    
    pBackGround_ = Sprite::create("white.png", Rect(0,0, 300,600));
    pBackGround_->setColor(Color3B::GRAY);
    pBackGround_->setAnchorPoint(Vec2::ZERO);
    addChild(pBackGround_, -1);
    
    pNextBorder_ = LayerColor::create(Color4B::ORANGE,200,200);
    pNextBorder_->setPosition(Vec2(width - 250, height - 250));
    addChild(pNextBorder_);
    
    pNextBorder2_ = LayerColor::create(Color4B::BLACK, 190, 190);
    pNextBorder2_->setPosition(Vec2(width - 245, height - 245));
    addChild(pNextBorder2_);
    
    RandomNodeCreate();
    
    auto K_listenr = EventListenerKeyboard::create();
    K_listenr->onKeyPressed = CC_CALLBACK_2(::GameLayer::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(K_listenr, this);
    
    return true;
}

void GameLayer::UI_StageName(int i)
{
    int width = Director::getInstance()->getWinSize().width;
    int height = Director::getInstance()->getWinSize().height;
    
    pStageName_ = Label::createWithTTF(("Stage " + std::to_string(i)), "fonts/Marker Felt.ttf", 50);
    pStageName_->setPosition(Vec2(width / 2, height - 50));
    addChild(pStageName_);
}

void GameLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    switch (keyCode)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        {
            switch (pMyCTR_->nodeType_)
            {
                case 'I':
                {
                    pMyCTR_->MoveLeft(pNode_I_);
                    break;
                }
                case 'O':
                {
                    pMyCTR_->MoveLeft(pNode_O_);
                    break;
                }
                case 'T':
                {
                    pMyCTR_->MoveLeft(pNode_T_);
                    break;
                }
                case 'J':
                {
                    pMyCTR_->MoveLeft(pNode_J_);
                    break;
                }
                case 'Z':
                {
                    pMyCTR_->MoveLeft(pNode_Z_);
                    break;
                }
                case 'S':
                {
                    pMyCTR_->MoveLeft(pNode_S_);
                    break;
                }
                case 'L':
                {
                    pMyCTR_->MoveLeft(pNode_L_);
                    break;
                }
            }
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        {
            switch (pMyCTR_->nodeType_)
            {
                case 'I':
                {
                    pMyCTR_->MoveRight(pNode_I_);
                    break;
                }
                case 'O':
                {
                    pMyCTR_->MoveRight(pNode_O_);
                    break;
                }
                case 'T':
                {
                    pMyCTR_->MoveRight(pNode_T_);
                    break;
                }
                case 'J':
                {
                    pMyCTR_->MoveRight(pNode_J_);
                    break;
                }
                case 'Z':
                {
                    pMyCTR_->MoveRight(pNode_Z_);
                    break;
                }
                case 'S':
                {
                    pMyCTR_->MoveRight(pNode_S_);
                    break;
                }
                case 'L':
                {
                    pMyCTR_->MoveRight(pNode_L_);
                    break;
                }
                    
            }
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        {
            switch (pMyCTR_->nodeType_) {
                case 'I':
                {
                    pMyCTR_->MoveUp(pNode_I_);
                    break;
                }
                case 'O':
                {
                    pMyCTR_->MoveUp(pNode_O_);
                    break;
                }
                case 'T':
                {
                    pMyCTR_->MoveUp(pNode_T_);
                    break;
                }
                case 'J':
                {
                    pMyCTR_->MoveUp(pNode_J_);
                    break;
                }
                case 'Z':
                {
                    pMyCTR_->MoveUp(pNode_Z_);
                    break;
                }
                case 'S':
                {
                    pMyCTR_->MoveUp(pNode_S_);
                    break;
                }
                case 'L':
                {
                    pMyCTR_->MoveUp(pNode_L_);
                    break;
                }
            }
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        {
            switch (pMyCTR_->nodeType_)
            {
                case 'I':
                {
                    pMyCTR_->MoveDown(pNode_I_);
                    break;
                }
                case 'O':
                {
                    pMyCTR_->MoveDown(pNode_O_);
                    break;
                }
                case 'T':
                {
                    pMyCTR_->MoveDown(pNode_T_);
                    break;
                }
                case 'J':
                {
                    pMyCTR_->MoveDown(pNode_J_);
                    break;
                }
                case 'Z':
                {
                    pMyCTR_->MoveDown(pNode_Z_);
                    break;
                }
                case 'S':
                {
                    pMyCTR_->MoveDown(pNode_S_);
                    break;
                }
                case 'L':
                {
                    pMyCTR_->MoveDown(pNode_L_);
                    break;
                }
            }
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
        {
            switch (pMyCTR_->nodeType_)
            {
                case 'I':
                {
                    pMyCTR_->Rotation(pNode_I_);
                    break;
                }
                case 'O':
                {
                    pMyCTR_->Rotation(pNode_O_);
                    break;
                }
                case 'T':
                {
                    pMyCTR_->Rotation(pNode_T_);
                    break;
                }
                case 'J':
                {
                    pMyCTR_->Rotation(pNode_J_);
                    break;
                }
                case 'Z':
                {
                    pMyCTR_->Rotation(pNode_Z_);
                    break;
                }
                case 'S':
                {
                    pMyCTR_->Rotation(pNode_S_);
                    break;
                }
                case 'L':
                {
                    pMyCTR_->Rotation(pNode_L_);
                    break;
                }
            }
            break;
        }
        
        case cocos2d::EventKeyboard::KeyCode::KEY_ENTER:
        {
            switch (pMyCTR_->nodeType_)
            {
                case 'I':
                {
                    pMyCTR_->InputBlock(pNode_I_, grid_);
                    break;
                }
                case 'O':
                {
                    pMyCTR_->InputBlock(pNode_O_, grid_);
                    break;
                }
                case 'T':
                {
                    pMyCTR_->InputBlock(pNode_T_, grid_);
                    break;
                }
                case 'J':
                {
                    pMyCTR_->InputBlock(pNode_J_, grid_);
                    break;
                }
                case 'Z':
                {
                    pMyCTR_->InputBlock(pNode_Z_, grid_);
                    break;
                }
                case 'S':
                {
                    pMyCTR_->InputBlock(pNode_S_, grid_);
                    break;
                }
                case 'L':
                {
                    pMyCTR_->InputBlock(pNode_L_, grid_);
                    break;
                }
            }
            GridUpdate();
            RandomNodeCreate();
            break;
        }
            
        case cocos2d::EventKeyboard::KeyCode::KEY_P:
        {
            if(Director::getInstance()->isPaused())
            {
                Director::getInstance()->resume();
            }
            else
            {
                Director::getInstance()->pause();
            }
        }
    }
}

void GameLayer::RandomNodeCreate()
{
    if(pNextMyNode_ == nullptr)
    {
        NextNode();
    }
    
    switch (pNextMyNode_->nodeType_)
    {
        case 'I':
        {
            pMyCTR_->nodeType_ = 'I';
            pNode_I_ = new Node_I(5, 18);
            pNode_I_->nodeType_ = 'I';
            addChild(pNode_I_->getNodeLayer(),5);
            break;
        }
        case 'O':
        {
            pMyCTR_->nodeType_ = 'O';
            pNode_O_ = new Node_O(5, 18);
            pNode_O_->nodeType_ = 'O';
            addChild(pNode_O_->getNodeLayer(),5);
            break;
        }
        case 'T':
        {
            pMyCTR_->nodeType_ = 'T';
            pNode_T_ = new Node_T(5, 18);
            pNode_T_->nodeType_ = 'T';
            addChild(pNode_T_->getNodeLayer(),5);
            break;
        }
        case 'J':
        {
            pMyCTR_->nodeType_ = 'J';
            pNode_J_ = new Node_J(5, 18);
            pNode_J_->nodeType_ = 'J';
            addChild(pNode_J_->getNodeLayer(),5);
            break;
        }
        case 'Z':
        {
            pMyCTR_->nodeType_ = 'Z';
            pNode_Z_ = new Node_Z(5, 18);
            pNode_Z_->nodeType_ = 'Z';
            addChild(pNode_Z_->getNodeLayer(),5);
            break;
        }
        case 'S':
        {
            pMyCTR_->nodeType_ = 'S';
            pNode_S_ = new Node_S(5, 18);
            pNode_S_->nodeType_ = 'S';
            addChild(pNode_S_->getNodeLayer(),5);
            break;
        }
        case 'L':
        {
            pMyCTR_->nodeType_ = 'L';
            pNode_L_ = new Node_L(5, 18);
            pNode_L_->nodeType_ = 'L';
            addChild(pNode_L_->getNodeLayer(),5);
            break;
        }
    }
    NextNode();
}

void GameLayer::GridUpdate()
{
    LineClear();
    pBackGround_->removeAllChildren();
    
    for(int row_i = 0; row_i < 20; ++row_i)
    {
        for(int col_t = 0; col_t < 10; ++col_t)
        {
            if(grid_[row_i][col_t] == 1)
            {
                Sprite* sprite = Sprite::create("CloseSelected.png", Rect(0, 0, 30, 30));
                sprite->setAnchorPoint(Vec2::ZERO);
                sprite->setPosition(Vec2((col_t * 30), (row_i * 30)));
                pBackGround_->addChild(sprite);
            }
        }
    }

}

void GameLayer::LineClear()
{
    int count = 0;
    int clearRow = 0;
    for(int row_i = 0; row_i < 20; ++row_i)
    {
        clearRow = row_i;
        for(int col_t = 0; col_t < 10; ++col_t)
        {
            if(grid_[row_i][col_t] == 1)
            {
                count += 1;
            }
        }
        if(count == 10)
        {
            row_i -= 1;
            lineClear_ += 1;
            
            for(int i = clearRow; i < 20; ++i)
            {
                for(int t = 0; t < 10; ++t)
                {
                    if(i != 19)
                    {
                        grid_[i][t] = grid_[i+1][t];
                        grid_[i+1][t] = 0;
                    }
                    else
                    {
                        grid_[i][t] = 0;
                    }
                }
            }
            cocos2d::log("Line Clear!! %d 클리어 했습니다.", lineClear_);
        }
        count = 0;
    }
}

void GameLayer::NextNode()
{
    int blockRandom = rand() % 7;
    pNextMyNode_ = new MyNode(5, 18);
    switch (blockRandom)
    {
        case 0:
        {
            pNextMyNode_->nodeType_ = 'I';
//            Sprite* pNextNode = Sprite::create("I.png");
//            pNextNode->setAnchorPoint(Vec2::ZERO);
//            pNextNode->setScale(0.2, 0.2);
//            pNextNode->setPosition(Vec2(100,100));
//            pNextBorder2_->addChild(pNextNode);
            break;
        }
        case 1:
        {
            pNextMyNode_->nodeType_ = 'T';
            break;
        }
        case 2:
        {
            pNextMyNode_->nodeType_ = 'O';
            break;
        }
        case 3:
        {
            pNextMyNode_->nodeType_ = 'Z';
            break;
        }
        case 4:
        {
            pNextMyNode_->nodeType_ = 'S';
            break;
        }
        case 5:
        {
            pNextMyNode_->nodeType_ = 'J';
            break;
        }
        case 6:
        {
            pNextMyNode_->nodeType_ = 'L';
            break;
        }
    }
}
