#include "TouchPointTest.h"

bool TouchPointTestLayer::init()
{
    if (Layer::init())
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = CC_CALLBACK_2(TouchPointTestLayer::onTouchBegan, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        auto title = LabelTTF::create("Please touch the screen!", "", 24);
        title->setPosition(VisibleRect::top()+Point(0, -40));
        addChild(title);
        
        _drawNode = DrawNode::create();
        addChild(_drawNode);
        
        return true;
    }
    return false;
}

bool TouchPointTestLayer::onTouchBegan(Touch* touch, Event* event)
{
    auto touchPoint = touch->getLocation();
    _drawNode->drawDot(touchPoint, 1.0f, Color4F(1.f, 1.f, 1.f, 1.f));

    Point vertical[2];
    vertical[0].x = 0;
    vertical[1].x = getContentSize().width;
    vertical[0].y = vertical[1].y = touchPoint.y;
    _drawNode->drawSegment(vertical[0], vertical[1], 1.f, Color4F(1.f, 1.f, 1.f, 1.f));

    Point horizontal[2];
    horizontal[0].y = 0;
    horizontal[1].y = getContentSize().height;
    horizontal[0].x = horizontal[1].x = touchPoint.x;
    _drawNode->drawSegment(horizontal[0], horizontal[1], 1.f, Color4F(1.f, 1.f, 1.f, 1.f));

    return true;
}


void TouchPointTestScene::runThisTest()
{
    auto layer = TouchPointTestLayer::create();

    addChild(layer, 0);

    Director::getInstance()->replaceScene(this);
}
