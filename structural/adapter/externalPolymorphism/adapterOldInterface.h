/**
  adapterOldInterface.h

  This is based on the AdapterExternalPolymorphism.cpp example from:
     https://sourcemaking.com/design_patterns/adapter/cpp/2
 
 The code here contains the code dealing with the "old/legacy" classes that
 aren't polymorphic and going to create an "adapter" interface so
 we can treat them in a similar fashion as polymorphic classes.
 
  See the repo's README.md for a breakdown of what was done to the example.

  Created by Tal Lancaster on 1/8/17.

**/



#ifndef adapterOldInterface_h
#define adapterOldInterface_h

// The old: three totally incompatible classes
// no common base class,
class Fea {
public:
    // no hope of polymorphism
    ~Fea() {
        std::cout << "Fea::dtor\n";
    }
    void doThis() {
        std::cout << "Fea::doThis()\n";
    }
};

class Feye {
public:
    ~Feye() {
        std::cout << "Feye::dtor\n";
    }
    
    void doThat() {
        std::cout << "Feye::doThat()\n";
    }
};

class Pheau {
public:
    ~Pheau() {
        std::cout << "Pheau::dtor\n";
    }
    void doTheOther() {
        std::cout << "Pheau::doTheOther()\n";
    }
};


#endif /* adapterOldInterface_h */
