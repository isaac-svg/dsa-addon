#include "stack.h"

Napi::Object Stack::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "Stack", {
        InstanceMethod("push", &Stack::Push),
        InstanceMethod("pop", &Stack::Pop),
        InstanceMethod("top", &Stack::Top),
        InstanceMethod("size", &Stack::Size),
        InstanceMethod("isEmpty", &Stack::IsEmpty),
    });

    

    exports.Set("Stack", func);
    return exports;
}

Stack::Stack(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Stack>(info) {
    Napi::Env env = info.Env();
    if (info.Length() != 0) {
        Napi::TypeError::New(env, "Constructor does not accept any arguments").ThrowAsJavaScriptException();
    }
}

Napi::Value Stack::Push(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Expected a single argument").ThrowAsJavaScriptException();
        return env.Null();
    }

    stack_.push(info[0].As<Napi::String>().ToString().Utf8Value());
    return env.Undefined();
}

Napi::Value Stack::Pop(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (stack_.empty()) {
        return env.Null();
    }

    std::string top = stack_.top();
    stack_.pop();
    return Napi::Value::From(env, top);
}

Napi::Value Stack::Top(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (stack_.empty()) {
        return env.Null();
    }

    return Napi::Value::From(env, stack_.top());
}

Napi::Value Stack::Size(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, stack_.size());
}

Napi::Value Stack::IsEmpty(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Boolean::New(env, stack_.empty());
}
