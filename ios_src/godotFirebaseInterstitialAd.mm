#import "godotFirebaseInterstitialAd.h"
#include "reference.h"

@implementation GodotFirebaseInterstitialAd

- (void) init:(NSDictionary*)config: (int)script_id; {
    NSLog(@"Calling init from interstitial");
}

- (void) load; {
    NSLog(@"Calling load from interstitial");
    
    NSString *const kInterstitialAdUnitID = @"ca-app-pub-3940256099942544/4411468910";
    
    interstitial = [[GADInterstitial alloc]
                                     initWithAdUnitID:kInterstitialAdUnitID];
    interstitial.delegate = self;
    [interstitial loadRequest:[GADRequest request]];
}


- (void) show; {
    NSLog(@"Calling show from interstitial");
    
    if (interstitial.isReady) {
        NSLog(@"Insterstitial show is ready");
        [interstitial presentFromRootViewController:((AppDelegate *)[[UIApplication sharedApplication] delegate]).window.rootViewController];
    } else {
        NSLog(@"Interstitial show IS NOT ready");
    }
}

@end
