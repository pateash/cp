#include<bits/stdc++.h>
using namespace std;

string lcs(char A[],char B[],int m,int n)
  //we will have to keep 0 index empty because in base case the size
  //of a string may reduce to 0,so size int main()
{
  int dp[m+1][n+1];
  for(int i=0;i<n+1;i++)
  {
      dp[i][0]=0;
      dp[0][i]=0;
  }
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
  {
      //cout<<A[i-1]<<" "<<B[j-1]<<endl;
      if(A[i-1]==B[j-1]){//because Character arrays here following 0 based indexing
            dp[i][j]=dp[i-1][j-1]+1;
      //   cout<<"matches"<<endl;
       }
       else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
       //cout<<"not matches"<<endl;
       }
  }
 //generating lcs
 int length=dp[m][n];
 int i=m,j=n;
 string lcsstr="";
 while(i!=0&&j!=0){//we do not reach to 0 index of any
    if(A[i-1]==B[j-1]){//we have to -1 because String is following 0 inde
        lcsstr+=A[i-1];
        i--;
        j--;
    }else
    {
        if(dp[i][j-1]==dp[i][j])
            j--;
        else
           i--;
    }
   }
  reverse(lcsstr.begin(),lcsstr.end());
  return lcsstr;
}
int main()
{
//  char X[] = "AGGTAB";
//  char Y[] = "GXTXAYB";
char X[]="ABCDGH";
char Y[]="AEDFHR";
  int m = strlen(X);
  int n = strlen(Y);
  string str=lcs( X, Y, m, n );
  printf("Length of LCS is %d\n",str.size() );
  cout<<"subsequence is "<<str<<endl;
  return 0;
}
