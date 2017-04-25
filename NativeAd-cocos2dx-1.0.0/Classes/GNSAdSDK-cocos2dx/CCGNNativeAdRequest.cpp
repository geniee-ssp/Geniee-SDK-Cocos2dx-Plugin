#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"
#include "CCGNNativeAdRequest.h"
#include "jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge.h"
#define CLASS_NAME "jp/co/geniee/sdk/ads/nativead/GNNativeAdActivityBridge"

namespace GNSAdSDK {
    
    static CCGNNativeAdRequestDelegate* mDelegate;
    void CCGNNativeAdRequest::initialize(const char* zoneId)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "initialize", "(Ljava/lang/String;)V")) {
            jstring jZoneId = t.env->NewStringUTF(zoneId);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jZoneId);
        }
    }

    void CCGNNativeAdRequest::loadAds()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "loadAds", "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
    }
    
    void CCGNNativeAdRequest::setDelegate(CCGNNativeAdRequestDelegate* delegate)
    {
        mDelegate = delegate;
    }
    
    CCGNNativeAdRequestDelegate* CCGNNativeAdRequest::getDelegate()
    {
        return mDelegate;
    }
    
    void CCGNNativeAdRequest::dispose()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "dispose", "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
        mDelegate = NULL;
    }
    
    void CCGNNativeAdRequest::detachDelegate()
    {
        mDelegate = NULL;
    }
    
}

#endif
