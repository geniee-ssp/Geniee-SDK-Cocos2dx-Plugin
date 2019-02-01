#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

//
//  CCGNSRewardVideoAd.mm
//  GNSAdSDK
//

#pragma mark - cocos native plugin


#include "CCGNSRewardVideoAd.h"
#include "CCGNSRewardVideoAdIOS.h"

namespace GNSAdSDK {    
    void CCGNSRewardVideoAd::initialize(const char* zoneId)
    {
        [CCGNSRewardVideoAdIOS sharedInstance];
        [[CCGNSRewardVideoAdIOS sharedInstance] setZoneId:
         [NSString stringWithCString:zoneId encoding:NSUTF8StringEncoding]];
    }
    
    void CCGNSRewardVideoAd::loadRequest()
    {
        [[CCGNSRewardVideoAdIOS sharedInstance] loadRequest];
    }
    
    void CCGNSRewardVideoAd::setDelegate(CCGNSRewardVideoAdDelegate* delegate)
    {
        [[CCGNSRewardVideoAdIOS sharedInstance] setDelegate:delegate];
    }
    
    CCGNSRewardVideoAdDelegate* CCGNSRewardVideoAd::getDelegate()
    {
        return [[CCGNSRewardVideoAdIOS sharedInstance] getDelegate];
    }
    
    bool CCGNSRewardVideoAd::canShow()
    {
        return [[CCGNSRewardVideoAdIOS sharedInstance] canShow];
    }
    
    void CCGNSRewardVideoAd::show()
    {
        [[CCGNSRewardVideoAdIOS sharedInstance] show];
    }
    
    void CCGNSRewardVideoAd::dispose()
    {
        [[CCGNSRewardVideoAdIOS sharedInstance] dispose];
    }
    
    void CCGNSRewardVideoAd::detachDelegate()
    {
        [[CCGNSRewardVideoAdIOS sharedInstance] detachDelegate];
    }
    
}


#endif
