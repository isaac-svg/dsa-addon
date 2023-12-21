#pragma once

#include <vector>
#include <napi.h>
#include <sstream>

// namespace LinkedListAddon {

class LinkedList : public Napi::ObjectWrap<LinkedList> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    LinkedList(const Napi::CallbackInfo& info);

    Napi::Value Push(const Napi::CallbackInfo& info);
    Napi::Value Pop(const Napi::CallbackInfo& info);
    Napi::Value Shift(const Napi::CallbackInfo& info);
    Napi::Value Unshift(const Napi::CallbackInfo& info);
    Napi::Value Get(const Napi::CallbackInfo& info);
    Napi::Value Set(const Napi::CallbackInfo& info);
    Napi::Value Size(const Napi::CallbackInfo& info);
  
    std::string ValueToString(Napi::Env env, const Napi::Value& value);
    Napi::Value StringToValue(Napi::Env env, const std::string& str);

    static std::string stringify(Napi::Env env, const Napi::Object& obj);
    static Napi::Value parse(Napi::Env env, const std::string& str);

    Napi::Value Stringify(const Napi::CallbackInfo& info);
    Napi::Value Parse(const Napi::CallbackInfo& info);
    Napi::Value toString(const Napi::CallbackInfo& info);
    private:
    std::vector<std::string> list_;

};


