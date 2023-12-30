#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <napi.h>
#include <thread>
#include <future>
#include "worker.h"


class MergeSort : public Napi::ObjectWrap<MergeSort> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    MergeSort(const Napi::CallbackInfo& info);
    Napi::Value bubblesortAsync(const Napi::CallbackInfo& info);
    [[nodiscard]] static std::vector<double> arrayToVector( Napi::Array array);
    [[nodiscard]] static Napi::Array vectorToArray(Napi::Env &env, std::vector<double>vec);
   void mergeSort(std::vector<std::string>& arr, int left, int right);
   void merge(std::vector<std::string>& arr, int left, int mid, int right);
   bool compare(const std::string& a, const std::string& b);
private:
    Napi::Value bubblesort(const Napi::CallbackInfo& info);
     std::vector<std::string> data_;

};

#endif
