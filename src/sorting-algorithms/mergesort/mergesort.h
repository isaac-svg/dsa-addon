#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <napi.h>
#include <thread>
#include <future>


class MergeSort : public Napi::ObjectWrap<MergeSort> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    MergeSort(const Napi::CallbackInfo& info);
    Napi::Value bubblesortAsync(const Napi::CallbackInfo& info);
    [[nodiscard]] static std::vector<double> arrayToVector( Napi::Array array);
    [[nodiscard]] static Napi::Array vectorToArray(Napi::Env &env, std::vector<double>vec);
   void mergeSort(std::vector<double>& arr, int left, int right);
   void merge(std::vector<double>& arr, int left, int mid, int right);
private:
    Napi::Value bubblesort(const Napi::CallbackInfo& info);
     std::vector<double> data_;

};

#endif
