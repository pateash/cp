#include <bits/stdc++.h>

using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
 int dp[n+1][k+1];
 for(int i=0;i<=n;i++){
    for(int j=0;j<=i;j++){//because in nCr r can't be greater than n
        if(j==0||j==i){
            dp[i][j]=1;
        }
        else{
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
      }
    }
 }
  return dp[n][k];
}
int main()
{
    int n = 10, k = 5;
    printf("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k));
    return 0;
}
