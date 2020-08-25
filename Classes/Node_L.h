//
//  Node_l.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_L_h
#define Node_L_h
#include "MyNode.h"


class Node_L : public MyNode
{
public:
    void RotSetting();
    
    cocos2d::Layer* getNodeLayer();
    
public:
    Node_L(int x, int y);
    
};

#endif /* Node_l_h */
