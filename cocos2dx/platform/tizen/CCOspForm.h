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

#ifndef _CCOSPFORM_H_
#define _CCOSPFORM_H_

#include <FBase.h>
#include <FUi.h>

typedef void (*EditTextCallback)(const char* pText, void* ctx);

class OspForm
    : public Tizen::Ui::Controls::Form
    , public Tizen::Ui::ITouchEventListener
    , public Tizen::Ui::ITextEventListener
    , public Tizen::Ui::Controls::IFormBackEventListener
    , public Tizen::Ui::Controls::IFormMenuEventListener
{
public:
    /**
     * @js ctor
     */
    OspForm();
    /**
     * @js NA
     * @lua NA
     */
    ~OspForm();

    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void  OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
    virtual void  OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
    virtual void  OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
    virtual void  OnTouchLongPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
    virtual void  OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
    virtual void  OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
    virtual void  OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

    // ITextEventListener
    virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
    virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);

    // IFormBackEventListener
    virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

    // IFormBackEventListener
    virtual void OnFormMenuRequested(Tizen::Ui::Controls::Form& source);

    void ShowKeypad(const char* pMessage, Tizen::Ui::Controls::KeypadStyle keypadStyle, Tizen::Ui::Controls::KeypadInputModeCategory keypadCategory, bool bSingleLineEnabled, bool bTextPrediction, int nMaxLength, EditTextCallback pfEditTextCallback, void* pCtx);
    void ShowKeypad();
    void CloseKeypad();

    Tizen::Ui::Controls::Keypad*__pKeypad;
    EditTextCallback _editTextCallback;
    void* _ctx;
};

#endif  // _CCOSPFORM_H_
