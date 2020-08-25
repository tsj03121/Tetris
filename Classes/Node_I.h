//
//  Node_I.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_I_h
#define Node_I_h
#include "MyNode.h"



class Node_I : public MyNode
{
    
public:
    void RotSetting();
    
    cocos2d::Layer* getNodeLayer();
    
public:
    Node_I(int x, int y);
    
};


#endif /* Node_I_h */
