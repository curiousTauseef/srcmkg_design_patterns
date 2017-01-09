
#include <memory>
#include <sstream>

#include "RedirectStdOut.h"
#include "adapterExternalPolymorphism.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("adapterEPTest", "[adapter]")
{
    const std::string capturedOutput {
R"(Fea::doThis()
Feye::doThat()
Pheau::doTheOther()
Pheau::dtor
Feye::dtor
Fea::dtor
)"
    };
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        {
            ExecuterInterfacePtrArray objects = initialize();
            for (auto& e: objects) {
                e->execute();
            }
        }
    }
    
    CHECK (capturedOutput == os.str() );
    
}
