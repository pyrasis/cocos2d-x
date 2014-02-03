#ifndef __TOUCHPOINTTEST_H__
#define __TOUCHPOINTTEST_H__

#include "../testBasic.h"

class TouchPointTestLayer : public Layer
{
public:
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    CREATE_FUNC(TouchPointTestLayer)

protected:
    cocos2d::DrawNode* _drawNode;
};

class TouchPointTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* __TOUCHPOINTTEST_H__ */
