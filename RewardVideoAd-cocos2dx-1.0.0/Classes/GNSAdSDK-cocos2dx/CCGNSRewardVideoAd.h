//
//  CCGNSRewardVideoAd.h
//  GNSAdSDK
//

#ifndef CCGNSRewardVideoAd_h
#define CCGNSRewardVideoAd_h

#include "cocos2d.h"

    /// The Delegate for receiving state change messages from CCGNSRewardVideoAd.
    class CCGNSRewardVideoAdDelegate
    {
    public:

        /// Tells the delegate that a reward video ad was received.
        virtual void rewardVideoAdDidReceiveAd() = 0;
        
        /// Tells the delegate that the reward video ad failed to load.
        virtual void didFailToLoadWithError(const char* errorMsg) = 0;

        /// Tells the delegate that the reward video ad started playing.
        virtual void rewardVideoAdDidStartPlaying() = 0;

        /// Tells the delegate that the reward video ad closed.
        virtual void rewardVideoAdDidClose() = 0;

        /**
         Tells the delegate that the reward video ad has rewarded the user.
         @param const char* (rewardType) Type of the reward
         @param double (rewardAmount) Amount rewarded to the user
         */
        virtual void didRewardUserWithReward(const char* rewardType, double rewardAmount) = 0;
    };

namespace GNSAdSDK {

    /// The CCGNSRewardVideoAd class is used for requesting and presenting reward video ad.
    class CCGNSRewardVideoAd
    {
    public:
        /// Initialize RewardVideoAd SDK instance.
        static void initialize(const char* zoneId);

        /// Fetch a reward video ad.
        static void loadRequest();

        /// Set the delegate for receiving video notifications.
        static void setDelegate(CCGNSRewardVideoAdDelegate* delegate);

        /// Get the delegate for receiving video notifications.
        static CCGNSRewardVideoAdDelegate* getDelegate();

        /// Indicates if the receiver is ready to show.
        static bool canShow();

        /// Presents the reward video ad.
        static void show();

        /// Dispose RewardVideoAd SDK resources.
        static void dispose();

        /// Detach delegate for receiving video notifications.
        static void detachDelegate();
    };
    
}

#endif /* CCGNSRewardVideoAd_h */
