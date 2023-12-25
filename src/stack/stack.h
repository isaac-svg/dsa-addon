#include <napi.h>

class Stack : public Napi::ObjectWrap<Stack> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Stack(const Napi::CallbackInfo& info);

  Napi::Value push(const Napi::CallbackInfo& info);
  Napi::Value pop(const Napi::CallbackInfo& info);
  Napi::Value peek(const Napi::CallbackInfo& info);
  Napi::Value isEmpty(const Napi::CallbackInfo& info);
  Napi::Value size(const Napi::CallbackInfo& info);
  Napi::Value clear(const Napi::CallbackInfo& info); // Optional

private:
  struct Node {
    Napi::Value value;
    Node* next;
  };

  Node* head = nullptr;
  uint32_t length = 0;
};
