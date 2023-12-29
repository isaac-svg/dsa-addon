#include "quicksort.h"
#include "quicksortasyncworker.h"
#include <vector>
#include <iostream>
#include <algorithm>

Napi::Object QuickSort::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "QuickSort", {
        InstanceMethod("sort", &QuickSort::quicksort),
        InstanceMethod("quicksortAsync", &QuickSort::quicksortAsync),
    });

    exports.Set("QuickSort", func);
    return exports;
}

QuickSort::QuickSort(const Napi::CallbackInfo& info) : Napi::ObjectWrap<QuickSort>(info) {
}



Napi::Value QuickSort::quicksort(const Napi::CallbackInfo& info) {
    
      Napi::Env env = info.Env();

   

    if (info[0].IsFunction()){
    std::sort(data_.begin(), data_.end());
    }else{
         std::sort(data_.begin(), data_.end());
    }

    Napi::Array resultArray = Napi::Array::New(env, data_.size());
    for (size_t i = 0; i < data_.size(); ++i) {
        resultArray.Set(i, Napi::Number::New(env, data_[i]));
    }
    return resultArray;
}


// async

 Napi::Array QuickSort::vectorToArray(Napi::Env &env, std::vector<double> vec){
    unsigned int length = vec.size();

    Napi::Array array = Napi::Array::New(env, length);
    for (size_t i = 0; i < length; i++)
    {
        array.Set(i, vec[i]);
    }
    
    return array;
 }

 std::vector<double> QuickSort::arrayToVector(Napi::Array array){

    unsigned int length = array.Length();
    std::vector<double> data(length);
    for (size_t i = 0; i < length; i++)
    {
        data[i] = array.Get(i).As<Napi::Number>().DoubleValue();
    }
    
    return data;
}


Napi::Value QuickSort::quicksortAsync(const Napi::CallbackInfo& info) {
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
    // Napi::Function comparator = info[1].As<Napi::Function>();

 
    //  perform async operation
    QuickSortAsync* worker = new QuickSortAsync(env, array);
    worker->Queue();
    // return the promise
    return worker->GetPromise();


}
