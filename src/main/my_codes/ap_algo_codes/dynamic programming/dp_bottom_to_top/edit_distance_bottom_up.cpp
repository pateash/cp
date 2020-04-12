#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int editDistDP(string A, string B, int m, int n)
{
      int dp[m+1][n+1];
     for(int i=0;i<=m;i++)
     {
         for(int j=0;j<=n;j++)
        {
            if(i==0){//boundry case
                dp[i][j]=j;
            }
            else if(j==0){//boundary case
                dp[i][j]=i;
            }
             else if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1];
             else
               dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
         }
     }
     return dp[m][n];
 }
// Driver program
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(), str2.length());

    return 0;
}
