#include "quicksort.h"
#include <vector>
#include <algorithm>

Napi::Object QuickSort::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "QuickSort", {
        InstanceMethod("sort", &QuickSort::quicksort)
    });

    exports.Set("QuickSort", func);
    return exports;
}

QuickSort::QuickSort(const Napi::CallbackInfo& info) : Napi::ObjectWrap<QuickSort>(info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "Expected an array as the first argument").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array array = info[0].As<Napi::Array>();
    uint32_t length = array.Length();
    data_.resize(length);

    for (uint32_t i = 0; i < length; ++i) {
        Napi::Value element = array.Get(i);
        if (!element.IsNumber()) {
            Napi::TypeError::New(env, "Array elements must be numbers").ThrowAsJavaScriptException();
            return;
        }
        data_[i] = element.As<Napi::Number>().DoubleValue();
    }
}

Napi::Value QuickSort::quicksort(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1 || !info[0].IsFunction()) {
        Napi::TypeError::New(env, "Expected a comparator function").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::sort(data_.begin(), data_.end(), [&env, &info](const double& a, const double& b) {
        Napi::Function comparator = info[0].As<Napi::Function>();
        Napi::Value result = comparator.Call( { Napi::Number::New(env, a), Napi::Number::New(env, b) });
        return result.ToBoolean().Value();
    });

    Napi::Array resultArray = Napi::Array::New(env, data_.size());
    for (size_t i = 0; i < data_.size(); ++i) {
        resultArray.Set(i, Napi::Number::New(env, data_[i]));
    }

    return resultArray;
}