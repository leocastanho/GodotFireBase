#include "register_types.h"

#ifdef IPHONE_ENABLED
#include "ios_src/godotFirebase.h"
#endif

#include "crashlytics.h"
#include "core/print_string.h"
#include "core/ustring.h"

#include "core/engine.h"

crashlytics_context_t *crashlytics_context = NULL;
PrintHandlerList *phl = NULL;

void crashlytics_print_handler(void *p_this, const String &p_string, bool p_error) {
    // crashlytics_context_t *context = static_cast<crashlytics_context_t *>(p_this);
    // if (context)
    //     context->log(context, p_string.utf8().get_data());
    if (Engine::get_singleton()->has_singleton("FireBase")) {
        Engine::get_singleton()->get_singleton_object("FireBase")->call("crash_log", p_string);
    }
}

void register_GodotFireBase_types() {
#ifdef IPHONE_ENABLED
    Engine::get_singleton()->add_singleton(Engine::Singleton("FireBase", memnew(GodotFirebase)));
#endif

    crashlytics_context = crashlytics_init();
    phl = memnew(PrintHandlerList);
    phl->printfunc = crashlytics_print_handler;
    phl->userdata = static_cast<void *>(crashlytics_context);
    add_print_handler(phl);
}
void unregister_GodotFireBase_types() {
    if (crashlytics_context) {
        crashlytics_free(&crashlytics_context);
    }
    remove_print_handler(phl);
    memfree(phl);
}
