//
//  GameLayer.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef GameLayer_h
#define GameLayer_h

#include "MyNode.h"
#include "MyCTR.h"

class GameLayer : public cocos2d::Layer
{
public:
    int stageLevel_;
    int lineClear_;
    int col_; // x
    int row_; // y
    int grid_[20][10];
    
    MyCTR* pMyCTR_;
    
    cocos2d::Sprite* pBackGround_ = nullptr;
    cocos2d::Label* pStageName_ = nullptr;
    cocos2d::LayerColor* pNextBorder_ = nullptr;
    cocos2d::LayerColor* pNextBorder2_ = nullptr;
    
    MyNode* pNextMyNode_ = nullptr;
    MyNode* pMyNode_ = nullptr;
    
public:
    static GameLayer* createLayer();
    
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameLayer);
public:
    void RandomNodeCreate();
    void GridUpdate();
    void LineClear();
    void NextNode();
    void UI_StageName(int i);
    
public:
    GameLayer();
    ~GameLayer();
};




#endif /* GameLayer_h */
