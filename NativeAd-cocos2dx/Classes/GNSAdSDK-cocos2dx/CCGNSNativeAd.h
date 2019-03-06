#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#ifndef CCGNNativeAd_h
#define CCGNNativeAd_h
#include "cocos2d.h"
namespace GNSAdSDK {
    class CCGNSNativeAd
    {
    public:
        const char* zoneID = "";
        const char* advertiser = "";
        const char* title = "";
        const char* description = "";
        const char* cta = "";
        double icon_aspectRatio = 0.0;
        const char* icon_url = "";
        int icon_height = 0;
        int icon_width = 0;
        double screenshots_aspectRatio = 0.0;
        const char* screenshots_url = "";
        int screenshots_height = 0;
        int screenshots_width = 0;
        const char* app_appName = "";
        const char* app_appid = "";
        double app_rating = 0.0;
        const char* app_storeURL = "";
        const char* app_targetAge = "";
        const char* optout_text = "";
        const char* optout_image_url = "";
        const char* optout_url = ""; 
        
        static CCGNSNativeAd* create();
        void onTrackingImpression();
        void onTrackingClick();
    };
}
#endif
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#ifndef CCGNSNativeAd_h
#define CCGNSNativeAd_h

#include <stdio.h>
#import <GNAdSDK/GNNativeAd.h>
#import <UIKit/UIKit.h>

//NS_ASSUME_NONNULL_BEGIN

namespace GNSAdSDK {
    class CCGNSNativeAd
    {
    private:
        GNNativeAd *_nativeAd;

        UIViewController *getRootViewController();
    public:

        const char* zoneID = "";
        const char* advertiser = "";
        const char* title = "";
        const char* description = "";
        const char* cta = "";
        double icon_aspectRatio = 0.0;
        const char* icon_url = "";
        int icon_height = 0;
        int icon_width = 0;
        double screenshots_aspectRatio = 0.0;
        const char* screenshots_url = "";
        int screenshots_height = 0;
        int screenshots_width = 0;
        const char* app_appName = "";
        const char* app_appid = "";
        double app_rating = 0.0;
        const char* app_storeURL = "";
        const char* app_targetAge = "";
        const char* optout_text = "";
        const char* optout_image_url = "";
        const char* optout_url = "";

        static CCGNSNativeAd *create();
        CCGNSNativeAd *from(GNNativeAd *nativeAd);
        void onTrackingImpression();
        void onTrackingClick();

    };
}

//NS_ASSUME_NONNULL_END
#endif
#endif
