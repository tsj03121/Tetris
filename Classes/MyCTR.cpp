//
//  Controller.cpp
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/24.
//

#include <stdio.h>
#include "MyCTR.h"
#include "Node_I.h"
#include "Node_O.h"
#include "Node_T.h"
#include "Node_J.h"
#include "Node_Z.h"
#include "Node_S.h"
#include "Node_L.h"

USING_NS_CC;


MyCTR::MyCTR()
{
    nodeType_ = '0';
}

MyCTR::~MyCTR()
{
    
}
void MyCTR::NodePosSetting(MyNode* node)
{
    switch (node->nodeType_)
    {
        case 'I':
        {
            ((Node_I* )node)->RotSetting();
            break;
        }
        case 'O':
        {
            ((Node_O* )node)->RotSetting();
            break;
        }
        case 'T':
        {
            ((Node_T* )node)->RotSetting();
            break;
        }
        case 'J':
        {
            ((Node_J* )node)->RotSetting();
            break;
        }
        case 'Z':
        {
            ((Node_Z* )node)->RotSetting();
            break;
        }
        case 'S':
        {
            ((Node_S* )node)->RotSetting();
            break;
        }
        case 'L':
        {
            ((Node_L* )node)->RotSetting();
            break;
        }
    }
}

void MyCTR::MoveLeft(MyNode* node)
{
    if(!isMove(node, 'L'))
        return;
    
    node->myX_ -= 1;
    NodePosSetting(node);
}

void MyCTR::MoveRight(MyNode* node)
{
    if(!isMove(node,'R'))
        return;
    
    node->myX_ += 1;
    NodePosSetting(node);
}

void MyCTR::MoveUp(MyNode* node)
{
    if(!isMove(node,'U'))
        return;
    
    node->myY_ += 1;
    NodePosSetting(node);
}

void MyCTR::MoveDown(MyNode* node)
{
    if(!isMove(node,'D'))
        return;
    
    node->myY_ -= 1;
    NodePosSetting(node);
}

void MyCTR::Rotation(MyNode* node)
{
    node->rotation_ += 1;
    node->rotation_ = node->rotation_ % 4;
    
    NodePosSetting(node);
}

void MyCTR::InputBlock(MyNode* node, int grid[20][10])
{
    bool check = isInputBlockCheck(node, grid);
    
    if(!check)
        return;
    
    node->pMyNodeLayer_->removeAllChildren();

    switch (node->nodeType_) {
        case 'I':
        {
             switch (node->rotation_)
             {
                 case 0:
                 {
                      grid[node->myY_ + 1][node->myX_] = 1;
                      grid[node->myY_][node->myX_] = 1;
                      grid[node->myY_ - 1][node->myX_] = 1;
                      grid[node->myY_ - 2][node->myX_] = 1;
                     break;
                 }
                 case 1:
                 {
                      grid[node->myY_][node->myX_+1] = 1;
                      grid[node->myY_][node->myX_] = 1;
                      grid[node->myY_][node->myX_-1] = 1;
                      grid[node->myY_][node->myX_-2] = 1;
                      break;
                 }
                 case 2:
                 {
                     grid[node->myY_ + 1][node->myX_ - 1] = 1;
                     grid[node->myY_][node->myX_ - 1] = 1;
                     grid[node->myY_ - 1][node->myX_- 1] = 1;
                     grid[node->myY_ - 2][node->myX_- 1] = 1;
                     break;
                 }
                 case 3:
                 {
                     grid[node->myY_][node->myX_-2] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
            }
            break;
        }
        case 'O':
        {
             switch (node->rotation_)
             {
                 case 0:
                 case 1:
                 case 2:
                 case 3:
                 {
                     grid[node->myY_+1][node->myX_-1] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     break;
                 }
            }
            break;
        }
        case 'T':
        {
             switch (node->rotation_)
             {
                 case 0:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 1:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 2:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 3:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     break;
                 }
                 break;
            }
            break;
        }
        case 'J':
        {
             switch (node->rotation_)
             {
                 case 0:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_+1] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 1:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_+1] = 1;
                     break;
                 }
                 case 2:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 3:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_-1] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     break;
                 }
                 break;
            }
            break;
        }
        case 'Z':
        {
             switch (node->rotation_)
             {
                 case 0:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 1:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     grid[node->myY_+1][node->myX_+1] = 1;
                     break;
                 }
                 case 2:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_+1] = 1;
                     break;
                 }
                 case 3:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_-1][node->myX_-1] = 1;
                     break;
                 }
                 break;
            }
            break;
        }
        case 'S':
        {
             switch (node->rotation_)
             {
                 case 0:
                 {
                     grid[node->myY_ + 1][node->myX_] = 1;
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_ + 1][node->myX_ + 1] = 1;
                     grid[node->myY_][node->myX_- 1 ] = 1;
                     break;
                 }
                 case 1:
                 {
                     grid[node->myY_][node->myX_+1] = 1;
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_+1] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     break;
                 }
                 case 2:
                 {
                     grid[node->myY_][node->myX_+1] = 1;
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_-1] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     break;
                 }
                 case 3:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_+1][node->myX_-1] = 1;
                     break;
                 }
            }
            break;
        }
        case 'L':
        {
             switch (node->rotation_)
             {
                 case 0:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 1:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     grid[node->myY_+1][node->myX_+1] = 1;
                     break;
                 }
                 case 2:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_+1] = 1;
                     grid[node->myY_][node->myX_-1] = 1;
                     grid[node->myY_][node->myX_+1] = 1;
                     break;
                 }
                 case 3:
                 {
                     grid[node->myY_][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_] = 1;
                     grid[node->myY_-1][node->myX_-1] = 1;
                     grid[node->myY_+1][node->myX_] = 1;
                     break;
                 }
                 break;
            }
            break;
        }
            
    }
   
}

//맵 밖으로 나가는지 여부체크 즉 움직일 수 있냐 체크
bool MyCTR::isMove(MyNode* node, char type)
{
    for(int i = 0; i < 4; ++i)
    {
        float x = node->pSprite_[i]->getPositionX();
        float y = node->pSprite_[i]->getPositionY();

        if(x <= 0 && type == 'L')
            return false;
        if(x >= 250 && type == 'R')
            return false;
        if(y <= 0 && type == 'D')
            return false;
        if(y >= 550 && type == 'U')
            return false;
    }
    return true;
}

//어디 까지 블럭이 내려갈 수 있는지 체크
bool MyCTR::isInputBlockCheck(MyNode* node, int grid[20][10])
{
    //노드 타입이 무엇이냐
    switch (node->nodeType_)
    {
        case 'I':
        {
            //얼만큼 회전되어있냐
            switch (node->rotation_)
            {
                case 0:
                {
                    //바로 아래 벽이 있다면
                    if(node->myY_ == 2)
                        return true;
                    
                    do
                    {
                        if(grid[node->myY_-3][node->myX_] == 0)
                            node->myY_ -= 1;
                        else
                            return true;
                    }while(node->myY_ >= 3);
                    return true;
                    break;
                }
                    
                case 1:
                {
                    //자신의 위치에서 최대 아래까지 추측하여 0이면
                    if(node->myY_ == 0)
                        return true;
                    
                    //무한반복 돌리는데 로우가 0이될때까지 내려간다.
                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_ - 1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ - 2] == 1)
                        {
                            stop = true;
                        }
                        
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                        
                    }while(node->myY_ >= 1);
                    return true;
                    break;
                }
                    
                case 2:
                {
                    //바로 아래 벽이 있다면
                    if(node->myY_ == 2)
                        return true;
                    
                    do
                    {
                        if(grid[node->myY_-3][node->myX_-1] == 0)
                            node->myY_ -= 1;
                        else
                            return true;
                    }while(node->myY_ >= 3);
                    return true;
                    break;
                }
                
                case 3:
                {
                    //자신의 위치에서 최대 아래까지 추측하여 0이면
                    if(node->myY_ == 0)
                        return true;
                    
                    //무한반복 돌리는데 로우가 0이될때까지 내려간다.
                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 1][node->myX_ - 2] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                        
                    }while(node->myY_ >= 1);
                    return true;
                    break;
                }
            }
            break;
        }
        case 'O':
        {
            //얼만큼 회전되어있냐
            switch (node->rotation_)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                {
                    //자신의 위치에서 최대 아래까지 추측하여 0이면
                    if(node->myY_ == 0)
                        return true;
                    
                    //무한반복 돌리는데 로우가 0이될때까지 내려간다.
                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                        
                    }while(node->myY_ >= 1);
                    return true;
                    break;
                }
            }
            break;
        }
        case 'T':
        {
            //얼만큼 회전되어있냐
            switch (node->rotation_)
            {
                case 0:
                {
                    if(node->myY_ == 0)
                        return true;
                    
                    //무한반복 돌리는데 로우가 0이될때까지 내려간다.
                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 1);
                    return true;
                    break;
                }
                case 1:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_ - 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_ - 1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 2:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_ - 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_ - 1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_ - 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 3:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_ - 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_ - 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                
            }
            break;
        }
        case 'J':
        {
            //얼만큼 회전되어있냐
            switch (node->rotation_)
            {
                case 0:
                {
                    if(node->myY_ == 0)
                         return true;

                     do
                     {
                         bool stop = false;
                         if(grid[node->myY_-1][node->myX_] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_-1][node->myX_ - 1] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_-1][node->myX_ + 1] == 1)
                         {
                             stop = true;
                         }
                         
                         if(stop)
                             return true;
                         
                         node->myY_ -= 1;
                     }while(node->myY_ >= 1);
                     return true;
                     break;
                }
                case 1:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 2][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 2:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_-1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_-1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_-1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 3:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_-2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
            }
            break;
        }
        case 'Z':
        {
            switch (node->rotation_)
            {
                case 0:
                {
                    if(node->myY_ == 0)
                         return true;

                     do
                     {
                         bool stop = false;
                         if(grid[node->myY_-1][node->myX_] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_][node->myX_ - 1] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_-1][node->myX_ + 1] == 1)
                         {
                             stop = true;
                         }
                         
                         if(stop)
                             return true;
                         
                         node->myY_ -= 1;
                     }while(node->myY_ >= 1);
                     return true;
                     break;
                }
                case 1:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 2:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 2][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 3:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 2][node->myX_- 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
            }
            break;
        }
        case 'S':
        {
            switch (node->rotation_)
            {
                case 0:
                {
                    if(node->myY_ == 0)
                         return true;

                     do
                     {
                         bool stop = false;
                         if(grid[node->myY_-1][node->myX_] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_][node->myX_ + 1] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_-1][node->myX_ - 1] == 1)
                         {
                             stop = true;
                         }
                         
                         if(stop)
                             return true;
                         
                         node->myY_ -= 1;
                     }while(node->myY_ >= 1);
                     return true;
                     break;
                }
                case 1:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 2:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 2][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 3:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_- 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
            }
            break;
        }
        case 'L':
        {
            switch (node->rotation_)
            {
                case 0:
                {
                    if(node->myY_ == 0)
                         return true;

                     do
                     {
                         bool stop = false;
                         if(grid[node->myY_-1][node->myX_] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_-1][node->myX_ + 1] == 1)
                         {
                             stop = true;
                         }
                         if(grid[node->myY_-1][node->myX_ - 1] == 1)
                         {
                             stop = true;
                         }
                         
                         if(stop)
                             return true;
                         
                         node->myY_ -= 1;
                     }while(node->myY_ >= 1);
                     return true;
                     break;
                }
                case 1:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_][node->myX_+1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 2:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 1][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 1][node->myX_ - 1] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 2][node->myX_ + 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
                case 3:
                {
                    if(node->myY_ == 1)
                        return true;

                    do
                    {
                        bool stop = false;
                        if(grid[node->myY_- 2][node->myX_] == 1)
                        {
                            stop = true;
                        }
                        if(grid[node->myY_- 2][node->myX_- 1] == 1)
                        {
                            stop = true;
                        }
                        if(stop)
                            return true;
                        
                        node->myY_ -= 1;
                    }while(node->myY_ >= 2);
                    return true;
                    break;
                }
            }
            break;
        }
    }
    return false;
}
