//
//  EventLayer.h
//  Tetris2
//
//  Created by CD-parkdaedong on 2020/08/25.
//

#ifndef EventLayer_h
#define EventLayer_h


class EventLayer : public cocos2d::Layer
{   
public:
    static EventLayer* createLayer();
    
    virtual bool init();
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(EventLayer);
};

#endif /* EventLayer_h */
