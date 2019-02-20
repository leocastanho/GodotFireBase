#ifndef GODOT_FIREBASE_H
#define GODOT_FIREBASE_H

#include <version_generated.gen.h>

#include "reference.h"

#ifdef __OBJC__

#import "Firebase.h"

@class GodotFirebaseInterstitialAd;
typedef GodotFirebaseInterstitialAd *interstitialAdPtr;

@class GodotFirebaseRewardedVideo;
typedef GodotFirebaseRewardedVideo *rewardedVideoPtr;

@class GodotFirebaseAnalytics;
typedef GodotFirebaseAnalytics *analyticsPtr;

#else

typedef void *interstitialAdPtr;
typedef void *rewardedVideoPtr;
typedef void *analyticsPtr;

#endif


class GodotFirebase : public Reference {
    
#if VERSION_MAJOR == 3
    GDCLASS(GodotFirebase, Reference);
#else
    OBJ_TYPE(GodotFirebase, Reference);
#endif
    
    interstitialAdPtr interstitialAd;
    rewardedVideoPtr rewardedVideo;
    analyticsPtr analytics;
    
protected:
    // void do_ios_rate(const String &app_id); TODO remove
    static void _bind_methods();
    
public:
    void initWithJson(const String &json, const int script_id);
    
    void load_interstitial();
    void show_interstitial_ad();
    
    void load_rewarded_video();
    void show_rewarded_video();
    
    void setScreenName(const String &screen_name);
    void send_events(const String &event_name, const Dictionary& key_values);
    
    GodotFirebase();
    ~GodotFirebase();
};

#endif
