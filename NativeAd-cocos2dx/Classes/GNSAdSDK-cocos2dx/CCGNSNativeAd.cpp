#include "CCGNSNativeAd.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "jp/co/geniee/sdk/ads/nativead/GNNativeAdActivityBridge"
USING_NS_CC;
namespace GNSAdSDK {

    CCGNSNativeAd* CCGNSNativeAd::create()
    {
        return new CCGNSNativeAd();
    }
    void CCGNSNativeAd::onTrackingImpression()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "onTrackingImpression", "(Ljava/lang/String;)V")) {
            jstring jZoneId = t.env->NewStringUTF(zoneID);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jZoneId);
        }
    }
    void CCGNSNativeAd::onTrackingClick()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "onTrackingClick", "(Ljava/lang/String;)V")) {
            jstring jZoneId = t.env->NewStringUTF(zoneID);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jZoneId);
        }
    }
}

#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#import <Foundation/Foundation.h>

#include "CCGNSNativeAd.h"
#import <GNAdSDK/GNNativeAd.h>

namespace GNSAdSDK {
    
    CCGNSNativeAd *CCGNSNativeAd::create()
    {
        return new CCGNSNativeAd();
    }
    
    CCGNSNativeAd *CCGNSNativeAd::from(GNNativeAd *nativeAd)
    {
        this->_nativeAd = nativeAd;
        
        this->zoneID = [nativeAd.zoneID UTF8String];
        this->advertiser = [nativeAd.advertiser UTF8String];
        this->title = [nativeAd.title UTF8String];
        this->description = [nativeAd.description UTF8String];
        this->cta = [nativeAd.cta UTF8String];
        this->icon_aspectRatio = nativeAd.icon_aspectRatio;
        this->icon_url = [nativeAd.icon_url UTF8String];
        this->icon_height = nativeAd.icon_height;
        this->icon_width = nativeAd.icon_width;
        this->screenshots_aspectRatio = nativeAd.screenshots_aspectRatio;
        this->screenshots_url = [nativeAd.screenshots_url UTF8String];
        this->screenshots_height = nativeAd.screenshots_height;
        this->screenshots_width = nativeAd.screenshots_width;
        this->app_appName = [nativeAd.app_appName UTF8String];
        this->app_appid = [nativeAd.app_appid UTF8String];
        this->app_rating = nativeAd.app_rating;
        this->app_storeURL = [nativeAd.app_storeURL UTF8String];
        this->app_targetAge = [nativeAd.app_targetAge UTF8String];
        this->optout_text = [nativeAd.optout_text UTF8String];
        this->optout_image_url = [nativeAd.optout_image_url UTF8String];
        this->optout_url = [nativeAd.optout_url UTF8String];
        
        return this;
    }
    
    void CCGNSNativeAd::onTrackingClick()
    {
        if (this->_nativeAd != NULL) {
            [this->_nativeAd trackingClick:[getRootViewController() view]];
        }
    }
    
    void CCGNSNativeAd::onTrackingImpression()
    {
        if(this->_nativeAd != NULL) {
            [this->_nativeAd trackingImpressionWithView:[getRootViewController() view]];
        }
    }
    
    UIViewController *CCGNSNativeAd::getRootViewController()
    {
        UIWindow *window = [UIApplication sharedApplication].keyWindow;
        if (window == nil) {
            window = [[UIApplication sharedApplication].windows objectAtIndex:0];
        }
        return window.rootViewController;
    }
}

#endif
