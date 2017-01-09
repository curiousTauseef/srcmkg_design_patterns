/**
  adapterExternalPolymorphism.cpp

  This is based on the AdapterExternalPolymorphism.cpp example from:
     https://sourcemaking.com/design_patterns/adapter/cpp/2
 
  See the repo's README.md for a breakdown of what was done to the example.
 
  The code here represnts sets up the Execute interface.

  Created by tal on 1/8/17.

 **/

#include "adapterExternalPolymorphism.h"
#include "adapterOldInterface.h"

/* the new is returned */
ExecuterInterfacePtrArray initialize() {
    ExecuterInterfacePtrArray array{};

    /* the old is below */
    array[0] = std::make_shared<ExecuteAdapter<Fea> > (new Fea(), &Fea::doThis);
    array[1] = std::make_shared<ExecuteAdapter<Feye> > (new Feye(), &Feye::doThat);
    array[2] = std::make_shared<ExecuteAdapter<Pheau> >(new Pheau(), &Pheau::doTheOther);

    return array;
}
