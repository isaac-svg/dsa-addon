#include "linkedlist.h"
#include <iostream>
// namespace LinkedListAddon {
// using namespace LinkedListAddon;

Napi::Object LinkedList::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "LinkedList", {
        InstanceMethod("push", &LinkedList::Push),
        InstanceMethod("pop", &LinkedList::Pop),
        InstanceMethod("shift", &LinkedList::Shift),
        InstanceMethod("unshift", &LinkedList::Unshift),
        InstanceMethod("get", &LinkedList::Get),
        InstanceMethod("set", &LinkedList::Set),
        InstanceMethod("size", &LinkedList::Size),
        InstanceMethod("parse", &LinkedList::Parse),
        InstanceMethod("stringify", &LinkedList::Stringify),
    });

    exports.Set("LinkedList", func);
    return exports;
}




LinkedList::LinkedList(const Napi::CallbackInfo& info) : Napi::ObjectWrap<LinkedList>(info) {}

Napi::Value LinkedList::Push(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Argument").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Value value = info[0];

    std::string stringValue = ValueToString(env, value);

    list_.push_back(stringValue);
    return value;
}

Napi::Value LinkedList::Pop(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (list_.empty()) {
        return env.Null();
    }

    std::string value = Napi::String::New(env, list_.back()).ToString().Utf8Value();
    list_.pop_back();

    Napi::Value parsedValue = StringToValue(env, value);
    return parsedValue;
}

Napi::Value LinkedList::Shift(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (list_.empty()) {
        return env.Null();
    }
    std::string value = list_.front();
    list_.erase(list_.begin());
    return Napi::Value::From(env, value);
}

Napi::Value LinkedList::Unshift(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    list_.insert(list_.begin(), ValueToString(env, info[0]));
    return env.Undefined();
}

Napi::Value LinkedList::Get(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint32_t index = info[0].As<Napi::Number>().Uint32Value();
    if (index >= list_.size()) {
        return env.Null();
    }
    int32_t idx =index;
    std::string retrievedValue = list_[idx];

   

    return Napi::Value::From(env, retrievedValue);
}

Napi::Value LinkedList::Set(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint32_t index = info[0].As<Napi::Number>().Uint32Value();
    if (index >= list_.size()) {
        return env.Null();
    }
    list_[index] = ValueToString(env, info[1]);
    return env.Undefined();
}

Napi::Value LinkedList::Size(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, list_.size());
}

std::string LinkedList::ValueToString(Napi::Env env, const Napi::Value& value) {
    std::stringstream ss;
    ss << value.ToString().Utf8Value();
    return ss.str();
}

Napi::Value LinkedList::StringToValue(Napi::Env env, const std::string& str) {
    return Napi::String::New(env, str);
}




  

Napi::Value LinkedList::Stringify(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::stringstream ss;
    ss << "[";

    for (size_t i = 0; i < list_.size(); ++i) {
        if (i != 0) {
            ss << ",";
        }
        ss << list_[i];
    }

    ss << "]";
    return Napi::String::New(env, ss.str());
}

Napi::Value LinkedList::Parse(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1 || !info[0].IsString()) {
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string str = info[0].As<Napi::String>().Utf8Value();
    std::vector<std::string> parsedList;

    //
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ',')) {
        parsedList.push_back(token);
    }

    // Assuming parsedList is a vector of strings
    list_ = parsedList;

    return Napi::Value::From(env, true);
}




// } // namespace LinkedListAddon




/**
 * Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    
    LinkedList::Init(env, exports);
    // linkedlist_pointer::LinkedList::Init(env, exports);
    return exports;
}

Napi::Object MODULE_NAME(Napi::Env env, Napi::Object exports) {
  return InitAll(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, MODULE_NAME)
// } // namespace LinkedListAddon

*/




