
#include <sstream>

#include "RedirectStdOut.h"
#include "commandAfter.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("commandTest", "[command]")
{
    const std::string capturedOutput {
R"(0-fee  1-phi  2-pheaux  3-fee  4-phi  5-pheaux  
)"
    };

    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        {
            testInterface ();
        }
    }

    CHECK (capturedOutput == os.str () );
}

