#ifndef SAMPLE_BITS_UTILS_H
#define SAMPLE_BITS_UTILS_H

#include "CommonLibs.h"

class BitsUtils{

    static int toggleBit(int n)
    {
        if (n == 0)
            return 1;

        // Make a copy of n as we are
        // going to change it.
        int i = n;

        // Below steps set bits after
        // MSB (including MSB)

        // Suppose n is 273 (binary
        // is 100010001). It does following
        // 100010001 | 010001000 = 110011001
        n |= n >> 1;

        // This makes sure 4 bits
        // (From MSB and including MSB)
        // are set. It does following
        // 110011001 | 001100110 = 111111111
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;

        return i ^ n;
    }

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

    /* this will turn off the last set bit(1)*/
    static int unsetLeastSignificantSetBit(int num){
        // for 1010 -> value = 10 = 3 ( second one is least significant set bit)
        // 10 -> 1010
        // -10 -> 0110 ( 2's complement) -> 6
        // now 1010 - (1010 & 0110) = 1010 - 10 = 1000(8)

        return num - (num & - num); //used in fenwick tree
    }

        /* this will turn on the last unset bit (0)*/
    static int setLeastSignificantUnsetBit(int num){
        // for 1010  -> 1011 (11)
        // 10 -> 1010
        // 10+1 -> 1011
        // now 1010 | 1011  = 1011(11)
        // +1 always alter last zero(unset bit)

        return num | (num+1);
    }

    /* this will turn off the last consecutive run of 1s (if any) */
    static int unsetLastConsecutive1s(int num){
        // will work for 1011 -> 1000 ( 1s should be at last)
        // 1011 +1 -> 1100
        // now if we do AND, 1011 & 1100 -> 1000
        // +1 always alter last 0 and in way it will always make consecutive 1s 0
        return num & (num + 1);
    }

        /* this will turn on the last consecutive run of 0s (if any) */
    static int setLastConsecutive0s(int num) {
            // will work for   1000 -> 1111 ( 0s should be at last)
            // 1000 - 1 -> 0111
            // now if we do OR , 1000 | 0111 -> 1111
            // -1 will convert all consecutive 0s into 1s

            return num | (num - 1);
        }

    static bool isPowerOf2(int num){
        // if num is Power of 2
        // let num = 8 =1000,
        // num-1 = 7 = 0111,
        // and will be 0 (only if num is power of 2)

      // NOTE -  num & (num - 1) == 0 will not work as == has more priority that &
        return (num & (num - 1)) == 0;
    }
    static int findModuloIfNisPowerOf2(int num,int N){
        if(!isPowerOf2(N)){
            // not possible to find  N must be power of 2
            return -1;
        }

        // let num = 10 = 1010
        // N = 4 = 100 ( must be power of 2 )
        //  so N-1 = 3 = 11
        // now, 1010 & 11 = 0010 ( it will extract only those bits which are covered by N-1 ( all 1's)


       // NOTE -  num & (N - 1) == 0 will not work as == has more priority that &

        return  num & (N - 1);
    }

    static int xnor(int num1, int num2){
        // we can't do directly ~(x^y) as there are extra bits which makes it negative.
//    https://www.geeksforgeeks.org/toggle-bits-significant-bit/
//    https://www.geeksforgeeks.org/xnor-two-numbers/

        // if num2 is greater then
        // we swap this number in num1
        if (num1 < num2)
            swap(num1, num2);
        num1 = toggleBit(num1);

        return num1 ^ num2;
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

    assert(BitsUtils::unsetLeastSignificantSetBit(10)==8);

    assert(BitsUtils::setLeastSignificantUnsetBit(10)==11);

    assert(BitsUtils::unsetLastConsecutive1s(11)==8);

    assert(BitsUtils::setLastConsecutive0s(8)==15);

    assert(BitsUtils::isPowerOf2(8));

    assert(!BitsUtils::isPowerOf2(10));

    assert(BitsUtils::findModuloIfNisPowerOf2(10,4)==2);

    assert(BitsUtils::xnor(7,5)==5 && BitsUtils::xnor(10,20)==1 && BitsUtils::xnor(10,50)==7 );
}

#endif
