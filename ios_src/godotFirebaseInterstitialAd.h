#import <GoogleMobileAds/GADInterstitial.h>
#import "app_delegate.h"

@interface GodotFirebaseInterstitialAd: UIViewController <GADInterstitialDelegate> {
    GADInterstitial *interstitial;
    NSDictionary* config;
    NSString* ad_id;
    int script_id;
}

- (void) init:(NSDictionary*)config_: (int)script_id_;
- (void) load;
- (void) show;

@end
