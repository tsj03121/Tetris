//
//  Node_T.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_T_h
#define Node_T_h
#include "MyNode.h"



class Node_T : public MyNode
{
    
public:
    virtual void RotSetting() override;
    
    virtual cocos2d::Layer* getNodeLayer() override;
    
public:
    Node_T(int x, int y);
    
};

#endif /* Node_T_h */
