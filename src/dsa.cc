#include "dsa.h"


namespace {

Napi::Object RegisterModule(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    LinkedList::Init(env, exports);
    linkedlist_pointer::LinkedList::Init(env, exports);
    //   Database::Init(env, exports);
    // Statement::Init(env, exports);
    // Backup::Init(env, exports);
        return exports;
}


}


NODE_API_MODULE(addon, RegisterModule)

// Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    
//     LinkedList::Init(env, exports);
//     // linkedlist_pointer::LinkedList::Init(env, exports);
//     return exports;
// }

// Napi::Object MODULE_NAME(Napi::Env env, Napi::Object exports) {
//   return InitAll(env, exports);
// }

// NODE_API_MODULE(NODE_GYP_MODULE_NAME, MODULE_NAME)