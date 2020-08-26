//
//  NodeFactory.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/25.
//

#ifndef NodeFactory_h
#define NodeFactory_h
#include "MyNode.h"

class NodeFactory
{
public:
    virtual MyNode* createNode(char nodeType){};
};

#endif /* NodeFactory_h */
