
#import "godotFirebaseAnalytics.h"
#include "reference.h"

#import "Firebase.h"

@implementation GodotFirebaseAnalytics

- (void) init:(NSDictionary*)config_: (int)script_id_; {
    NSLog(@"Calling init from analytics");
}

- (void) setScreenName: (NSString *) screen_name; {
    NSLog(@"Set screen name to %@", screen_name);
    
    [FIRAnalytics setScreenName:screen_name screenClass:nil];
    
}

- (void) send_events: (NSString *) event_name: (Dictionary *)  key_values; {
    NSLog(@"Sending analytics event");
    NSLog(@"Name: %@", event_name);
    // NSLog(@"Data: %@", key_values);
    
    // TODO send analytics to firebase
}


@end
