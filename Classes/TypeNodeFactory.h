//
//  TypeNodeFactory.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/26.
//

#ifndef TypeNodeFactory_h
#define TypeNodeFactory_h

#include "NodeFactory.h"
#include "MyNode.h"

class TypeNodeFactory : public NodeFactory
{
    
public:
    virtual MyNode* createNode(char nodeType) override;
};
#endif /* TypeNodeFactory_h */
