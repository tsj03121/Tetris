//
//  GameLayer.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef GameLayer_h
#define GameLayer_h

#include "Node_I.h"
#include "Node_O.h"
#include "Node_T.h"
#include "Node_J.h"
#include "Node_Z.h"
#include "Node_S.h"
#include "Node_L.h"
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
    Node_I* pNode_I_ = nullptr;
    Node_O* pNode_O_ = nullptr;
    Node_T* pNode_T_ = nullptr;
    Node_J* pNode_J_ = nullptr;
    Node_Z* pNode_Z_ = nullptr;
    Node_S* pNode_S_ = nullptr;
    Node_L* pNode_L_ = nullptr;
    
public:
    static GameLayer* createLayer();
    
    virtual bool init();
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
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
