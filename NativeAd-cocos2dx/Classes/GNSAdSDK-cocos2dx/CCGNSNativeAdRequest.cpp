#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"
#include "CCGNSNativeAdRequest.h"
#define CLASS_NAME "jp/co/geniee/sdk/ads/nativead/GNNativeAdActivityBridge"

namespace GNSAdSDK {

    static CCGNSNativeAdRequestDelegate* mDelegate;
    void CCGNSNativeAdRequest::initialize(const char* zoneId)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "initialize", "(Ljava/lang/String;)V")) {
            jstring jZoneId = t.env->NewStringUTF(zoneId);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jZoneId);
        }
    }

    void CCGNSNativeAdRequest::loadAds()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "loadAds", "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
    }

    void CCGNSNativeAdRequest::multiLoadAds()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "multiLoadAds", "()V"))
        {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
    }

    void CCGNSNativeAdRequest::setDelegate(CCGNSNativeAdRequestDelegate* delegate)
    {
        mDelegate = delegate;
    }

    CCGNSNativeAdRequestDelegate* CCGNSNativeAdRequest::getDelegate()
    {
        return mDelegate;
    }

    void CCGNSNativeAdRequest::dispose()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "dispose", "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
        mDelegate = NULL;
    }

    void CCGNSNativeAdRequest::detachDelegate()
    {
        mDelegate = NULL;
    }

}

#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#import <Foundation/Foundation.h>

#import "CCGNSNativeAdRequest.h"
#import <GNAdSDK/GNNativeAdRequest.h>
#include "CCGNSNativeAdReqIOS.h"

namespace GNSAdSDK
{
    CCGNSNativeAdReqIOS *nativeAdRequesetIOS = [[CCGNSNativeAdReqIOS alloc] init];
    
    void CCGNSNativeAdRequest::initialize(const char *zoneId)
    {
        if (nativeAdRequesetIOS == NULL) {
            nativeAdRequesetIOS = [[CCGNSNativeAdReqIOS alloc] init];
        }
        
        [nativeAdRequesetIOS initialize:[NSString stringWithUTF8String:zoneId]];
        
    }
    
    void CCGNSNativeAdRequest::loadAds()
    {
        if (nativeAdRequesetIOS != NULL) {
            [nativeAdRequesetIOS loadAds];
        }
        
    }
    
    void CCGNSNativeAdRequest::multiLoadAds()
    {
        if (nativeAdRequesetIOS != NULL) {
            [nativeAdRequesetIOS multiLoadAds];
        }
    }
    
    void CCGNSNativeAdRequest::setDelegate(CCGNSNativeAdRequestDelegate *delegate)
    {
        [nativeAdRequesetIOS setDelegate: delegate];
    }
    
}

#endif
