#include <napi.h>
#include "quicksort.h"
#include <algorithm>
#include <iostream>

class QuickSortAsync : public Napi ::AsyncWorker {
 public:
  QuickSortAsync(const Napi::Env& env,  Napi::Array res)
      : Napi::AsyncWorker{env, "QuickSortAsync"},
        m_deferred{env}, data{res} {

        len =  data.Length();
        // copy the aray values into the  vector
    for (size_t i = 0; i < len; i++)
    {
        Napi::Value value = data.Get(i);

        if (value.IsString()){
            mixedVect.push_back(value.As<Napi::String>().Utf8Value());
           
        }
        else if(value.IsNumber()){
            mixedVect.push_back(value.As<Napi::Number>().Int32Value());
            
        }
        
    }
    }

    // overload the constructor to take a comparator

     
  /**
   * GetPromise associated with _deferred for return to JS
   */
  Napi::Promise GetPromise() { return m_deferred.Promise(); }

 protected:
  /**
   * perform the heavy work
   */
  void Execute() override {

    std::sort(mixedVect.begin(), mixedVect.end(),QuickSort::VariantComparator());
      
  }

  /**
   * Resolve the promise with the result
   */
  void OnOK() {
        Napi::HandleScope scope(Env());
        auto env = Env();
        Napi::Array result = Napi::Array::New(env, len);
        
       
       
        for (size_t i = 0; i < len; i++)
        {
            
             if (std::holds_alternative<int>(mixedVect.at(i))){
            result.Set(i, Napi::Number::New(env, std::get<int>(mixedVect.at(i))));
        }
        else if (std::holds_alternative<std::string>(mixedVect.at(i))){
            result.Set(i, Napi::String::New(env, std::get<std::string>(mixedVect.at(i))));
        }
        }
        
        mixedVect ={};
        
    m_deferred.Resolve(Napi::Array::From(Env(), result));
   }

  /**
   * Reject the promise with errors
   */
  void OnError(const Napi::Error& err) { m_deferred.Reject(err.Value()); }

 private:
  Napi::Promise::Deferred m_deferred;
  Napi::Array data;
  std::vector<double> Vect;
  std::vector<std::variant<int, std::string>> mixedVect;
  size_t len;
  Napi::Number sortby;
  
};