cmake_minimum_required(VERSION 3.5)
project(Sample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
     main.cpp
        libs/CommonLibs.h
        libs/OtherFunctions.h
        libs/Primes.h
        libs/UnionFind.h
        libs/SegmentTree.h
        libs/SegmentTreeLazy.h
        libs/ModArithmetic.h
        libs/Sorting.h
        libs/BinarySearchTree.h
        )

add_executable(Sample ${SOURCE_FILES})