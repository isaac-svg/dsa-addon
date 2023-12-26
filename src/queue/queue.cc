#include "queue.h"
#include <iostream>
Napi::FunctionReference Queue::constructor;

Napi::Object Queue::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "Queue", {
        InstanceMethod("enqueue", &Queue::Enqueue),
        InstanceMethod("dequeue", &Queue::Dequeue),
        InstanceMethod("size", &Queue::Size),
        InstanceMethod("isEmpty", &Queue::IsEmpty),
        InstanceMethod("peek", &Queue::peek),
        InstanceMethod("back", &Queue::back),


    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("Queue", func);
    return exports;
}

Queue::Queue(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Queue>(info) {
  // 
}

Napi::Value Queue::Enqueue(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1 ) {
        Napi::TypeError::New(env, "Expected a single Arguement").ThrowAsJavaScriptException();
        return env.Null();
    }

    queue_.push(info[0].As<Napi::String>().ToString().Utf8Value());
   
    
    return env.Undefined();
}

 Napi::Value Queue::peek(const Napi::CallbackInfo& info){
      Napi::Env env = info.Env();

       if (queue_.empty()) {
        return env.Null();
    }
    auto value = queue_.front();


    return Napi::Value::From(env, value);
 }

 Napi::Value Queue::back(const Napi::CallbackInfo& info){
      Napi::Env env = info.Env();

       if (queue_.empty()) {
        return env.Null();
    } 

    return Napi::Value::From(env, (queue_.back()));
 }

Napi::Value Queue::Dequeue(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (queue_.empty()) {
        return env.Null();
    }

    std::string frontValue = queue_.front();
    queue_.pop();
    return Napi::Value::From(env, frontValue);
}

Napi::Value Queue::Size(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, queue_.size());
}

Napi::Value Queue::IsEmpty(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Boolean::New(env, queue_.empty());
}
