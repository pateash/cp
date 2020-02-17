#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int CeilIndex(vector<int>A, int start, int end, int key)
{
   if(start>end)
    return -1;
   int mid=(start+end)/2;
   if(A[mid]==key)
    return mid;
   else if(A[mid]>key){
    int i=CeilIndex(A,start,mid-1,key);
    if(i==-1)
        return mid;
   }else
   return CeilIndex(A,mid+1,end,key);
}
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
vector<int> LongestIncreasingSubsequenceLength(int A[], int size)
{
    // Add boundary case, when array size is one
    vector<int>tailTable;
    //int *tailTable   = new int[size];
 //   int len; // always points empty slot

   // memset(tailTable, 0, sizeof(tailTable[0])*size);

    //tailTable[0] = A[0];
     tailTable.push_back(A[0]);

    for (int i = 1; i < size; i++)
    {
        if (A[i] < tailTable[0])
            // new smallest value
            tailTable[0] = A[i];

        else if (A[i] > tailTable[tailTable.size()-1])
            // A[i] wants to extend largest subsequence
            tailTable.push_back(A[i]);

        else
            // A[i] wants to be current end candidate of an existing
            // subsequence. It will replace ceil value in tailTable
            tailTable[CeilIndex(tailTable, 0, tailTable.size()-1, A[i])] = A[i];
    }

 return tailTable;
}

int main()
{
   int A[] = { 2, 5,-1,4 ,-2};
//   int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };

//    int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 ,100,200};
     int n = sizeof(A)/sizeof(A[0]);
    auto v=LongestIncreasingSubsequenceLength(A, n);
    printf("Length of Longest Increasing Subsequence is %d\n",
           v.size());

    //vector not represents the lis here as it will always replace table[0] with least
    cout<<"vector is"<<endl;
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
