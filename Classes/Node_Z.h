//
//  Node_Z.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Node_Z_h
#define Node_Z_h
#include "MyNode.h"


class Node_Z : public MyNode
{
public:
    virtual void RotSetting() override;
    
    virtual cocos2d::Layer* getNodeLayer() override;
    
public:
    Node_Z(int x, int y);
    
};

#endif /* Node_Z_h */
