#include <napi.h>

namespace Exception
{
    
    class exception
    {
    private:
        /* data */
    public:
       static Napi::Value emptyList(Napi::Env env);
       static Napi::Value outOfRange(Napi::Env env);
    };
    
    
} // namespace Exception
