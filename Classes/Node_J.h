//
//  Node_J.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_J_h
#define Node_J_h
#include "MyNode.h"


class Node_J : public MyNode
{
public:
    void RotSetting();
    
    cocos2d::Layer* getNodeLayer();
    
public:
    Node_J(int x, int y);
    
};

#endif /* Node_J_h */
