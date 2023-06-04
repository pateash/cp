cmake_minimum_required(VERSION 3.5)
project(code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        src/main/main.cpp
#        src/main/main_fastio.cpp
        src/main/leetcode.cpp
        src/main/template.cpp
        src/main/libs/CommonLibs.h
        src/main/libs/MathsUtils.h
        src/main/libs/Primes.h
        src/main/libs/UnionFind.h
        src/main/libs/SegmentTree.h
        src/main/libs/SegmentTreeLazy.h
        src/main/libs/FenwickTree.h
        src/main/libs/ModArithmetic.h
        src/main/libs/Sorting.h
        src/main/libs/BinarySearchTree.h
        src/main/libs/StringUtils.h
        src/main/libs/BitsUtils.h
        src/main/libs/graph/GraphTraversal.h
        src/main/libs/graph/GraphTypes.h
        src/main/libs/Stack.h
        src/main/libs/BinarySearchUtils.h
        )

add_executable(code ${SOURCE_FILES})


set(TEST_SOURCE_FILES
        src/main/test.cpp
        src/main/libs/CommonLibs.h
        src/main/libs/MathsUtils.h
        src/main/libs/Primes.h
        src/main/libs/UnionFind.h
        src/main/libs/SegmentTree.h
        src/main/libs/SegmentTreeLazy.h
        src/main/libs/FenwickTree.h
        src/main/libs/ModArithmetic.h
        src/main/libs/Sorting.h
        src/main/libs/BinarySearchTree.h
        src/main/libs/StringUtils.h
        src/main/libs/BitsUtils.h
        src/main/libs/graph/GraphTraversal.h
        src/main/libs/graph/GraphTypes.h
        src/main/libs/Stack.h
        src/main/libs/BinarySearchUtils.h
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
