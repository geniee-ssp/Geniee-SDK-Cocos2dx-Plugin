#include <jni.h>

#ifndef _Included_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge
#define _Included_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge

extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge_onNativeAdsLoaded
    (JNIEnv *, jclass, jobjectArray);
    JNIEXPORT void JNICALL Java_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge_onNativeAdsFailedToLoad
    (JNIEnv *, jclass);
    JNIEXPORT bool JNICALL Java_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge_onShouldStartInternalBrowserWithClick
    (JNIEnv *, jclass, jstring);

}

#endif
