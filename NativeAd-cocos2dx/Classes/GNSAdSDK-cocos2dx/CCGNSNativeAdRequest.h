//
//  CCGNNativeAdRequest.h
//  GNSAdSDK
//

#ifndef CCGNNativeAdRequest_h
#define CCGNNativeAdRequest_h

#include "cocos2d.h"
#include "CCGNSNativeAd.h"

    /// The Delegate for receiving state change messages from CCGNNativeAdRequest.
    class CCGNSNativeAdRequestDelegate
    {
    public:

        /// Tells the delegate that a native ad was received.
        virtual void onNativeAdsLoaded(std::vector<GNSAdSDK::CCGNSNativeAd *> nativeAds) = 0;
        
        /// Tells the delegate that the native ad failed to load.
        virtual void onNativeAdsFailedToLoad() = 0;

        /// Tells the delegate that the native ad shoud start internal browser with click.
        virtual bool onShouldStartInternalBrowserWithClick(const char* landingURL) = 0;
    };

namespace GNSAdSDK {

    /// The CCGNNativeAdRequest class is used for requesting and presenting native ad.
    class CCGNSNativeAdRequest
    {
    public:
        /// Initialize NativeAd SDK instance.
        static void initialize(const char* zoneId);

        /// Fetch a native ad.
        static void loadAds();

        // Fetch multiple native ads.
        static void multiLoadAds();

        /// Set the delegate for receiving native notifications.
        static void setDelegate(CCGNSNativeAdRequestDelegate* delegate);

        /// Get the delegate for receiving native notifications.
        static CCGNSNativeAdRequestDelegate* getDelegate();

        /// Dispose NativeAd SDK resources.
        static void dispose();

        /// Detach delegate for receiving native notifications.
        static void detachDelegate();
    };
    
}

#endif /* CCGNNativeAdRequest_h */
