//
//  CCGNSNativeAdReqIOS.h
//  NativeAd-cocos2dx-mobile
//
//  Created by Nguyen Duy Long on 11/1/18.
//

#import <Foundation/Foundation.h>
#import <GNAdSDK/GNNativeAdRequest.h>
#include "../CCGNSNativeAdRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface CCGNSNativeAdReqIOS : NSObject <GNNativeAdRequestDelegate>
{
    CCGNSNativeAdRequestDelegate *_delegate;
}

- (void) setDelegate:(CCGNSNativeAdRequestDelegate*) delegate;

- (CCGNSNativeAdRequestDelegate *)getDelegate;

- (void)initialize:(NSString *)zoneId;

- (void)loadAds;

- (void)multiLoadAds;

- (void)dispose;

- (void)detachDelegate;

@end

NS_ASSUME_NONNULL_END
