/**
  main.cpp
 
  This is based on the AdapterExternalPolymorphism.cpp example from:
     https://sourcemaking.com/design_patterns/adapter/cpp/2
 
  See the repo's README.md for a breakdown of what was done to the example.
 
 The code here represents the main() from the original example

  Created by Tal Lancaster on 1/8/17.

**/

#include "adapterExternalPolymorphism.h"

int main() {
    ExecuterInterfacePtrArray objects = initialize();
    for (auto& e: objects) {
        e->execute();
    }
}
