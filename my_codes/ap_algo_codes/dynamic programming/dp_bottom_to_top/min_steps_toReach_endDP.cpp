#include <bits/stdc++.h>
using namespace std;
 
int minJumps(int arr[],int n){
    //n is the last index on which we have to reach
    //dp[i] represents the min no. of steps require to reach end from ith index
    // here we are filling from end as reaching end from end is 0
    int dp[n+1];//n is last index
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
       int mine=INT_MAX; 
       if(arr[i]==0)//if 0 then set it to infinity so no one could reach
           dp[i]=INT_MAX;
       else{
          for(int j=i+1;j<=n&&j<=i+1+arr[i];j++)
              mine=min(mine,dp[j]);
          dp[i]=mine+1; 
        }
     }
    for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
  return dp[0];   
}
// Driver program to test above function
int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size-1));
    return 0;
}