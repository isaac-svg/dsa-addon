#include "exception.h"


namespace Exception
{
    Napi::Value exception::emptyList(Napi::Env env){

         Napi::RangeError::New(env, "EmptyListException").ThrowAsJavaScriptException();
            return env.Null();
    }
    
    Napi::Value exception::outOfRange(Napi::Env env){

        Napi::RangeError::New(env, "Index must be a non-negative number").ThrowAsJavaScriptException();
        return env.Null();
    
    }
} // namespace Exception
