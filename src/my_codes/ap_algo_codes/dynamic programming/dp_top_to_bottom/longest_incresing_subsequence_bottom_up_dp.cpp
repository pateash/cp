
/*
PROBLEM-
The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence
such that all elements of the subsequence are sorted in increasing order. For example,
length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

SOLUTION-
  lis(i) i.e.length of subsequence having arr[i] as last element,
  will be equal to maximum of all lis[j] if arr[j]<arr[i],
  means if arr[j]<arr[i] we can add  arr[i] to the subsequence lis(j);
  so we have to go from j=1 to i-1 and find length of all and add arr[i] to it
  and update the dp_table;
   lis(i)= max(lis[j]) + 1
           j=0 to i-1
                   lis(4)
                 /   |    \
         lis(3)    lis(2)    lis(1)
        /     \     /
  lis(2)  lis(1)   lis(1)
  /
lis(1)
*/
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* lis() returns the length of the longest increasing
   subsequence in arr[] of size n */
int lis( int arr[], int n )
{//here we are only finding length not array
   int *lis_dp, i, j, max = 0;
   lis_dp = new int[n ];

   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis_dp[i] = 1;//initialling all to 1
    /*
    author@ashishPatel
         here lis[i]=== max. length of subsequence having arr[i] as last element
   */

   // Compute optimized LIS values in bottom up manner
   // starting from 1 as length of substring ending with arr[0] will always be 1 (starting index)
   for ( i = 1; i < n; i++ ){
       for ( j = 0; j < i; j++ ){
         if(arr[j]<arr[i]){
           if(lis_dp[i]<lis_dp[j]+1)
           lis_dp[i]=lis_dp[j]+1;
         //if we can add a number than length will be at length of that+1
         }
        }
    }
    /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis_dp[i] )
         max = lis_dp[i];

   /* Free memory to avoid memory leak */
   free( lis_dp );

   return max;
}

/* Driver program to test above function */
int main()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LIS is %d\n", lis( arr, n ) );
  return 0;
}
//OUPUT- Length of LIS is 5
