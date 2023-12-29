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
        Vect.resize(len);

        // copy the aray values into the  vector
        for (size_t i = 0; i < len; i++) {
            Vect[i] = data.Get(i).As<Napi::Number>().DoubleValue();
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

    std::sort(Vect.begin(), Vect.end());
      
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
            
            result.Set(i, Vect[i]);
        }
        
        
        
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
  size_t len;
  Napi::Number sortby;
  
};