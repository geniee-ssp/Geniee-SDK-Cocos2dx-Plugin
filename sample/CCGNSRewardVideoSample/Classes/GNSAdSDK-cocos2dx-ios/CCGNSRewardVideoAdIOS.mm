//
//  CCGNSRewardVideoAdIOS.mm
//  GNSAdSDK
//

#include "CCGNSRewardVideoAdIOS.h"
#include "CCGNSRewardVideoAd.h"

#import <GNAdSDK/GNSRewardVideoAd.h>
#import <GNAdSDK/GNSRequest.h>
#import <GNAdSDK/GNSAdReward.h>
#import <GNAdSDK/GNSRewardVideoAdDelegate.h>

@interface CCGNSRewardVideoAdIOS() <GNSRewardVideoAdDelegate>

@end

@implementation CCGNSRewardVideoAdIOS

static CCGNSRewardVideoAdIOS *sharedCCGNSRewardVideoAdIOS = nil;

+ (CCGNSRewardVideoAdIOS*) sharedInstance
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedCCGNSRewardVideoAdIOS = [[CCGNSRewardVideoAdIOS alloc] init];
        [GNSRewardVideoAd sharedInstance].delegate = sharedCCGNSRewardVideoAdIOS;
    });
    return sharedCCGNSRewardVideoAdIOS;
}

- (void) setDelegate:(CCGNSRewardVideoAdDelegate*) delegate
{
    _delegate = delegate;
}

- (CCGNSRewardVideoAdDelegate *)getDelegate
{
    return _delegate;
}

- (void)setZoneId:(NSString *)zoneId
{
    _zoneId = zoneId;
}

- (void) loadRequest
{
    GNSRequest *request = [GNSRequest request];
    //request.geoLocationEnable = NO;
    //request.GNAdlogPriority = GNLogPriorityInfo;
    [[GNSRewardVideoAd sharedInstance] loadRequest:request
                                        withZoneID:_zoneId];
}

- (bool)canShow
{
    return [[GNSRewardVideoAd sharedInstance] canShow];
}

- (void)show
{
    if ([[GNSRewardVideoAd sharedInstance] canShow]) {
        [[GNSRewardVideoAd sharedInstance] show:[CCGNSRewardVideoAdIOS getRootViewController]];
    }
}

+ (UIViewController *)getRootViewController{
    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    if (window == nil) {
        window = [[UIApplication sharedApplication].windows objectAtIndex:0];
    }
    return window.rootViewController;
}

+ (const char *)NSString_to_charstr:(NSString *)str{
    return (char*)[str UTF8String];
}

- (void)dispose
{
    _delegate = nil;

    [sharedCCGNSRewardVideoAdIOS release];
    sharedCCGNSRewardVideoAdIOS = nil;
    
}

- (void)detachDelegate
{
    _delegate = nil;
}

#pragma mark - GNSRewardVideoAdDelegate delegate

/// Tells the delegate that the reward video ad failed to load.
- (void)rewardVideoAd:(GNSRewardVideoAd *)rewardVideoAd
didFailToLoadWithError:(NSError *)error
{
    NSLog(@"[INFO]CCGNSRewardVideoAdIOS: didFailToLoadWithError: %@", [error localizedDescription]);
    if(_delegate != NULL){
        _delegate->didFailToLoadWithError([CCGNSRewardVideoAdIOS NSString_to_charstr:[error localizedDescription]]);
    }
}

/// Tells the delegate that a reward video ad was received.
- (void)rewardVideoAdDidReceiveAd:(GNSRewardVideoAd *)rewardVideoAd
{
    NSLog(@"[INFO]CCGNSRewardVideoAdIOS: rewardVideoAdDidReceiveAd");
    if(_delegate != NULL){
        _delegate->rewardVideoAdDidReceiveAd();
    }
}

/// Tells the delegate that the reward video ad started playing.
- (void)rewardVideoAdDidStartPlaying:(GNSRewardVideoAd *)rewardVideoAd
{
    NSLog(@"[INFO]CCGNSRewardVideoAdIOS: rewardVideoAdDidStartPlaying");
    if(_delegate != NULL){
        _delegate->rewardVideoAdDidStartPlaying();
    }
}


/// Tells the delegate that the reward video ad closed.
- (void)rewardVideoAdDidClose:(GNSRewardVideoAd *)rewardVideoAd
{
    NSLog(@"[INFO]CCGNSRewardVideoAdIOS: rewardVideoAdDidClose");
    if(_delegate != NULL){
        _delegate->rewardVideoAdDidClose();
    }
}

/// Tells the delegate that the reward video ad has rewarded the user.
- (void)rewardVideoAd:(GNSRewardVideoAd *)rewardVideoAd
didRewardUserWithReward:(GNSAdReward *)reward
{
    NSLog(@"[INFO]CCGNSRewardVideoAdIOS: didRewardUserWithReward");
    if(_delegate != NULL){
        _delegate->didRewardUserWithReward([CCGNSRewardVideoAdIOS NSString_to_charstr:reward.type], [reward.amount doubleValue]);
    }
}

@end

