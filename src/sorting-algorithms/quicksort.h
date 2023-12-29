#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <napi.h>
#include <thread>
#include <future>


class QuickSort : public Napi::ObjectWrap<QuickSort> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    QuickSort(const Napi::CallbackInfo& info);
    Napi::Value quicksortAsync(const Napi::CallbackInfo& info);
    [[nodiscard]] static std::vector<double> arrayToVector( Napi::Array array);
    [[nodiscard]] static Napi::Array vectorToArray(Napi::Env &env, std::vector<double>vec);
   
private:
    Napi::Value quicksort(const Napi::CallbackInfo& info);
     std::vector<double> data_;

};

#endif
