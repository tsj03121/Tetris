//
//  TypeNodeFactroy.cpp
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/26.
//

#include <stdio.h>
#include "TypeNodeFactory.h"
#include "Node_T.h"
#include "Node_I.h"
#include "Node_O.h"
#include "Node_S.h"
#include "Node_Z.h"
#include "Node_J.h"
#include "Node_L.h"

MyNode* TypeNodeFactory::createNode(char type)
{
    MyNode* node = nullptr;
    
    switch (type) {
        case '0':
        case 'I':
            return new Node_I(5,18);
            break;
        case '1':
        case 'O':
            return new Node_O(5,18);
            break;
        case '2':
        case 'S':
            return new Node_S(5,18);
            break;
        case '3':
        case 'Z':
            return new Node_Z(5,18);
            break;
        case '4':
        case 'J':
            return new Node_J(5,18);
            break;
        case '5':
        case 'L':
            return new Node_L(5,18);
            break;
        case '6':
        case 'T':
            return new Node_T(5,18);
            break;
    }
    return node;
}
