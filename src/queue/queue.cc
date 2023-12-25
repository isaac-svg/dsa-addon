#include "queue.h"


Napi::Object Queue::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(env, "Queue", {
    InstanceMethod("enqueue", &Queue::enqueue),
    InstanceMethod("dequeue", &Queue::dequeue),
    InstanceMethod("peek", &Queue::peek),
    InstanceMethod("front", &Queue::front),
    InstanceMethod("isEmpty", &Queue::isEmpty),
    InstanceMethod("size", &Queue::size),
    InstanceMethod("clear", &Queue::clear) // Optional
  });

  exports.Set("Queue", func);
  return exports;
}

Queue::Queue(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Queue>(info) {
    Napi::Env env = info.Env();

    head = nullptr;
    tail = nullptr;
    length = 0;
      
    if (info.Length() > 0) {
        Napi::Value arg = info[0];

        if (arg.ToObject().Has(Napi::Symbol::WellKnown(env, "iterator"))) {
            Napi::Function iteratorFunction = arg.ToObject().Get(Napi::Symbol::WellKnown(env, "iterator")).As<Napi::Function>();
            Napi::Object iterator = iteratorFunction.Call(arg, {}).As<Napi::Object>();

            Napi::Value next = iterator.Get("next");
            if (!next.IsFunction()) {
                Napi::TypeError::New(env, "Iterator's next method is not a function").ThrowAsJavaScriptException();
                return;
            }

            while (true) {
                Napi::Value result = next.As<Napi::Function>().Call(iterator, {});
                if (result.ToObject().Get("done").ToBoolean().Value()) {
                    break;
                }
                Napi::Value value = result.ToObject().Get("value");
                this->Enqueue(value);
            }
        } else {
            Napi::TypeError::New(env, "Argument must be iterable").ThrowAsJavaScriptException();
        }
    }
}



Napi::Value Queue::enqueue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Value value = info[0];

  Node* newNode = new Node{value, nullptr};
  if (tail == nullptr) {
    head = newNode;
  } else {
    tail->next = newNode;
  }
  tail = newNode;
  length++;

  return env.Null();
}

Napi::Value Queue::dequeue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (isEmpty(info).ToBoolean()) {
    Napi::TypeError::New(env, "Queue is empty").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Value value = head->value;
  Node* temp = head;
  head = head->next;
  delete temp;
  length--;

  if (head == nullptr) {
    tail = nullptr;
  }

  return value;
}

Napi::Value Queue::peek(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (isEmpty(info).ToBoolean()) {
    return env.Null();
  }

  return head->value;
}

Napi::Value  Queue::front(const Napi::CallbackInfo& info){

   Napi::Env env = info.Env();

  if (isEmpty(info).ToBoolean()) {
    return env.Null();
  }

  return tail->value;
}

Napi::Value Queue::isEmpty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Boolean::New(env, length == 0);
}

Napi::Value Queue::size(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Number::New(env, length);
}

Napi::Value Queue::clear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }

  head = tail = nullptr;
  length = 0;

  return env.Null();
}


// internal methods

Napi::Value Queue::Enqueue(const Napi::Value& value) {
    Napi::Env env = Env();

    Node* newNode = new Node{value, nullptr};
    if (tail == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
    length++;

    return env.Null();
}
