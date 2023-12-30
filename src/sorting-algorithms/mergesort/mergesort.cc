#include "mergesort.h"
#include "worker.h"
#include <vector>
#include <iostream>
#include <algorithm>

Napi::Object MergeSort::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "MergeSort", {
        // InstanceMethod("sort", &MergeSort::bubblesort),
        InstanceMethod("bubbleSort", &MergeSort::bubblesortAsync),
    });

    exports.Set("MergeSort", func);
    return exports;
}

MergeSort::MergeSort(const Napi::CallbackInfo& info) : Napi::ObjectWrap<MergeSort>(info) {
}



Napi::Value MergeSort::bubblesort(const Napi::CallbackInfo& info) {
    
      Napi::Env env = info.Env();

   

    if (info[0].IsFunction()){
        // will sort by comparator
    std::sort(data_.begin(), data_.end());
    }else{
        //  std::sort(data_.begin(), data_.end());
            mergeSort(data_, 0, data_.size() - 1);
    }

    Napi::Array resultArray = Napi::Array::New(env, data_.size());
    for (size_t i = 0; i < data_.size(); ++i) {
        resultArray.Set(i, Napi::Number::New(env, data_[i]));
    }
    return resultArray;
}

void MergeSort::merge(std::vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void  MergeSort::mergeSort(std::vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// async

Napi::Value MergeSort::bubblesortAsync(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // take arg1{array} , arg2{function || null}

    // check if arg1 is an array type
    if (!info[0].IsArray()){
        Napi::Error::New(env,"Expected an array as the first argument");
        return env.Null();
    }

     // check if arg2 is a number
     


    //  cast the argument to a napi array
    Napi::Array array = info[0].As<Napi::Array>();

    //  perform async operation
    MergeSortWorker* worker = new MergeSortWorker(env, array);
    worker->Queue();
    // return the promise
    return worker->GetPromise();


}
