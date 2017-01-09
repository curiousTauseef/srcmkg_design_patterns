/**
  AdapterExternalPolymorphism.h
 
  This is based on the AdapterExternalPolymorphism.cpp example from:
    https://sourcemaking.com/design_patterns/adapter/cpp/2
 
 See the repo's README.md for a breakdown of what was done to the example.
  Created by Tal Lancaster on 1/8/17.

 The code here represnts the "new" common interface through the use of an adapter.
**/

#ifndef AdapterExternalPolymorphism_h
#define AdapterExternalPolymorphism_h


/**
 1. Specify the new desired interface
 2. Design a "wrapper" class that can "impedance match" the old to the new
 3. The client uses (is coupled to) the new interface
 4. The adapter/wrapper "maps" to the legacy implementation
 **/

#include <array>
#include <iostream>
#include <memory>

constexpr int InterfaceSize {3};

class ExecuteInterface {
public:
    // 1. Specify the new interface
    virtual ~ExecuteInterface(){}
    virtual void execute() = 0;
};

using ExecuterInterfacePtrArray = std::array<std::shared_ptr<ExecuteInterface>, InterfaceSize>;

// 2. Design a "wrapper" or "adapter" class
template <class TYPE>
class ExecuteAdapter: public ExecuteInterface {
public:
    ExecuteAdapter(TYPE *o, void(TYPE:: *m)())
    :
    _object {o},
    _method {m}
    {}
        
    ~ExecuteAdapter() {
        delete _object;
    }
    
    // 4. The adapter/wrapper "maps" the new to the legacy implementation
    void execute() {  /* the new */
        (_object->*_method)();
    }
private:
    TYPE *_object; // ptr-to-object attribute
    
    void(TYPE:: *_method)(); /* the old */     // ptr-to-member-function attribute
};

ExecuterInterfacePtrArray initialize ();

#endif /* AdapterExternalPolymorphism_h */
