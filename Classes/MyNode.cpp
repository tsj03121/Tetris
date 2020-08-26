//
//  Node.cpp
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#include <stdio.h>
#include "MyNode.h"

USING_NS_CC;

MyNode::MyNode(int x, int y)
{
    myX_ = x;
    myY_ = y;
    
    pMyNodeLayer_ = Layer::create();
}

MyNode::~MyNode()
{
    for(int i = 0; i < 4; ++i)
    {
        pSprite_[i]->release();
    }
    delete pMyNodeLayer_;
}

void MyNode::MyNodeSpriteCreate()
{
    for(int i = 0; i < 4; ++i)
    {
        pSprite_[i] = nullptr;
        pSprite_[i] = Sprite::create("CloseSelected.png", Rect(0, 0, 30, 30));
        pSprite_[i]->setAnchorPoint(Vec2::ZERO);
        
        pSprite_[i]->retain();
    }
}
