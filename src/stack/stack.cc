#include "stack.h"


Napi::Object Stack::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(env, "Stack", {
    InstanceMethod("push", &Stack::push),
    InstanceMethod("pop", &Stack::pop),
    InstanceMethod("peek", &Stack::peek),
    InstanceMethod("isEmpty", &Stack::isEmpty),
    InstanceMethod("size", &Stack::size),
    InstanceMethod("clear", &Stack::clear) // Optional
  });

  exports.Set("Stack", func);
  return exports;
}

Stack::Stack(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Stack>(info) {}

Napi::Value Stack::push(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Value value = info[0];

  Node* newNode = new Node{value, head};
  head = newNode;
  length++;

  return env.Null();
}

Napi::Value Stack::pop(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (isEmpty(info).ToBoolean()) {
    Napi::TypeError::New(env, "Stack is empty").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Value value = head->value;
  Node* temp = head;
  head = head->next;
  delete temp;
  length--;

  return value;
}

Napi::Value Stack::peek(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (isEmpty(info).ToBoolean()) {
    return env.Null();
  }

  return head->value;
}


Napi::Value Stack::isEmpty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Boolean::New(env, length == 0);
}

Napi::Value Stack::size(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Number::New(env, length);
}

Napi::Value Stack::clear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }

  head = nullptr;
  length = 0;

  return env.Null();
}
