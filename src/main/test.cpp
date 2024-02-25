#include "libs/ArrayUtils.h"
#include "libs/Backtracking.h"
#include "libs/BinarySearchTree.h"
#include "libs/BinarySearchUtils.h"
#include "libs/BitsUtils.h"
#include "libs/CommonLibs.h"
#include "libs/FenwickTree.h"
#include "libs/LinkedList.h"
#include "libs/maths/MathsUtils.h"
#include "libs/maths/GcdLcmUtils.h"
#include "libs/ModArithmetic.h"
#include "libs/Primes.h"
#include "libs/SegmentTree.h"
#include "libs/SegmentTreeLazy.h"
#include "libs/Sorting.h"
#include "libs/Stack.h"
#include "libs/Stack2.h"
#include "libs/string/StringUtils.h"
#include "libs/string/StringSearch.h"
#include "libs/UnionFind.h"
#include "libs/GenerateUtils.h"
#include "libs/graph/GraphTypes.h"
#include "libs/graph/GraphTraversal.h"

using namespace std;

void runTests(){
    puts("testMathUtils");
    testMathUtils();

    puts("testGcdLcmUtils");
    testGcdLcmUtils();

    puts("testArrayUtils");
    testArrayUtils();

    puts("testBinarySearchUtils");
    testBinarySearchUtils();

    puts("testBitsUtils");
    testBitsUtils();

    puts("testGenerateUtils");
    testGenerateUtils();

    puts("testLinkedList");
    testLinkedList();

    puts("testSegmentTree");
    testSegmentTree();

    puts("testSorting");
    testSorting();

    puts("testGraphTypes");
    testGraphTypes();

    puts("testGraphTraversals");
    testGraphTraversals();

    puts("testStringUtils");
    testStringUtils();

    puts("testStringSearch");
    testStringSearch();
}

int main(){
    puts("RUNNING TESTS");
    puts("*********************\n");
    runTests();
    puts("\n\nAll Tests done!");
    puts("*********************");

}
