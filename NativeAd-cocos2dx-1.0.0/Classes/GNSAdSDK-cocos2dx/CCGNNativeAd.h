#ifndef CCGNNativeAd_h
#define CCGNNativeAd_h
#include "cocos2d.h"
namespace GNSAdSDK {
    class CCGNNativeAd
    {
    public:
        const char* zoneID = "";
        const char* advertiser = "";
        const char* title = "";
        const char* description = "";
        const char* cta = "";
        double icon_aspectRatio = 0.0D;
        const char* icon_url = "";
        int icon_height = 0;
        int icon_width = 0;
        double screenshots_aspectRatio = 0.0D;
        const char* screenshots_url = "";
        int screenshots_height = 0;
        int screenshots_width = 0;
        const char* app_appName = "";
        const char* app_appid = "";
        double app_rating = 0.0D;
        const char* app_storeURL = "";
        const char* app_targetAge = "";
        static CCGNNativeAd* create();
        void onTrackingImpression();
        void onTrackingClick();
    };
}
#endif
