//
//  Controller.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#ifndef Controller_h
#define Controller_h
#include "MyNode.h"

class MyCTR
{
public:
    char nodeType_;
    
    void MoveLeft(MyNode* node);
    void MoveRight(MyNode* node);
    void MoveUp(MyNode* node);
    void MoveDown(MyNode* node);
    void Rotation(MyNode* node);
    void InputBlock(MyNode* node, int grid[20][10]);
    void NodePosSetting(MyNode* node);
    
    
    bool isMove(MyNode* node, char type);
    bool isInputBlockCheck(MyNode* node, int grid[20][10]);
    
public:

public:
    MyCTR();
    ~MyCTR();
};


#endif /* Controller_h */
