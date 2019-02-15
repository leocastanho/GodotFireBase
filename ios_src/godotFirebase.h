#ifndef GODOT_FIREBASE_H
#define GODOT_FIREBASE_H

#include <version_generated.gen.h>

#include "reference.h"

#ifdef __OBJC__

#import "Firebase.h"
@class GodotFirebaseInterstitialAd;
typedef GodotFirebaseInterstitialAd *interstitialAdPtr;

#else

typedef void *interstitialAdPtr; // GodotFirebaseInterstitialAd

#endif


class GodotFirebase : public Reference {
    
#if VERSION_MAJOR == 3
    GDCLASS(GodotFirebase, Reference);
#else
    OBJ_TYPE(GodotFirebase, Reference);
#endif
    
    interstitialAdPtr interstitialAd;
    
protected:
    // void do_ios_rate(const String &app_id); TODO remove
    static void _bind_methods();
    
public:
    void initWithJson(const String &json, const int script_id);
    
    void load_interstitial();
    void show_interstitial_ad();
    
    // void ask_and_rate(const String &message, const String &positive_button_text, const String &negative_button_text, const String &app_id); TODO remove
    
    // void rate(const String &url_prefix, const String &url_prefix_fallback, const String &id_format, const String &app_id); TODO remove
    
    GodotFirebase();
    ~GodotFirebase();
};

#endif
