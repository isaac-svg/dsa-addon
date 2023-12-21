#pragma  once
#include <napi.h>


namespace linkedlist_pointer
{
    
    class LinkedList : public Napi::ObjectWrap<LinkedList>
    {
    private:
        struct Node
        {
            std::string value;
            Node *next;
            Node(std::string v, Node *n);
            Node(std::string v);
            Node();
        };
        Node *head;
        int list_size = 0;
    public:
                LinkedList(const Napi::CallbackInfo& info);

             static Napi::Object Init(Napi::Env env, Napi::Object exports);
         Napi::Value size(const Napi::CallbackInfo& info);
         Napi::Value peek(const Napi::CallbackInfo& info);
         Napi::Value isEmpty(const Napi::CallbackInfo& info);
         Napi::Value addHead(const Napi::CallbackInfo& info);
         Napi::Value removeHead(const Napi::CallbackInfo& info);
         Napi::Value addTail(const Napi::CallbackInfo& info);
         Napi::Value print(const Napi::CallbackInfo& info);
         Napi::Value sortedInsert(const Napi::CallbackInfo& info);
         Napi::Value isPresent(const Napi::CallbackInfo& info);
         Napi::Value deleteNode(const Napi::CallbackInfo& info);
         Napi::Value deleteNodes(const Napi::CallbackInfo& info);
         Napi::Value freeList(const Napi::CallbackInfo& info);
         Napi::Value reverse(const Napi::CallbackInfo& info);
         Napi::Value removeDuplicate(const Napi::CallbackInfo& info);
        //  Napi::Value CopyListReversed(const Napi::CallbackInfo& info);
        //  Napi::Value CopyList(const Napi::CallbackInfo& info);
         Napi::Value findLength(const Napi::CallbackInfo& info);
         Napi::Value nthNodeFromBegining(const Napi::CallbackInfo& info);
         Napi::Value nthNodeFromEnd(const Napi::CallbackInfo& info);
         Napi::Value loopDetect(const Napi::CallbackInfo& info);
         Napi::Value reverseListLoopDetect(const Napi::CallbackInfo& info);
    };
    
    
    
} // namespace linkedlist_pointer
