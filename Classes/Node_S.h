//
//  Node_S.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_S_h
#define Node_S_h
#include "MyNode.h"


class Node_S : public MyNode
{
public:
    void RotSetting();
    
    cocos2d::Layer* getNodeLayer();
    
public:
    Node_S(int x, int y);
    
};

#endif /* Node_S_h */
