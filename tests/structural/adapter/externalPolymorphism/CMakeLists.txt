set(EXAMPLE externalPolymorphism)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME adapterEPTest)

include_directories (../../../include ${SRC_PATH})

set(sources
   adapterEPTest.cpp 
   ${SRC_PATH}/adapterExternalPolymorphism.cpp)

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )

