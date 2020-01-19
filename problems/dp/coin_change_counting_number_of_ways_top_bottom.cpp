//source - https://www.hackerrank.com/challenges/coin-change/problem
//#include<bits/stdc++.h>
#include "libs/CommonLibs.h"
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
// n+1, sum+1
long dp[51][251];

long coin_change(int sum,int index, vector<long>&v){
    if(index<0 || sum<0) return 0;
    long &x=dp[index][sum];

    if(x!=-1) return x;
    if(sum==0) x=1;
    else
        x = coin_change(sum,index-1,v) +
            coin_change(sum-v[index],index,v);
    return x;
}
long coin_change(int sum, vector<long> arr) {

    if(sum == 0 || arr.size() == 0) return 0;

    memset(dp,-1,sizeof dp);
    return coin_change(sum, arr.size() - 1, arr);
}

// Driver program to test above function
int main()
{
    int i, j;
    vector<long>arr = {1, 2, 3};
    int sum=4; //ans -> 1111, 112, 22, 31
    printf("%d\n", coin_change(sum,arr));

    for (int l = 0; l < arr.size() ; ++l) {
        for (int k = 0; k < sum+1; ++k) {
            cout<<dp[l][k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
