#include<bits/stdc++.h>
#include<conio.h>
#define R 3
#define C 3
using namespace std;
int minCost(int cost[R][C], int m, int n){
  int dp[m+1][n+1];
  for(int i=0;i<=m;i++)
  for(int j=0;j<=n;j++){
    if(i==0&&j==0)
        dp[i][j]=cost[i][j];
    else if(i==0)
        dp[i][j]=dp[i][j-1]+cost[i][j];
    else if(j==0)
        dp[i][j]=dp[i-1][j]+cost[i][j];
    else
        dp[i][j]=cost[i][j]+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
  }
 //GENERATING PATH
 //using reverse method
 int i=m,j=n;
 vector<pair<int,int>>vp;
 vp.push_back(make_pair(i,j));
 while(i!=0 && j!=0)//both should be zero
 {
     //now we have to find from which block we have reached there
     // we must have come from a block which has min value
     if(dp[i-1][j-1]<=dp[i][j-1]&&dp[i-1][j-1]<=dp[i-1][j])
     {
         //came from i-1,j-1, if it is min of three
         vp.push_back(make_pair(i-1,j-1));
         i--;j--;
     }
     else if(dp[i-1][j]<=dp[i-1][j-1]&&dp[i-1][j]<=dp[i][j-1])
     {
            vp.push_back(make_pair(i-1,j));
            i--;
     }
     else
     {
       vp.push_back(make_pair(i,j-1));
       j--;
     }
}
if(i!=0){
    while(i!=0)
        vp.push_back(make_pair(--i,0));
}
else if(j!=0){
     while(j!=0)
        vp.push_back(make_pair(0,--j));

}
cout<<"path is "<<endl;
  reverse(vp.begin(),vp.end());
  for(auto p:vp){
    cout<<p.first<<" "<<p.second<<endl;
  }
  return dp[m][n];
}
// Driver program
int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", minCost(cost, 2, 2));
   return 0;
}
