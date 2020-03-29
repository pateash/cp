#ifndef SAMPLE_BINARY_SEARCH_UTILS_H
#define SAMPLE_BINARY_SEARCH_UTILS_H

#include "CommonLibs.h"

#define INVALID -1

class BinarySearchUtils{

    template<typename T>
    static int binarySearchMinOrEqualUtility(int start, int end,vector<T>& v, T value) {

        //base case same as all binary search problems
        if(start>end)
            return INVALID;

        int mid=(start+end)/2;

        int ans;
        //if value is equal
        if(v[mid]==value)
            ans= mid;
        else if(value < v[mid]){ // value is smaller go to left
            ans = binarySearchMinOrEqualUtility(start,mid-1,v,value);
        }
        else{//value is larger go to right

            int index=binarySearchMinOrEqualUtility(mid+1,end,v,value);
            /*
             as we are finding equal or less here is a catch, it is possible that we don't get any value while going to right
             we might get nothing ( INVALID),
             in this case the answer is this index.
             Reason - we have to find equal or less than value, which is already greater than v[mid], so if we do not find any value there,
             this is ofcourse the answer.
            */
            if(index==INVALID) //could not able to find solution at the right side
                ans = mid;
            else
                ans= index; // if solution is found
        }
        return ans;
    }

    template<typename T>
    static int binarySearchMaxOrEqualUtility(int start, int end,vector<T>& v, T value) {

        //base case same as all binary search problems
        if(start>end)
            return INVALID;

        int mid=(start+end)/2;

        int ans;
        //if value is equal
        if(v[mid]==value)
            ans= mid;
        else if(value > v[mid]){ // value is greater simply go to right ( at least greater than value required )
            ans = binarySearchMaxOrEqualUtility(mid+1,end,v,value);
        }
        else{//value is smaller go to left with check for invalid result

            int index=binarySearchMaxOrEqualUtility(start,mid-1,v,value);

            if(index==INVALID) //could not able to find solution at the right side
                ans = mid;
            else
                ans= index; // if solution is found
        }
        return ans;
    }

public:

    /*this method returns an index of element equal(if exists in array) or just greater in sorted array in O(log n)*/
    template<typename T>
    static int binarySearchMinOrEqual(vector<T>& v, T value){
        return binarySearchMinOrEqualUtility(0,v.size()-1,v,value);
    }

    /*this method returns an index of element equal(if exists in array) or just greater in sorted array in O(log n)*/
    template<typename T>
    static int binarySearchMaxOrEqual(vector<T>& v, T value){
        return binarySearchMaxOrEqualUtility(0,v.size()-1,v,value);
    }

};

/* int main()
{
   vi v={10,20,30,40,50};

   // --------- equal of smaller

   //   int index=BinarySearchUtils::binarySearchMinOrEqual(v,09);
//   int ans=v[index];
//   cout<<index<<" :"<<ans<<endl;


    assert(30==v[BinarySearchUtils::binarySearchMinOrEqual<int>(v,30)]);
    assert(20==v[BinarySearchUtils::binarySearchMinOrEqual<int>(v,21)]);
    assert(30==v[BinarySearchUtils::binarySearchMinOrEqual<int>(v,31)]);

    //if the number is even smaller than the first element, Index is invalid
    assert(INVALID==BinarySearchUtils::binarySearchMinOrEqual<int>(v,9));

    //if the number is even larger than the last element
    assert(50==v[BinarySearchUtils::binarySearchMinOrEqual<int>(v,9999)]);


   // --------- equal of greater


//      int index=BinarySearchUtils::binarySearchMaxOrEqual(v,9);
//   int ans=v[index];
//   cout<<index<<" :"<<ans<<endl;


    assert(30==v[BinarySearchUtils::binarySearchMaxOrEqual<int>(v,30)]);
    assert(30==v[BinarySearchUtils::binarySearchMaxOrEqual<int>(v,21)]);
    assert(40==v[BinarySearchUtils::binarySearchMaxOrEqual<int>(v,31)]);

    //if the number is even larger than the last element, Index is invalid
    assert(INVALID==BinarySearchUtils::binarySearchMaxOrEqual<int>(v,9999));

    //if the number is even smaller than the first element
    assert(10==v[BinarySearchUtils::binarySearchMaxOrEqual<int>(v,9)]);


    return 0;
}
*/


#endif
