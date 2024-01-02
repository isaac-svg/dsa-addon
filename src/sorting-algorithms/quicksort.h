#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <napi.h>
#include <thread>
#include <future>
#include  <variant>
#include <string>
#include <iostream>

using myVariant = std::variant<int,std::string>;

class QuickSort : public Napi::ObjectWrap<QuickSort> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    QuickSort(const Napi::CallbackInfo& info);
    Napi::Value quicksortAsync(const Napi::CallbackInfo& info);
    Napi::Value quicksort(const Napi::CallbackInfo& info);
   
//    Helper Methods

    [[nodiscard]]  std::vector<std::variant<int,std::string>> getContainer();
    [[nodiscard]]  Napi::Array vectorToArray(Napi::Env &env,  std::vector<std::variant<int,std::string>> );
    std::vector<double> arrayToVector( Napi::Array array);



    // 

     struct VariantComparator {
    bool operator()(const std::variant<int, std::string>& a, const std::variant<int, std::string>& b) const {
        // Handle different types within variants:
        if (std::holds_alternative<int>(a) && std::holds_alternative<int>(b)) {
            // Both are ints, compare directly:
            return std::get<int>(a) < std::get<int>(b);
        } else if (std::holds_alternative<std::string>(a) && std::holds_alternative<std::string>(b)) {
            // Both are strings, compare lexicographically:
            return std::stoi(std::get<std::string>(a)) < std::stoi(std::get<std::string>(b));
        } else if (std::holds_alternative<std::string>(a) && std::holds_alternative<int>(b)){
            // Different types, prioritize ints before strings:
           
           return std::stoi(std::get<std::string>(a))<  std::get<int>(b);

            
        }
        else{
            return  std::get<int>(a) < std::stoi(std::get<std::string>(b));
        }
    }
};


private:
     std::vector<double> data_;
    std::vector<std::variant<int,std::string>> container; 
    // 
    
};

#endif
