//
//  CCGNSNativeAdReqIOS.m
//  NativeAd-cocos2dx-mobile
//
//  Created by Nguyen Duy Long on 11/1/18.
//

#import "CCGNSNativeAdReqIOS.h"
#import "../CCGNSNativeAdRequest.h"
#import "../CCGNSNativeAd.h"
#import <GNAdSDK/GNNativeAd.h>
#import <GNAdSDK/GNNativeAdRequest.h>

@implementation CCGNSNativeAdReqIOS

GNNativeAdRequest *nativeAdRequest = [[GNNativeAdRequest alloc] init];

- (void)setDelegate:(CCGNSNativeAdRequestDelegate *)delegate
{
    _delegate = delegate;
}

- (CCGNSNativeAdRequestDelegate *)getDelegate
{
    return _delegate;
}

- (void)initialize:(NSString *)zoneId
{
    if (nativeAdRequest == NULL) {
        nativeAdRequest = [[GNNativeAdRequest alloc] init];
    }
    
    [nativeAdRequest setGNAdlogPriority:GNLogPriorityInfo];
    [nativeAdRequest initWithID:zoneId];
    nativeAdRequest.delegate = self;
}

- (void)loadAds
{
    if (nativeAdRequest != NULL) {
        [nativeAdRequest loadAds];
    }
}

- (void)multiLoadAds
{
    if (nativeAdRequest != NULL) {
        [nativeAdRequest multiLoadAds];
    }
}

- (void)dispose
{
    if (_delegate != NULL) {
        _delegate = NULL;
    }
    
    [nativeAdRequest release];
    nativeAdRequest = NULL;
}

- (void)detachDelegate
{
    if (_delegate != NULL) {
        _delegate = NULL;
    }
}

#pragma GNNativeAdRequestDelegate

- (void)nativeAdRequest:(GNNativeAdRequest *)request didFailToReceiveAdsWithError:(NSError *)error {
    
    if (_delegate != NULL) {
        _delegate->onNativeAdsFailedToLoad();
    }
}

- (void)nativeAdRequestDidReceiveAds:(NSArray *)nativeAds {
    
    std::vector<GNSAdSDK::CCGNSNativeAd *> cocosNativeAds;
    
    for (GNNativeAd *nativeAd in nativeAds) {
        
        GNSAdSDK::CCGNSNativeAd *cocosNativeAd = GNSAdSDK::CCGNSNativeAd::create();
        
        cocosNativeAd->from(nativeAd);
        
        cocosNativeAds.push_back(cocosNativeAd);
    }
    
    if (_delegate != NULL) {
        _delegate->onNativeAdsLoaded(cocosNativeAds);
    }
    
}

@end
