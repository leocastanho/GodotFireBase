#import <GoogleMobileAds/GADInterstitial.h>
#import "app_delegate.h"

@interface GodotFirebaseInterstitialAd: UIViewController <GADInterstitialDelegate> {
    GADInterstitial *interstitial;
    int script_id;
}

- (void) init:(NSDictionary*)config: (int)script_id;
- (void) load;
- (void) show;

@end
