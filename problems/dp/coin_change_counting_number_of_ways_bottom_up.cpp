//#include<bits/stdc++.h>
#include "libs/CommonLibs.h"
#define R 3
#define C 3
using namespace std;
int count(int arr[],int n,int sum){
    //sum could be zero also
    int dp[n][sum+1];//n is index of coins

    //base case when sum is 0, 1 solution
    //BASE CASES
    //that is do not take any coin
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            //j=0,ie sum=0 already done for all
            int if_include_coin=(j-arr[i]<0)?0:dp[i][j-arr[i]];
            //if j-arr[i]<0 then it will not be available

            int if_not_include_coin=(i==0)?0:dp[i-1][j];
            //if i==0 then i-1 will not be available

            dp[i][j]=if_include_coin+if_not_include_coin;
            //HERE + because we are calculating total no. of solution of both sides
            //but there in KNAPSACK we have to pick one which is giving more profit we can't include both so we had take max of both sides
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n-1][sum];
}
// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int sum=4;
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, m, sum));
    getchar();
    return 0;
}

/*OUTPUT
1 1 1 1 1
1 1 2 2 3
1 1 2 3 4
4
 */
