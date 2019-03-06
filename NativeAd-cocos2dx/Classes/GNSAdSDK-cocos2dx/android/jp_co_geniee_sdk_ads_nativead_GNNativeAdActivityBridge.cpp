#include "cocos2d.h"
#include "jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge.h"
#include <vector>
#include "../CCGNSNativeAdRequest.h"

using GNSAdSDK::CCGNSNativeAdRequest;
using GNSAdSDK::CCGNSNativeAd;

extern "C" {
    JNIEXPORT void JNICALL Java_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge_onNativeAdsLoaded(JNIEnv *env, jclass clazz, jobjectArray jnativeAds)
    {
        std::vector<GNSAdSDK::CCGNSNativeAd*> nativeAds;
        CCGNSNativeAdRequestDelegate* listener = CCGNSNativeAdRequest::getDelegate();

        if (listener != NULL) {
            int cntNativeAd = env->GetArrayLength(jnativeAds);
            for (int i = 0; i < cntNativeAd; i++)
            {
                jobject jnativeAdElement = env->GetObjectArrayElement(jnativeAds, i);
                jclass jnativeAd = env->FindClass("jp/co/geniee/sdk/ads/nativead/GNNativeAd");
                GNSAdSDK::CCGNSNativeAd* nativeAd = GNSAdSDK::CCGNSNativeAd::create();
                nativeAd->zoneID = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "zoneID", "Ljava/lang/String;"))
                    , 0);
                nativeAd->advertiser = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "advertiser", "Ljava/lang/String;"))
                    , 0);
                nativeAd->title = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "title", "Ljava/lang/String;"))
                    , 0);
                nativeAd->description = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "description", "Ljava/lang/String;"))
                    , 0);
                nativeAd->cta = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "cta", "Ljava/lang/String;"))
                    , 0);
                nativeAd->icon_aspectRatio =
                    env->GetDoubleField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "icon_aspectRatio", "D"));
                nativeAd->icon_url = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "icon_url", "Ljava/lang/String;"))
                    , 0);
                nativeAd->icon_height =
                    env->GetIntField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "icon_height", "I"));
                nativeAd->icon_width =
                    env->GetIntField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "icon_width", "I"));
                nativeAd->screenshots_aspectRatio =
                    env->GetDoubleField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "screenshots_aspectRatio", "D"));
                nativeAd->screenshots_url = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "screenshots_url", "Ljava/lang/String;"))
                    , 0);
                nativeAd->screenshots_height =
                    env->GetIntField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "screenshots_height", "I"));
                nativeAd->screenshots_width =
                    env->GetIntField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "screenshots_width", "I"));
                nativeAd->app_appName = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "app_appName", "Ljava/lang/String;"))
                    , 0);
                nativeAd->app_appid = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "app_appid", "Ljava/lang/String;"))
                    , 0);
                nativeAd->app_rating =
                    env->GetDoubleField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "app_rating", "D"));
                nativeAd->app_storeURL = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "app_storeURL", "Ljava/lang/String;"))
                    , 0);
                nativeAd->app_targetAge = env->GetStringUTFChars(
                    (jstring)env->GetObjectField(jnativeAdElement,
                    env->GetFieldID(jnativeAd, "app_targetAge", "Ljava/lang/String;"))
                    , 0);
                nativeAd->optout_text = env->GetStringUTFChars(
                        (jstring)env->GetObjectField(jnativeAdElement,
                                                     env->GetFieldID(jnativeAd, "optout_text", "Ljava/lang/String;"))
                        , 0);
                nativeAd->optout_image_url = env->GetStringUTFChars(
                        (jstring)env->GetObjectField(jnativeAdElement,
                                                     env->GetFieldID(jnativeAd, "optout_image_url", "Ljava/lang/String;"))
                        , 0);
                nativeAd->optout_url = env->GetStringUTFChars(
                        (jstring)env->GetObjectField(jnativeAdElement,
                                                     env->GetFieldID(jnativeAd, "optout_url", "Ljava/lang/String;"))
                        , 0);

                nativeAds.push_back(nativeAd);
            }
            listener->onNativeAdsLoaded(nativeAds);
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge_onNativeAdsFailedToLoad(JNIEnv *env, jclass clazz)
    {
        CCGNSNativeAdRequestDelegate* listener = CCGNSNativeAdRequest::getDelegate();
        if (listener != NULL) {
            listener->onNativeAdsFailedToLoad();
        }
    }
    
    JNIEXPORT bool JNICALL Java_jp_co_geniee_sdk_ads_nativead_GNNativeAdActivityBridge_onShouldStartInternalBrowserWithClick(JNIEnv *env, jclass clazz, jstring url)
    {
        bool flag = false;
        const char* utfurl = env->GetStringUTFChars(url, 0);
        CCGNSNativeAdRequestDelegate* listener = CCGNSNativeAdRequest::getDelegate();
        if (listener != NULL) {
            flag = listener->onShouldStartInternalBrowserWithClick(utfurl);
        }
        env->ReleaseStringUTFChars(url, utfurl);
        return flag;
    }
    
}
