cmake_minimum_required(VERSION 3.5)
project(Sample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
     main.cpp
        lib/CommonLibs.h
        lib/OtherFunctions.h
        lib/Primes.h
        lib/UnionFind.h
        lib/SegmentTree.h
        lib/SegmentTreeLazy.h
        lib/ModArithmetic.h
        lib/Sorting.h
        lib/BinarySearchTree.h
        )

add_executable(Sample ${SOURCE_FILES})