//
//  Node_Z.cpp
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#include <stdio.h>
#include "Node_Z.h"

USING_NS_CC;

Node_Z::Node_Z(int x, int y)
: MyNode(x, y)
{
    RotSetting();
}

Layer* Node_Z::getNodeLayer()
{
    return pMyNodeLayer_;
}

//블록 회전 경우의 수
void Node_Z::RotSetting()
{
    pMyNodeLayer_->removeAllChildren();
    MyNodeSpriteCreate();
    switch (rotation_)
    {
        case 0:
        {
            pSprite_[0]->setPosition(Vec2((myX_ * 30), (myY_ * 30)));
            pSprite_[1]->setPosition(Vec2(((myX_-1) * 30), ((myY_+1) * 30)));
            pSprite_[2]->setPosition(Vec2(((myX_) * 30), ((myY_+1) * 30)));
            pSprite_[3]->setPosition(Vec2(((myX_+1) * 30), ((myY_) * 30)));
            break;
        }
        case 1:
        {
            pSprite_[0]->setPosition(Vec2((myX_ * 30), (myY_ * 30)));
            pSprite_[1]->setPosition(Vec2(((myX_) * 30), ((myY_-1) * 30)));
            pSprite_[2]->setPosition(Vec2(((myX_+1) * 30), ((myY_) * 30)));
            pSprite_[3]->setPosition(Vec2(((myX_+1) * 30), ((myY_+1) * 30)));
            break;
        }
        case 2:
        {
            pSprite_[0]->setPosition(Vec2((myX_ * 30), (myY_ * 30)));
            pSprite_[1]->setPosition(Vec2(((myX_-1) * 30), ((myY_) * 30)));
            pSprite_[2]->setPosition(Vec2(((myX_) * 30), ((myY_-1) * 30)));
            pSprite_[3]->setPosition(Vec2(((myX_+1) * 30), ((myY_-1) * 30)));
            break;
        }
        case 3:
        {
            pSprite_[0]->setPosition(Vec2((myX_ * 30), (myY_ * 30)));
            pSprite_[1]->setPosition(Vec2(((myX_) * 30), ((myY_+1) * 30)));
            pSprite_[2]->setPosition(Vec2(((myX_-1) * 30), ((myY_) * 30)));
            pSprite_[3]->setPosition(Vec2(((myX_-1) * 30), ((myY_-1) * 30)));
            break;
        }
    }
    
    for(int i = 0; i < 4; ++i)
    {
        pMyNodeLayer_-> addChild(pSprite_[i]);
    }
}
