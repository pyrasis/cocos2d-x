/****************************************************************************
Copyright (c) 2013 cocos2d-x.org
Copyright (c) 2013 Lee, Jae-Hong

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __PLATFORM_TIZEN_CCACCELEROMETER_H__
#define __PLATFORM_TIZEN_CCACCELEROMETER_H__

#include "platform/CCCommon.h"
#include <ccTypes.h>
#include <FUix.h>
#include <functional>

NS_CC_BEGIN

class CC_DLL Accelerometer : public Tizen::Uix::Sensor::ISensorEventListener
{
public:
    /**
     * @js ctor
     */
    Accelerometer();
    /**
     * @js NA
     * @lua NA
     */
    ~Accelerometer();

    void setDelegate(std::function<void(Acceleration*)> function);
    void setAccelerometerInterval(float interval);
    void startSensor();
    void stopSensor();

    virtual void OnDataReceived(Tizen::Uix::Sensor::SensorType sensorType, Tizen::Uix::Sensor::SensorData& sensorData , result r);

private:
    std::function<void(Acceleration*)> _function;
    Acceleration _accelerationValue;
    Tizen::Uix::Sensor::SensorManager* __sensorMgr;
};

NS_CC_END

#endif
