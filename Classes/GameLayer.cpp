//
//  GameLayer.cpp
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#include <stdio.h>
#include "GameLayer.h"
#include "TypeNodeFactory.h"

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
    return true;
}

//스테이지 제목 설정
void GameLayer::UI_StageName(int i)
{
    int width = Director::getInstance()->getWinSize().width;
    int height = Director::getInstance()->getWinSize().height;
    
    pStageName_ = Label::createWithTTF(("Stage " + std::to_string(i)), "fonts/Marker Felt.ttf", 50);
    pStageName_->setPosition(Vec2(width / 2, height - 50));
    addChild(pStageName_);
}

//이번 노드 랜덤 생성
void GameLayer::RandomNodeCreate()
{
    TypeNodeFactory typeNodeFactory;
    
    if(pNextMyNode_ == nullptr)
    {
        NextNode();
    }
    
    pMyNode_ = typeNodeFactory.createNode(pNextMyNode_->nodeType_);
    pMyCTR_->nodeType_ = pNextMyNode_->nodeType_;
    addChild(pMyNode_->getNodeLayer(),1, "pMyNode");
    
    NextNode();
}

//화면 재구성
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

//다음 노드를 생성
void GameLayer::NextNode()
{
    int blockRandom = rand() % 7;
    TypeNodeFactory typeNodeFactory;
    std::string std = std::to_string(blockRandom);
    pNextMyNode_ = typeNodeFactory.createNode(std[0]);
}
