cmake_minimum_required(VERSION 3.5)
project(code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB SOURCE_FILES
        "src/main/main.cpp"
        )

file(GLOB LIVE_SOURCE_FILES
                "src/main/live/*.cpp"
        )

add_executable(code ${SOURCE_FILES})
add_executable(live ${LIVE_SOURCE_FILES})

file(GLOB TEST_SOURCE_FILES
        "src/main/test.cpp"
        "src/main/libs/*.h"
        "src/main/libs/maths/*.h"
        )

add_executable(test ${TEST_SOURCE_FILES})

set(RUN_SOURCE_FILES
        src/main/run.cpp
        )
add_executable(run ${RUN_SOURCE_FILES})

# resources file copy , only use for testing (can't use for main as we want to monitor them )
FILE(COPY src/resources/libs/graph_input.txt DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY src/resources/libs/graph_input_adjlist.txt DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY src/resources/libs/graph_input_adjmatrix.txt DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY src/resources/libs/graph_input_edgelist.txt DESTINATION "${CMAKE_BINARY_DIR}")
