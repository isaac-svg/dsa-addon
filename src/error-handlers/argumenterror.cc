#include "argumenterror.h"

namespace argumentError
{
    
    Napi::Value argError::argumentCountEror(size_t expected, size_t received, Napi::Env env){

        if (expected != received){
            
            std::string message  = "Expected " + std::to_string(expected) + " argument(s) but got " + std::to_string(received);
            Napi::Error::New(env, message).ThrowAsJavaScriptException();
            return env.Null();
        }
    }

    Napi::Value argError::argumentTypeEror( Napi::Env env, std::string message){
         Napi::TypeError::New(env, message).ThrowAsJavaScriptException();
            return env.Null();
    }
} // namespace argumentError
