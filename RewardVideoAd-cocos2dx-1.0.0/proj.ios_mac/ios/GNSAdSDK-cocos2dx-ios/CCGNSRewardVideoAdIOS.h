//
//  CCGNSRewardVideoAdIOS.h
//  GNSAdSDK
//

#ifndef CCGNSRewardVideoAdIOS_h
#define CCGNSRewardVideoAdIOS_h

class CCGNSRewardVideoAdDelegate;

@interface CCGNSRewardVideoAdIOS : NSObject
{
    CCGNSRewardVideoAdDelegate* _delegate;
    NSString *_zoneId;
}

+ (CCGNSRewardVideoAdIOS*) sharedInstance;

- (void) setDelegate:(CCGNSRewardVideoAdDelegate*) delegate;
- (CCGNSRewardVideoAdDelegate *)getDelegate;

- (void)setZoneId:(NSString *)zoneId;

- (void)loadRequest;

- (bool)canShow;

- (void)show;

- (void)dispose;

- (void)detachDelegate;


@end


#endif /* CCGNSRewardVideoAdIOS_h */
