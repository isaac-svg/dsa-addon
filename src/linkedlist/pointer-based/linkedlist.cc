#include "linkedlist.h"
#include "../../error-handlers/argumenterror.h"
#include "../../error-handlers/exception.h"
#include <iostream>
using namespace linkedlist_pointer;
// namespace linkedlist_pointer {


    Napi::Object LinkedList::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "LinkedList", {
        InstanceMethod("addHead", &LinkedList::addHead),
        InstanceMethod("addTail", &LinkedList::addTail),
        // InstanceMethod("copyList", &LinkedList::CopyList),
        // InstanceMethod("CopyListReversed", &LinkedList::CopyListReversed),
        InstanceMethod("deleteNode", &LinkedList::deleteNode),
        InstanceMethod("deleteNodes", &LinkedList::deleteNodes),
        InstanceMethod("freeList", &LinkedList::freeList),
        InstanceMethod("isPresent", &LinkedList::isPresent),
        InstanceMethod("sortedInsert", &LinkedList::reverse),
        InstanceMethod("isPresent", &LinkedList::sortedInsert),
        InstanceMethod("size", &LinkedList::size),
        InstanceMethod("reverse", &LinkedList::reverse),
        InstanceMethod("peek", &LinkedList::peek),

    });

    exports.Set("PointerList", func);
    return exports;
}

    LinkedList::LinkedList(const Napi::CallbackInfo& info) : Napi::ObjectWrap<LinkedList>(info) {}
   LinkedList::Node::Node(std::string v, Node *n)
    {
        value = v;
        next = n;
    }
    LinkedList::Node::Node(std::string v)
    {
        value = v;
        next = nullptr;
    }

    LinkedList::Node::Node(){
        next = nullptr;
   
    }
   
    Napi::Value LinkedList::size(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();
        return Napi::Number::New(env, list_size);
    }

    Napi::Value LinkedList::peek(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();
        if (head != nullptr) {
            return Napi::Value::From(env, head->value);
        } else {
            return env.Null();
        }
    }

    Napi::Value LinkedList::isEmpty(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();
        return Napi::Boolean::New(env, list_size == 0);
    }

   Napi::Value LinkedList::addHead(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();
    // Check argument validity
    // argumentError::argError::argumentCountEror(1, info.Length(), env);


    // argumentCountEror(1,1,env);

   
    Napi::Value val = info[0];
    std::string value = val.As<Napi::String>().ToString().Utf8Value();

    
    
    LinkedList::Node* newNode = new Node(value, head);

    newNode->next = head;
    head = newNode;

    list_size++;

    
        // std::string str = Napi::JSONStringify(env, value).Utf8Value();
    return val; 
   }

    Napi::Value LinkedList::removeHead(const Napi::CallbackInfo& info){

        Napi::Env env = info.Env();

        if (head == nullptr){
            return  env.Null();
        }
        Node * temp = head;
        head = head->next;
        std:: string oldVal  =  temp->value;
        delete temp;

        --list_size;

        return  Napi::String::New(env, oldVal);
    }


    Napi::Value LinkedList::addTail(const Napi::CallbackInfo& info){

        Napi::Env env = info.Env();

        // argumentError::argError::argumentCountEror(1, 1, env);

        if (head == nullptr){
            return env.Null();
        }

        std::string value = info[0].As<Napi::String>().ToString().Utf8Value();

    
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        } else {
        //  node
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        return Napi::String::New(env, value);
    }

     Napi::Value LinkedList::sortedInsert(const Napi::CallbackInfo& info){

        Napi::Env env = info.Env();

        //  argumentError::argError::argumentCountEror(1, 1, env);

        Napi::Value nval = info[0];
        std::string v = info[0].As<Napi::String>().ToString().Utf8Value();

        Node *newNode = new Node(v, nullptr);
        Node *curr = head;

        if (curr == nullptr || curr->value > v)
        {
            newNode->next = head;
            head = newNode;
            return env.Null();
        }
        while (curr->next != nullptr && curr->next->value < v )
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;

        return Napi::String::New(env, v);
     }

     Napi::Value LinkedList::isPresent(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();

        //  argumentError::argError::argumentCountEror(1, 1, env);

        Napi::Value nVal = info[0];
        std::string data = nVal.As<Napi::String>().ToString().Utf8Value();
         Node *curr = head;

        while (curr->next != nullptr)
        {
            if (curr->value == data)
            {
                return Napi::Boolean::New(env, true);;
            }
            curr = curr->next;
        }
        return Napi::Boolean::New(env, false);;
     }
    Napi::Value LinkedList::deleteNode(const Napi::CallbackInfo &info){
        Napi::Env env = info.Env();

        if (list_size == 0)
        {
            // throw an exception
            Exception::exception::emptyList(env);
        }
   

    Node *curr = head;
    Node *delMe = nullptr;

    Napi::Value nVal = info[0];
    std::string data = nVal.As<Napi::String>().ToString().Utf8Value();
    if (head->value == data)
    {
        Node *delMe = head;
        head = head->next;
        list_size--;
        delete delMe;
        return Napi::Boolean::New(env, true);
    }
    while (curr->next != nullptr)
    {
        if (curr->next->value == data)
        {
            delMe = curr->next;
            curr->next = curr->next->next;
            list_size--;
            delete delMe;
            return Napi::Boolean::New(env, true);
        }
        curr = curr->next;
    }
    return Napi::Boolean::New(env, false);
    }


    Napi::Value LinkedList::deleteNodes(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();


        argumentError::argError::argumentCountEror(1,1,env);
            Node *currNode = head;
            Node *delMe = nullptr;
            Node *nextNode = nullptr;
            Napi::Value nVal = info[0];
            std::string delValue = nVal.As<Napi::String>().ToString().Utf8Value();
         // check for first occurence.
            while (currNode != nullptr && currNode->value == delValue)
            {
            delMe = head;
            head = currNode->next;
            currNode = head;
            delete delMe;
        }
        while (currNode != nullptr)
        {
            nextNode = currNode->next;
            if (nextNode != nullptr && nextNode->value == delValue)
            {
            delMe = currNode->next;
            currNode->next = nextNode->next;
            delete delMe;
         }
            else
        {
            currNode = nextNode;
        }
        }
    }

    Napi::Value LinkedList::freeList(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();
        Node *currNode = head;
        Node *nextNode;
        while (currNode != nullptr)
        {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
        }
    head = nullptr;
    list_size = 0;

    return env.Null();
    }

    Napi::Value LinkedList::reverse(const Napi::CallbackInfo& info){
    Napi::Env env =  info.Env();
        Node *currNode = head;
    Node *nextNode = nullptr;
    Node *prevNode = nullptr;

    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
    return Napi::String::New(env, head->value);
    }

    Napi::Value LinkedList::removeDuplicate(const Napi::CallbackInfo& info){

        Napi::Env env = info.Env();
        argumentError::argError::argumentCountEror(0, info.Length(), env);
        if (head == nullptr) {
        return env.Null();
    }

    Node* current = head;

    while (current->next != nullptr) {
        Node* runner = current;
        
        while (runner->next->next != nullptr) {
            if (current->value == runner->next->value) {
                // Remove duplicate
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
                list_size--;
               
                break;  
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }

    return env.Null();

    }

   Napi::Value LinkedList::nthNodeFromBegining(const Napi::CallbackInfo& info){

    Napi::Env env = info.Env();

    if (info.Length() != 1 || !info[0].IsNumber()) {
        argumentError::argError::argumentTypeEror(env, "Expected a number");
    }

    const int index = info[0].As<Napi::Number>().Int32Value();

    if (index <= 0 || index > list_size) {
        Exception::exception::outOfRange(env);
    }

    Node* currentNode = head;
    int count = 1; // Start count from 1 for the first node

    while (currentNode != nullptr && count < index) {
        currentNode = currentNode->next;
        count++;
    }

    if (currentNode != nullptr) {
        return Napi::String::New(env, currentNode->value);
    } else {
        Exception::exception::outOfRange(env);
    }
   }

    Napi::Value LinkedList::nthNodeFromEnd(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();

    // Argument validation:
    try {
        // argumentError::argError::argumentCountEror(1, info.Length(), env);
        int n = info[0].As<Napi::Number>().Int32Value();

        // Handle invalid index and empty list:
        if (n < 1 || head == nullptr) {
            return env.Null();
        }

        // Two-pointer approach:
        Node* first = head;
        Node* second = head;

        // Move second pointer n nodes ahead:
        for (int i = 0; i < n && second != nullptr; i++) {
            second = second->next;
        }

        // Check if n is greater than list size:
        if (second == nullptr) {
            return env.Null();  // nth node from end doesn't exist
        }

        // Move both pointers together until second reaches the end:
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Return the value of the nth node from the end:
        return Napi::String::New(env, first->value);
          // 
    } catch (const Napi::TypeError& e) {
        // argumentError::argError::argumentTypeEror(env, Napi::Value::From(env, e).ToString().Utf8Value());  
        return env.Null();
    }
    }


    Napi::Value LinkedList::loopDetect(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();

    // Handle empty list
    if (head == nullptr) {
        return Napi::Boolean::New(env, false);  // No loop in an empty list
    }

    // (Hare and Tortoise approach)
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // If they meet, there's a loop
        if (slow == fast) {
            return Napi::Boolean::New(env, true);
        }
    }

    // If they don't meet, there's no loop
    return Napi::Boolean::New(env, false);
    }

    // Napi::Value LinkedList::CopyList(const Napi::CallbackInfo& info){
    //     Napi::Env env = info.Env();
    //     Node *headNode = nullptr;
    // Node *tailNode = nullptr;
    // Node *tempNode = nullptr;
    // Node *currNode = head;

    // if (currNode == nullptr)
    // {
    //     LinkedList *LL2 = new LinkedList();
    //     LL2->head = nullptr;
    //     return Napi::Value::From(env, LL2).As<Napi::String>();
    // }
    // headNode = new Node(currNode->value, nullptr);
    // tailNode = headNode;
    // currNode = currNode->next;

    // // iteration starts from the second node;
    // while (currNode != nullptr)
    // {
    //     tempNode = new Node(currNode->value, nullptr);
    //     tailNode->next = tempNode;
    //     tailNode = tempNode;
    //     currNode = currNode->next;
    // }
    // LinkedList *LL2 = new LinkedList();
    // LL2->head = tempNode;
    // return Napi::Value::From(env, LL2);
    // }

    //  Napi::Value LinkedList::CopyListReversed(const Napi::CallbackInfo& info){
    //     Napi::Env env = info.Env();

    // // Create a new empty list to hold the reversed copy
    // LinkedList* reversedList = new LinkedList();

    // // Handle empty list
    // if (head == nullptr) {
    //     return Napi::Value::From(env, reversedList);  // Return the empty list
    // }

    // // Iterate through the original list and add nodes to the reversed list in reverse order
    // Node* current = head;
    // while (current != nullptr) {
    //     // Create a new node for the reversed list
    //     Node* newNode = new Node(current->value);

    //     // Add the new node at the beginning of the reversed list
    //     newNode->next = reversedList->head;
    //     reversedList->head = newNode;

    //     current = current->next;
    // }

    // // Update the list size of the reversed list
    // reversedList->list_size = list_size;

    // return Napi::Value::From(env, reversedList);  // Return
    //  }
// } // namespace linkedlist_pointer





