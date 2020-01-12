cmake_minimum_required(VERSION 3.5)
project(Sample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
     main.cpp
        libs/CommonLibs.h
        libs/MathsUtils.h
        libs/Primes.h
        libs/UnionFind.h
        libs/SegmentTree.h
        libs/SegmentTreeLazy.h
        libs/FenwickTree.h
        libs/ModArithmetic.h
        libs/Sorting.h
        libs/BinarySearchTree.h
        libs/StringUtils.h
        libs/BitsUtils.h
        libs/Graph.h
        libs/Stack.h
        libs/BinarySearchUtils.h
        )

add_executable(Sample ${SOURCE_FILES})
