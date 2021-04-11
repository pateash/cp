#ifndef SAMPLE_ARRAY_UTILS_H
#define SAMPLE_ARRAY_UTILS_H

#include "CommonLibs.h"

template <typename T>
class ArrayUtils{
public:
    static int findSumOfAbsoluteDifferenceOfAllPairs(vector<T> v){

/*
 * source - https://www.geeksforgeeks.org/sum-absolute-differences-pairs-given-array/
 *  https://stackoverflow.com/questions/5855066/finding-sum-of-absolute-difference-of-every-pair-of-integer-from-an-array
 */


/*  SOLUTION
    For example: Given a[]= {2,3, 5, 7 };
    output would be (3-2) + (5-2) + (7-2) + (5-3) + (7-3) + (7-5) = 17.

    I suppose you could --
    Sum the multiplication of each number starting backwards with #count - 1 to get the total
    Sum the multiplication of each number starting up front with #count - 1 to get the total to subtract
    This would then become (7*3 + 5*2 +3*1) - (2*3 + 3*2 + 5*1) = 17
 *
 */

        if ( v.size() < 2 )
            return 0;

        sort(v.begin(),v.end()); // sorting ascending

//        show_1d(v);
        int sum = 0;

        //  we are iterating from n-1 to 0 ( for + part, and we will then adjust other index)
        for(int i=v.size()-1;i>=0;i--)
        {
            sum += (v[i]*(i) - v[i]*(v.size()-i-1));
        }
//        cout<<"sum: "<<sum<<endl;
        return sum;
    }
};

void testArrayUtils()
{
    assert(
            ArrayUtils<int>::findSumOfAbsoluteDifferenceOfAllPairs({1,2,3,4,5})
            == 20);
    assert(
            ArrayUtils<int>::findSumOfAbsoluteDifferenceOfAllPairs({2,3,5,7})
            == 17);
    cout<<"------------"<<endl;
}
#endif


