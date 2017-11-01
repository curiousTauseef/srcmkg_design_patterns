set(EXAMPLE command)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME commandAfterTest)

include_directories (../../include ${SRC_PATH})

set(sources
   ${TEST_NAME}.cpp
   ${SRC_PATH}/CommandAfter.cpp)

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )

