//
//  Node.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_h
#define Node_h



class MyNode : public cocos2d::Node
{
public:
    int myX_ = 0;
    int myY_ = 0;
    char nodeType_;
    int rotation_ = 0;
    
    cocos2d::Sprite* pSprite_[4] = {};
    cocos2d::Layer* pMyNodeLayer_;
    
public:
    void MyNodeSpriteCreate();
    void RotSetting();
    
public:
    MyNode(int x, int y);
    ~MyNode();
};

#endif /* Node_h */
