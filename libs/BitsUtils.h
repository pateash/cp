#ifndef SAMPLE_BITS_UTILS_H
#define SAMPLE_BITS_UTILS_H

#include "CommonLibs.h"

class BitsUtils{


public:
    /* could be used as multiply by 2^N and floor*/
    static int leftShiftByN(int num, int N){
        return num << N;
    }

    /* could be used as devide by 2^N and floor*/
    static int rightShiftByN(int num, int N){
        return num >> N;
    }


    // first bit is 0th bit
    static bool isNthBitSet(int num, int N){
        return (num & (1 << N)) == 1;
    }

    static int setNthBit(int num, int N){
        return num | (1 << N);
    }

    static int UnsetNthBit(int num, int N){
        // doing & by 0 will unSet
        return num & ~(1 << N);
    }

    static int flipNthBit(int num, int N){
        // if we do XOR with 1, we will flip
        // 0 ^ 1 -> 1
        // 1 ^ 1 -> 0
        return num ^ (1 << N);
    }

    static int valueOfLeastSignificantBit(int num){
        // for 1010 -> value = 10 = 3 ( second one is least significant set bit)
        // 10 -> 1010
        // -10 -> 0110 ( 2's complement, flip after least significant bit)
        // doing & will remote all opposite and we get 10 = 2

        return num & (-num);
    }

    static int removeLeastSignificantBit(int num){
        // for 1010 -> value = 10 = 3 ( second one is least significant set bit)
        // 10 -> 1010
        // -10 -> 0110 ( 2's complement) -> 6
        // now 1010 - (1010 & 0110) = 1010 - 10 = 1000(8)

        return num - (num & -num); //used in fenwick tree
    }

};

int main(){

    assert(BitsUtils::leftShiftByN(2,2)==8);

    assert(BitsUtils::rightShiftByN(4,2)==1);

// first bit is 0th bit
    //    1010 3rd bit is not set
    assert(!BitsUtils::isNthBitSet(10, 3));

    assert(BitsUtils::setNthBit(4,1)==6);

    assert(BitsUtils::UnsetNthBit(6,1)==4);

    assert(BitsUtils::flipNthBit(6,1)==4);

    assert(BitsUtils::flipNthBit(4,1)==6);

    assert(BitsUtils::valueOfLeastSignificantBit(10)==2);

    assert(BitsUtils::removeLeastSignificantBit(10)==8);

}

#endif
