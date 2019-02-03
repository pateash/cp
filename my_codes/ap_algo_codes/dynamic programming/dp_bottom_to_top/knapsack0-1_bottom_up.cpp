#include <bits/stdc++.h>
/*
SOLUTION-write the recursive solution in bottom approach so that
 smaller value form bigger ans;
 int find_max_profit(int n,int capacity)//n size
{
//AT EACH STEP n represent index just more than current index
  if(n-1<0)//if all are done
        return 0;
  if(capacity<weights[n-1])//check for ith object
        return find_max_profit(n-1,capacity);
  else
  return max(find_max_profit(n-1,capacity),profits[n-1]+find_max_profit(n-1,capacity-weights[n-1]));
}


*/

using namespace std;
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int sum, int wt[], int val[], int size)
{
    //W is sum required
    int dp[size+1][sum+1];
    // index i will represent ith item,(we have to handle i=0 otherwise i-1 will not be available)
    //and sum from 0 to sum
    for(int i=0;i<=size;i++)
    for(int s=0;s<=sum;s++){
        if(i==0||s==0){
         //base case
         //if only 0 item or 0 sum is required
         dp[i][s]=0;
        }
        else if(wt[i-1]>s)//we have to handle it otherwise s-wt[i-1] will not available there
            dp[i][s]=dp[i-1][s];
        else
            dp[i][s]=max(dp[i-1][s],val[i-1]+dp[i-1][s-wt[i-1]]);
    }
//    for(int i=0;i<size;i++){
//    for(int s=0;s<=sum;s++)
//        cout<<dp[i][s]<<" ";
//    cout<<endl;
//    }
return dp[size][sum];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
//int val[] = {1, 4, 5,7};
//    int wt[] = {1,3,4,5};
//    int  W = 7;

    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
