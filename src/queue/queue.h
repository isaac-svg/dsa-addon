#pragma once
#include <queue>
#include <napi.h>

class Queue : public Napi::ObjectWrap<Queue> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Queue(const Napi::CallbackInfo& info);

private:
    static Napi::FunctionReference constructor;
    Napi::Value Enqueue(const Napi::CallbackInfo& info);
    Napi::Value Dequeue(const Napi::CallbackInfo& info);
    Napi::Value Size(const Napi::CallbackInfo& info);
    Napi::Value IsEmpty(const Napi::CallbackInfo& info);
     Napi::Value peek(const Napi::CallbackInfo& info);
      Napi::Value back(const Napi::CallbackInfo& info);

    std::queue<std::string> queue_;
};
