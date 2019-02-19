
#import "app_delegate.h"
#import <GoogleMobileAds/GADRewardBasedVideoAdDelegate.h>

@interface GodotFirebaseRewardedVideo: UIViewController <GADRewardBasedVideoAdDelegate> {
    NSString* ad_id;
    int script_id;
}

- (void) init:(NSDictionary*)config_: (int)script_id_;
- (void) load;
- (void) show;

@end
