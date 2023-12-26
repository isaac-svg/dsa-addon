#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <napi.h>

class QuickSort : public Napi::ObjectWrap<QuickSort> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    QuickSort(const Napi::CallbackInfo& info);

private:
    Napi::Value quicksort(const Napi::CallbackInfo& info);

    std::vector<double> data_;
};

#endif
