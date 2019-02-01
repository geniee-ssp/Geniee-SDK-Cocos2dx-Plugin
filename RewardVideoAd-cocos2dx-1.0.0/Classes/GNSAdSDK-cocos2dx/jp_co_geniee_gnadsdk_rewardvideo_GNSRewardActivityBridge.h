#include <jni.h>

#ifndef _Included_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge
#define _Included_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge

extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_rewardVideoAdDidReceiveAd
    (JNIEnv *, jclass);
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_rewardVideoAdDidStartPlaying
    (JNIEnv *, jclass);
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_didRewardUserWithReward
    (JNIEnv *, jclass, jstring, double);
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_rewardVideoAdDidClose
    (JNIEnv *, jclass);
    JNIEXPORT void JNICALL Java_jp_co_geniee_gnadsdk_rewardvideo_GNSRewardActivityBridge_didFailToLoadWithError
    (JNIEnv *, jclass, jstring);

}

#endif
