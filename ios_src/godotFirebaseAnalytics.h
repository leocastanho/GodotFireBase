#include "core/dictionary.h"
#import "app_delegate.h"

@interface GodotFirebaseAnalytics : NSObject {
}

- (void) init;
- (void) setScreenName: (NSString *) screen_name;
- (void) send_events: (NSString *) event_name: (Dictionary *)  key_values;

@end


