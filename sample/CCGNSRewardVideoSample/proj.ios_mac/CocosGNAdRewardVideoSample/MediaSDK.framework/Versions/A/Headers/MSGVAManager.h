//
//  MSGVAManager.h
//  MediaSDK
//
//  Created by 市村 有貴江 on 2018/06/06.
//  Copyright © 2018年 市村 有貴江. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MSVideoAdManager.h"
#import "MSGVAViewController.h"

@class MSGVAManager;

@protocol MSGVAVideoAdDelegate <NSObject>

- (void) onGVAReadyToPlayAd:(MSGVAManager*)msGVAManager;
- (void) onGVAFailedToReceiveAd:(MSGVAManager*)msGVAManager;
- (void) onGVAPlayStart:(MSGVAManager*)msGVAManager;
- (void) onGVAPlayEnd:(MSGVAManager*)msGVAManager;
- (void) onGVAAdClick:(MSGVAManager*)msGVAManager;
- (void) onGVAFailedToPlay:(MSGVAManager*)msGVAManager;
- (void) onGVAClose:(MSGVAManager*)msGVAManager;

@end

@interface MSGVAManager : NSObject <MSVideoAdDelegate, AdCloseDelegate>
{
    __weak id<MSGVAVideoAdDelegate> delegate;
}

@property MSGVAViewController* adViewController;

@property NSString* m_id;
@property NSString* media_user_id;
@property NSString* placement;
@property NSString* sdk_token;
@property bool mute;
@property bool volumeButtonVisiblity;

- (void) loadAd;
- (void) showAdView:(UIViewController*)viewController;
- (void) setDelegate:(id<MSGVAVideoAdDelegate>)d;
- (void) removeDelegate;
- (bool) isReady;

@end
