#include <napi.h>

class Queue : public Napi::ObjectWrap<Queue> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Queue(const Napi::CallbackInfo& info);

    // Queue methods
    Napi::Value enqueue(const Napi::CallbackInfo& info);
    Napi::Value dequeue(const Napi::CallbackInfo& info);
    Napi::Value peek(const Napi::CallbackInfo& info);
    Napi::Value isEmpty(const Napi::CallbackInfo& info);
    Napi::Value size(const Napi::CallbackInfo& info);

  private:
    Napi::Value clear(const Napi::CallbackInfo& info);

    struct Node {
      Napi::Value value;
      Node* next;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
};

