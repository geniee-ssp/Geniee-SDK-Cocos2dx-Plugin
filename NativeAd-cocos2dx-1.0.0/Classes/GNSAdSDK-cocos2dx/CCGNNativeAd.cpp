#include "CCGNNativeAd.h"
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "jp/co/geniee/sdk/ads/nativead/GNNativeAdActivityBridge"
USING_NS_CC;
namespace GNSAdSDK {

    CCGNNativeAd* CCGNNativeAd::create()
    {
        return new CCGNNativeAd();
    }
    void CCGNNativeAd::onTrackingImpression()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "onTrackingImpression", "(Ljava/lang/String;)V")) {
            jstring jZoneId = t.env->NewStringUTF(zoneID);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jZoneId);
        }
    }
    void CCGNNativeAd::onTrackingClick()
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "onTrackingClick", "(Ljava/lang/String;)V")) {
            jstring jZoneId = t.env->NewStringUTF(zoneID);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jZoneId);
        }
    }
}
