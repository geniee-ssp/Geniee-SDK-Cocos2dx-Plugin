#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"
#include "CCGNSRewardVideoAd.h"
#include "jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge.h"
#define CLASS_NAME "jp/co/geniee/gnadsdk/rewardvideo/GNSRewardActivityBridge"

namespace GNSAdSDK {
    
    static CCGNSRewardVideoAdDelegate* mDelegate;
    void CCGNSRewardVideoAd::initialize(const char* zoneId)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "initialize", "(Ljava/lang/String;)V")) {
            jstring jZoneId = t.env->NewStringUTF(zoneId);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jZoneId);
        }
    }

    void CCGNSRewardVideoAd::loadRequest()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "loadRequest", "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
    }
    
    void CCGNSRewardVideoAd::setDelegate(CCGNSRewardVideoAdDelegate* delegate)
    {
        mDelegate = delegate;
    }
    
    CCGNSRewardVideoAdDelegate* CCGNSRewardVideoAd::getDelegate()
    {
        return mDelegate;
    }
    
    bool CCGNSRewardVideoAd::canShow()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "canShow", "()Z")) {
            return t.env->CallStaticBooleanMethod(t.classID, t.methodID);
        }
        return false;
    }
    
    void CCGNSRewardVideoAd::show()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "show", "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
    }
    
    void CCGNSRewardVideoAd::dispose()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "dispose", "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
        mDelegate = NULL;
    }
    
    void CCGNSRewardVideoAd::detachDelegate()
    {
        mDelegate = NULL;
    }
    
}

#endif
