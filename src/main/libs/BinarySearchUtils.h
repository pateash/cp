#ifndef SAMPLE_BINARY_SEARCH_UTILS_H
#define SAMPLE_BINARY_SEARCH_UTILS_H

#include "CommonLibs.h"

#define INVALID -1

//tutorial - https://www.youtube.com/watch?v=GU7DpgHINWQ
class BinarySearchUtils {

    template<typename T>
    static int binarySearchSmallerOrEqualUtility(int start, int end, vector<T> &v, T value) {

        //base case same as all binary search problems
        if (start > end)
            return INVALID;

        int mid = (start + end) / 2;

        int ans;
        //if value is equal
        if (v[mid] == value)
            ans = mid;
        else if (value < v[mid]) { // value is smaller go to left
            ans = binarySearchSmallerOrEqualUtility(start, mid - 1, v, value);
        } else {//value is larger go to right

            int index = binarySearchSmallerOrEqualUtility(mid + 1, end, v, value);
            /*
             as we are finding equal or less here is a catch, it is possible that we don't get any value while going to right
             we might get nothing ( INVALID),
             in this case the answer is this index.
             Reason - we have to find equal or less than value, which is already greater than v[mid], so if we do not find any value there,
             this is ofcourse the answer.
            */
            if (index == INVALID) //could not able to find solution at the right side
                ans = mid;
            else
                ans = index; // if solution is found
        }
        return ans;
    }

    template<typename T>
    static int binarySearchGreaterOrEqualUtility(int start, int end, vector<T> &v, T value) {

        //base case same as all binary search problems
        if (start > end)
            return INVALID;

        int mid = (start + end) / 2;

        int ans;
        //if value is equal
        if (v[mid] == value)
            ans = mid;
        else if (value > v[mid]) { // value is greater simply go to right ( at least greater than value required )
            ans = binarySearchGreaterOrEqualUtility(mid + 1, end, v, value);
        } else {//value is smaller go to left with check for invalid result

            int index = binarySearchGreaterOrEqualUtility(start, mid - 1, v, value);

            if (index == INVALID) //could not able to find solution at the right side
                ans = mid;
            else
                ans = index; // if solution is found
        }
        return ans;
    }

public:

    /*this method returns an index of element equal(if exists in array) or just greater in sorted array in O(log n)*/
    template<typename T>
    static int binarySearchSmallerOrEqual(vector<T> &v, T value) {
        return binarySearchSmallerOrEqualUtility(0, v.size() - 1, v, value);
    }

    /*this method returns an index of element equal(if exists in array) or just greater in sorted array in O(log n)*/
    template<typename T>
    static int binarySearchGreaterOrEqual(vector<T> &v, T value) {
        return binarySearchGreaterOrEqualUtility(0, v.size() - 1, v, value);
    }

    template<typename T>
    static T binarySearchSmallerOrEqualv2(vector<T> &v, T value) {
        T ans = INVALID;// keep INT_MAX for int and LONG_MAX for long
        int low = 0, high = v.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // works and avoids overflow incase low+high > INT_MAX
            if (v[mid] <= value) { // first v[mid] >=value
                ans = v[mid];
                low = mid + 1;
            } else {
                high = mid - 1; // go and check if we able to find anything smaller
            }
        }
        return ans;
    }

    // this  is also called lowerbound - start of the range of similar elements, as we know upperbound is the pointer pointing the end of the range.
    // works and avoids overflow incase low+high > INT_MAX
    template<typename T>
    static T binarySearchGreaterOrEqualv2(vector<T> &v, T value) {
        T ans = INVALID;
        int low = 0, high = v.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] >= value) { // first v[mid] >=value
                ans = v[mid]; // update
                high = mid - 1; // go and check if we able to find anything smaller
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }


    // smallest element in sorted and rotated array
    // assumption there are not duplicates

    template<typename T>
    static T binarySearchSmallestElementInRotatedArray(vector<T> v) {

        int n = v.size();

        if(n==1)
            return v[0];

        if(v[0] < v[n-1])
            return v.front(); // no rotation is done ( first < last )

        int low=0,high=n-1;

/*
 * We need to find split, ie. where the rotation is, then we can find next element as ans.
 * ex. { 4, 5, 6, 7 , 0, 1,2},
 * rotation is done ^^^, so answer is 0.
 */
        int ans;
        int first = v[0];
        while(low<=high){
            // Find the mid element
            int mid=low+(high-low)/2;

            // are we in the bigger part or the smaller part
            if(v[mid] >= first){ //bigger part, go to the right
                low = mid+1;
            } else { // go to the left part, answer could be this or min then this one.
                ans = v[mid];
                high = mid - 1;
            }
        }
        return ans;
    }
};

void testBinarySearchUtils() {
   vi v={10,20,30,40,50};

   // --------- equal of smaller

   //   int index=BinarySearchUtils::binarySearchSmallerOrEqual(v,09);
//   int ans=v[index];
//   cout<<index<<" :"<<ans<<endl;


    assert(30==v[BinarySearchUtils::binarySearchSmallerOrEqual<int>(v,30)]);
    assert(20==v[BinarySearchUtils::binarySearchSmallerOrEqual<int>(v,21)]);
    assert(30==v[BinarySearchUtils::binarySearchSmallerOrEqual<int>(v,31)]);

    //if the number is even smaller than the first element, Index is invalid
    assert(INVALID==BinarySearchUtils::binarySearchSmallerOrEqual<int>(v,9));

    //if the number is even larger than the last element
    assert(50==v[BinarySearchUtils::binarySearchSmallerOrEqual<int>(v,9999)]);

    //version_2, value<=x( this returns value instead of index)

    assert(30 == BinarySearchUtils::binarySearchSmallerOrEqualv2<int>(v,30));
    assert(20 == BinarySearchUtils::binarySearchSmallerOrEqualv2<int>(v,21));
    assert(30 == BinarySearchUtils::binarySearchSmallerOrEqualv2<int>(v,31));

    //if the number is even smaller than the first element, Index is invalid
    assert(INVALID == BinarySearchUtils::binarySearchSmallerOrEqualv2<int>(v,9));

    //if the number is even larger than the last element
    assert(50 == BinarySearchUtils::binarySearchSmallerOrEqualv2<int>(v,9999));



    // --------- equal of greater


//      int index=BinarySearchUtils::binarySearchGreaterOrEqual(v,9);
//   int ans=v[index];
//   cout<<index<<" :"<<ans<<endl;


    assert(30==v[BinarySearchUtils::binarySearchGreaterOrEqual<int>(v,30)]);
    assert(30==v[BinarySearchUtils::binarySearchGreaterOrEqual<int>(v,21)]);
    assert(40==v[BinarySearchUtils::binarySearchGreaterOrEqual<int>(v,31)]);

    //if the number is even larger than the last element, Index is invalid
    assert(INVALID==BinarySearchUtils::binarySearchGreaterOrEqual<int>(v,9999));

    //if the number is even smaller than the first element
    assert(10==v[BinarySearchUtils::binarySearchGreaterOrEqual<int>(v,9)]);


    // LOWER BOUND version_2, value>=x( this returns value instead of index)
    assert(30== BinarySearchUtils::binarySearchGreaterOrEqualv2<int>(v, 30));
    assert(30== BinarySearchUtils::binarySearchGreaterOrEqualv2<int>(v, 21));
    assert(40== BinarySearchUtils::binarySearchGreaterOrEqualv2<int>(v, 31));

    //if the number is even larger than the last element, return INVALID
    assert(INVALID== BinarySearchUtils::binarySearchGreaterOrEqualv2<int>(v, 9999));

    //if the number is even smaller than the first element, Index is invalid
    assert(10== BinarySearchUtils::binarySearchGreaterOrEqualv2<int>(v, 9));


    // Binary searching smallest element in sorted and rotated array
    assert(0 == BinarySearchUtils::binarySearchSmallestElementInRotatedArray(
            vector<int>({ 4, 5, 6,7 , 9, 0,1})));
    assert(1==BinarySearchUtils::binarySearchSmallestElementInRotatedArray(
            vector<int>({ 4, 5, 6,7 , 9, 1,2})));
    assert(0==BinarySearchUtils::binarySearchSmallestElementInRotatedArray(
            vector<int>({ 4, 5, 6,7 , 9, 0,2})));

    assert(1==BinarySearchUtils::binarySearchSmallestElementInRotatedArray(
            vector<int>({2, 1})));


}

#endif
