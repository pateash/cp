#include <iostream>

using namespace std;
/*
PROBLEM-
Write an efficient C program to find the sum of contiguous subarray
within a one-dimensional array of numbers which has the largest sum.
SOLUTION-
Simple idea of the Kadane's algorithm is to look for all positive contiguous segments of the array (max_this_subarray,this_start,this_end is used for traking).
And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this).
Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far
*/

/*
NOTE-LIMITATION
Algorithm doesn't work for all negative numbers.
It simply returns 0 if all numbers are negative.
For handling this we can add an extra phase before actual implementation.
The phase will look if all numbers are negative, if they are it will return maximum of them
(or smallest in terms of absolute value)
*/



int maxSubArraySum(int arr[],int n){
   int max_sofar;//represents maximum sum so far obtained
   int start_sofar,end_sofar;//represents starting and ending indexes of till find subarray
   
   int max_this_subarray;//represents maximum sum for present subarray
   int start_this,end_this;//represents start and end index of this subarray

   start_this=start_sofar=end_this=end_sofar=0;
   max_sofar=max_this_subarray=0;

   int maxe=INT_MIN;//this will used if max_sofar remains 0(means all are negative)
   for(int i=0;i<n;++i){
       max_this_subarray=max_this_subarray+arr[i];
       end_this=i;//end will be i always upto now

       if(max_this_subarray<0){//if this becomes less than 0 than this is not need so reset start and sum
          max_this_subarray=0;
          start_this=i+1;//new will start will be this
       }
       else if(max_this_subarray>max_sofar){
         max_sofar=max_this_subarray;
         start_sofar=start_this;
         end_sofar=end_this;
       }
    if(arr[i]>maxe)
        maxe=arr[i];
   }
   if(max_sofar==0){
    cout<<"all elements are negative\nSum:"<<maxe<<endl;
   }
   else{
        cout<<"Sum:"<<max_sofar<<" ["<<start_sofar<<","<<end_sofar<<"] "<<endl;
    }
}

int main()
{
 //  int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int a[] =  {-1,-2, -3, -1, -6,-3};

   int n = sizeof(a)/sizeof(a[0]);
  maxSubArraySum(a, n);
    return 0;
}
