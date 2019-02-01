/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
//#include "GNSAdSDK-cocos2dx/CCGNSNativeAdRequest.h"
#include "../../../NativeAd-cocos2dx/Classes/GNSAdSDK-cocos2dx/CCGNSNativeAdRequest.h"
#include "../../../NativeAd-cocos2dx/Classes/GNSAdSDK-cocos2dx/CCGNSNativeAd.h"
#include <stdio.h>
#include <ui/UIEditBox/UIEditBox.h>
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Scene, CCGNSNativeAdRequestDelegate
{
private:
    void sendNativeAdRequest();
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    // Zone Ids value
    const char *zoneIds = "";

    //Sample label, edit, button for load ad
    cocos2d::Label *label;
    cocos2d::ui::EditBox *zoneid_edit;
    cocos2d::ui::ScrollView *scrollView;
    cocos2d::Label *debugLog;
    
    GNSAdSDK::CCGNSNativeAdRequest *nativeAdRequest;
    
    void push_Load_Button(Ref *pSender);
    void clearLog(Ref *pSender);
    void addLog(const std::string logAdded);
    
    /// Tells the delegate that a native ad was received.
    virtual void onNativeAdsLoaded(std::vector<GNSAdSDK::CCGNSNativeAd *> nativeAds);
    
    /// Tells the delegate that the native ad failed to load.
    virtual void onNativeAdsFailedToLoad();
    
    /// Tells the delegate that the native ad shoud start internal browser with click.
    virtual bool onShouldStartInternalBrowserWithClick(const char* landingURL);
    
};

#endif // __HELLOWORLD_SCENE_H__
