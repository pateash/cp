cmake_minimum_required(VERSION 3.5)
project(code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
     main.cpp
     main2.cpp
        src/libs/CommonLibs.h
        src/libs/MathsUtils.h
        src/libs/Primes.h
        src/libs/UnionFind.h
        src/libs/SegmentTree.h
        src/libs/SegmentTreeLazy.h
        src/libs/FenwickTree.h
        src/libs/ModArithmetic.h
        src/libs/Sorting.h
        src/libs/BinarySearchTree.h
        src/libs/StringUtils.h
        src/libs/BitsUtils.h
        src/libs/Graph.h
        src/libs/Stack.h
        src/libs/BinarySearchUtils.h
        )

add_executable(code ${SOURCE_FILES})
