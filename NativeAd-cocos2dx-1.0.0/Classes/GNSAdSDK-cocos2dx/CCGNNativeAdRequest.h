//
//  CCGNNativeAdRequest.h
//  GNSAdSDK
//

#ifndef CCGNNativeAdRequest_h
#define CCGNNativeAdRequest_h

#include "cocos2d.h"
#include "CCGNNativeAd.h"

    /// The Delegate for receiving state change messages from CCGNNativeAdRequest.
    class CCGNNativeAdRequestDelegate
    {
    public:

        /// Tells the delegate that a native ad was received.
        virtual void onNativeAdsLoaded(std::vector<GNSAdSDK::CCGNNativeAd*> nativeAds) = 0;
        
        /// Tells the delegate that the native ad failed to load.
        virtual void onNativeAdsFailedToLoad() = 0;

        /// Tells the delegate that the native ad shoud start internal browser with click.
        virtual bool onShouldStartInternalBrowserWithClick(const char* landingURL) = 0;
    };

namespace GNSAdSDK {

    /// The CCGNNativeAdRequest class is used for requesting and presenting native ad.
    class CCGNNativeAdRequest
    {
    public:
        /// Initialize NativeAd SDK instance.
        static void initialize(const char* zoneId);

        /// Fetch a native ad.
        static void loadAds();

        /// Set the delegate for receiving native notifications.
        static void setDelegate(CCGNNativeAdRequestDelegate* delegate);

        /// Get the delegate for receiving native notifications.
        static CCGNNativeAdRequestDelegate* getDelegate();

        /// Dispose NativeAd SDK resources.
        static void dispose();

        /// Detach delegate for receiving native notifications.
        static void detachDelegate();
    };
    
}

#endif /* CCGNNativeAdRequest_h */
