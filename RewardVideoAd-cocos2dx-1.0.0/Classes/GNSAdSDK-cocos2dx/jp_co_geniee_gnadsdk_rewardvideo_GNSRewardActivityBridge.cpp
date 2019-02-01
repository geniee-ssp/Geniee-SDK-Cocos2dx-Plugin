#include "cocos2d.h"
#include "jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge.h"
#include "CCGNSRewardVideoAd.h"

using GNSAdSDK::CCGNSRewardVideoAd;

extern "C" {
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_rewardVideoAdDidReceiveAd(JNIEnv *env, jclass clazz)
    {
        CCGNSRewardVideoAdDelegate* listener = CCGNSRewardVideoAd::getDelegate();
        if (listener != NULL) {
            listener->rewardVideoAdDidReceiveAd();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_rewardVideoAdDidStartPlaying(JNIEnv *env, jclass clazz)
    {
        CCGNSRewardVideoAdDelegate* listener = CCGNSRewardVideoAd::getDelegate();
        if (listener != NULL) {
            listener->rewardVideoAdDidStartPlaying();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_didRewardUserWithReward(JNIEnv *env, jclass clazz, jstring rewardType, double rewardAmount)
    {
        const char* type = env->GetStringUTFChars(rewardType, 0);
        CCGNSRewardVideoAdDelegate* listener = CCGNSRewardVideoAd::getDelegate();
        if (listener != NULL) {
            listener->didRewardUserWithReward(type, rewardAmount);
        }
        env->ReleaseStringUTFChars(rewardType, type);
    }
    
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_rewardVideoAdDidClose(JNIEnv *env, jclass clazz)
    {
        CCGNSRewardVideoAdDelegate* listener = CCGNSRewardVideoAd::getDelegate();
        if (listener != NULL) {
            listener->rewardVideoAdDidClose();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_didFailToLoadWithError(JNIEnv *env, jclass clazz, jstring errorMsg)
    {
        const char* msg = env->GetStringUTFChars(errorMsg, 0);
        CCGNSRewardVideoAdDelegate* listener = CCGNSRewardVideoAd::getDelegate();
        if (listener != NULL) {
            listener->didFailToLoadWithError(msg);
        }
        env->ReleaseStringUTFChars(errorMsg, msg);
    }
}
