#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <iostream>
#include "CCGNNativeAd.h"
#include "CCGNNativeAdRequest.h"
#include "ui/CocosGUI.h"
#include <vector>

class HelloWorld : public cocos2d::Scene, CCGNNativeAdRequestDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    //Sample label, edit, button for load ad
    cocos2d::Label* label;
    cocos2d::ui::EditBox* zoneid_edit;
    void push_Load_Button(Ref *pSender);
    
    // CCGNNativeAdRequestDelegate callback
    virtual void onNativeAdsLoaded(std::vector<GNSAdSDK::CCGNNativeAd*> nativeAds);
    virtual void onNativeAdsFailedToLoad();
    virtual bool onShouldStartInternalBrowserWithClick(const char* landingURL);
};

#endif // __HELLOWORLD_SCENE_H__
