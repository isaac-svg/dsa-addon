#ifndef STACK_H
#define STACK_H

#include <napi.h>
#include <stack>

class Stack : public Napi::ObjectWrap<Stack> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Stack(const Napi::CallbackInfo& info);

private:
    std::stack<std::string> stack_;

    Napi::Value Push(const Napi::CallbackInfo& info);
    Napi::Value Pop(const Napi::CallbackInfo& info);
    Napi::Value Top(const Napi::CallbackInfo& info);
    Napi::Value Size(const Napi::CallbackInfo& info);
    Napi::Value IsEmpty(const Napi::CallbackInfo& info);
};

#endif // STACK_H
