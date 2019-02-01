//
//  MSGVAViewController.h
//  MediaSDK
//
//  Created by 市村 有貴江 on 2018/06/06.
//  Copyright © 2018年 市村 有貴江. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MSVideoAdManager.h"

@protocol AdCloseDelegate <NSObject>
- (void) onClose;
@end

@interface MSGVAViewController : UIViewController <MSVideoAdDelegate>
{
    CGFloat viewOriginX;
    CGFloat viewOriginY;
    CGFloat viewWidth;
    CGFloat viewHeight;
    __weak id<MSVideoAdDelegate> delegate;
    __weak id<AdCloseDelegate> closeDelegate;
}

@property MSVideoAdManager* adManager;
@property UIView* adView;
@property UIButton* closeButton;
@property UIImage* closeImage;

@property NSString* m_id;
@property NSString* media_user_id;
@property NSString* placement;
@property NSString* sdk_token;
@property bool mute;
@property bool volumeButtonVisiblity;

- (void) setDelegate:(id<MSVideoAdDelegate>)d;
- (void) setCloseDelegate:(id<AdCloseDelegate>)d;
- (void) removeDelegate;
- (void) loadAd ;
- (bool) isReady;

@end
