
#include "godotFirebase.h"
#import "app_delegate.h"

#if VERSION_MAJOR == 3
#define CLASS_DB ClassDB
#else
#define CLASS_DB ctTypeDB
#endif

//GADInterstitial *interstitial = NULL;
NSMutableDictionary *config = NULL;

GodotFirebase::GodotFirebase() {
}

GodotFirebase::~GodotFirebase() {
}

void GodotFirebase::initWithJson(const String &json, const int script_id) {
    NSLog(@"Initializing firebase from objective-C...");
    NSLog(@"json = %@", [NSString stringWithCString:json.utf8().get_data() encoding: NSUTF8StringEncoding]);
    
    [FIRApp configure];
    
    config = [NSJSONSerialization JSONObjectWithData:[[NSString stringWithCString:json.utf8().get_data() encoding: NSUTF8StringEncoding]  dataUsingEncoding:NSUTF8StringEncoding] options:kNilOptions error:nil];
                                                      
    interstitialAd = [GodotFirebaseInterstitialAd alloc];
    [interstitialAd init: config: script_id];
    
    // NSLog(@"Config parsed from objective-c, ads and interstitialadid are:");
    // NSLog(config[@"Ads"]);
    // NSLog(config[@"Ads"][@"InterstitialAdId"]);
    
}

/*void GodotRateIt::ask_and_rate(const String &message, const String &positive_button_text, const String &negative_button_text, const String &app_id) {
    do_ios_rate(app_id);
}

void GodotRateIt::rate(const String &url_prefix, const String &url_prefix_fallback, const String &id_format, const String &app_id) {
    do_ios_rate(app_id); TODO remove
}*/

void GodotFirebase::load_interstitial() {
    NSLog(@"load_insterstitial from ObjC");
    [interstitialAd load];
    
}

void GodotFirebase::show_interstitial_ad() {
    NSLog(@"show_instertitial_ad from ObjC");
    [interstitialAd show];
    
}

void GodotFirebase::_bind_methods() {
    CLASS_DB::bind_method("initWithJson", &GodotFirebase::initWithJson);
    
    // Admob functions
    CLASS_DB::bind_method("load_interstitial", &GodotFirebase::load_interstitial);
    CLASS_DB::bind_method("show_interstitial_ad", &GodotFirebase::show_interstitial_ad);
    
    /*
     Admob related functions to be implemented:
     
    "show_interstitial_ad", "show_rewarded_video",
    "is_interstitial_loaded", "is_rewarded_video_loaded","load_rewarded_video",
    "load_interstitial"
     
     TODO remove
     */
}
