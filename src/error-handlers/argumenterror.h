#include <napi.h>

namespace argumentError
{
    
    class argError
    {
    private:
        /* data */
    public:
       static Napi::Value argumentCountEror(size_t expected, size_t received, Napi::Env env);
       static Napi::Value argumentTypeEror(Napi::Env env, std::string message);
       
    };
    
    
    
} // namespace argumentError
