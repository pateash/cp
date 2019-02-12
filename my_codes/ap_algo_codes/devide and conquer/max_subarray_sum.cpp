
//Q. max-subarray problem
/*
  INPUT: array of integers(positive or negative)
  OUTPUT: maximum sum ,we can modify to get indexes also
  LOGIC:  if we devide the array in two halves and then,
            the solution can be from left or right or from combination of both
            so, we will try all cases left or right is same as the original problems
            so we will write another function for the third case
      THERE IS ALSO KADANE's algorithm for solving this is O(n) time
*/
#include<bits/stdc++.h>
#define size 8
#define INF 1e9
using namespace std;
int find_max_crossarray(int arr[],int start,int end)
{
   int mid=(start+end)/2;
   int lsum=-INF;//so that update even if one element is there
   int tempsum=0;
   for(int i=mid;i>=0;i--)
   {
       tempsum=tempsum+arr[i];
        if(tempsum>lsum)
         lsum=tempsum;
   }
   tempsum=0;
   int rsum=-INF;
   for(int i=mid+1;i<size;i++)
   {
       tempsum=tempsum+arr[i];
        if(tempsum>rsum)
         rsum=tempsum;
   }
   return lsum+rsum;
}
int find_max_subarray(int arr[],int start,int end)
{
   if(start==end)//if only one element
        return arr[start];//only that element will be max sub array because if all are negative except one then it will be ans
   int mid=(start+end)/2;
   int lmax=find_max_subarray(arr,start,mid);
   int rmax=find_max_subarray(arr,mid+1,end);
   int cmax=find_max_crossarray(arr,start,end);
    return max(max(lmax,rmax),cmax);
}
int main()
{
    cout << "Enter array" << endl;
    int arr[size];
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<find_max_subarray(arr,0,size-1);
    return 0;
}
