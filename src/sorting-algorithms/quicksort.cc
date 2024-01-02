#include "quicksort.h"
#include "quicksortasyncworker.h"
#include <vector>
#include <iostream>
#include <algorithm>

Napi::Object QuickSort::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "QuickSort", {
        InstanceMethod("sort", &QuickSort::quicksort),
        InstanceMethod("sortAsync", &QuickSort::quicksortAsync),
    });

    exports.Set("QuickSort", func);
    return exports;
}

QuickSort::QuickSort(const Napi::CallbackInfo& info) : Napi::ObjectWrap<QuickSort>(info) {
}



Napi::Value QuickSort::quicksort(const Napi::CallbackInfo& info) {
    
    Napi::Env env = info.Env();
    // get the array input
    Napi::Array array = info[0].As<Napi::Array>();
    // push the array elements to the container
    // arrayToVector(array);
    
 unsigned int length = array.Length();
    for (size_t i = 0; i < length; i++)
    {
        Napi::Value value = array.Get(i);

        if (value.IsString()){
            container.push_back(value.As<Napi::String>().Utf8Value());
            
        }
        else if(value.IsNumber()){
            container.push_back(value.As<Napi::Number>().Int32Value());
            
        }
        
    }
    // perform quick sort on the container

    std::sort(container.begin(), container.end(),VariantComparator());
    Napi::Array result = vectorToArray(env, container);
    container = {};
    return result;
   

}


// async

 Napi::Array QuickSort::vectorToArray(Napi::Env &env,  std::vector<std::variant<int,std::string>>  vec){
    unsigned int length = vec.size();

    Napi::Array array = Napi::Array::New(env, length);
    for (size_t i = 0; i < length; i++)
    {
        if (std::holds_alternative<int>(vec.at(i))){
            array.Set(i, Napi::Number::New(env, std::get<int>(vec.at(i))));
        }
        else if (std::holds_alternative<std::string>(vec.at(i))){
            array.Set(i, Napi::String::New(env, std::get<std::string>(vec.at(i))));
        }
    }
    
    return array;
 }
 
 std::vector<double> QuickSort::arrayToVector(Napi::Array array){

    unsigned int length = array.Length();
    for (size_t i = 0; i < length; i++)
    {
        Napi::Value value = array.Get(i);

        if (value.IsString()){
            container.push_back(value.As<Napi::String>().Utf8Value());
            
        }
        else if(value.IsNumber()){
            container.push_back(value.As<Napi::Number>().Int32Value());
            
        }
        
    }
    
}

 std::vector<std::variant<int,std::string>> QuickSort::getContainer(){

    return container;
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
    

 
    //  perform async operation
    QuickSortAsync* worker = new QuickSortAsync(env, array);
    worker->Queue();
    // return the promise
    return worker->GetPromise();


}
