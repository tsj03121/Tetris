//
//  Node_O.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_O_h
#define Node_O_h
#include "MyNode.h"



class Node_O : public MyNode
{
    
public:
    void RotSetting();
    
    cocos2d::Layer* getNodeLayer();
    
public:
    Node_O(int x, int y);
    
};

#endif /* Node_O_h */
