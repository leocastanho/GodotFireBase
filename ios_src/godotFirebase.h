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

#else

typedef void *interstitialAdPtr;
typedef void *rewardedVideoPtr;

#endif


class GodotFirebase : public Reference {
    
#if VERSION_MAJOR == 3
    GDCLASS(GodotFirebase, Reference);
#else
    OBJ_TYPE(GodotFirebase, Reference);
#endif
    
    interstitialAdPtr interstitialAd;
    rewardedVideoPtr rewardedVideo;
    
protected:
    // void do_ios_rate(const String &app_id); TODO remove
    static void _bind_methods();
    
public:
    void initWithJson(const String &json, const int script_id);
    
    void load_interstitial();
    void show_interstitial_ad();
    
    void load_rewarded_video();
    void show_rewarded_video();
    
    GodotFirebase();
    ~GodotFirebase();
};

#endif
