
#include "bits/stdc++.h"
#include "libs/CommonLibs.h"
using namespace std;

// source - https://www.hackerrank.com/challenges/sherlock-and-cost/problem
// Created by Ashish Patel on 19/01/20.
//

/* explanation ( for more see editorial of problem from link )
Here are two columns '0' and '1'. '0' column indicates take present ar[i] = 1 while '1' column indicates take present ar[i] = b[i] i.e. the max possible value .
for dp[i][0] (present value = 1) :
either dp[i-1][0] + abs(1 - 1) as previous value=1 and present value=1 or dp[i-1][1] + abs(1 - ar[i-1]) as previous value=max and present value=1
for dp[i][1] ( present value = max i.e. arr[i] ) :
either dp[i-1][0] + abs(1 - ar[i]) as previous value=1 and present value=max or dp[i-1][1] + abs(ar[i]- ar[i-1]) as previous value=max and present value=max
therefore, dp[i][0]=max(dp[i-1][0],dp[i-1][1]+abs(ar[i-1]-1));
dp[i][1]=max(dp[i-1][0]+abs(ar[i]-1),dp[i-1][1]+abs(ar[i-1]-ar[i]));

 */


// Complete the cost function below.
int cost_dp_solution(vector<int> B) {
    int n =B.size();
    int dp[n][2];

    // if only 1 element in B, ans will be 0
    dp[0][0] =0;
    dp[0][1] =0;
    for(int i=1;i<n;i++){
        //if current is 1, if previous was 1 or B[i-1]
        dp[i][0]=max(dp[i-1][0]+abs(1-1),dp[i-1][1]+abs(1-B[i-1]));

        //if current is B[i], if previous was 1 or B[i-1]
        dp[i][1]=max(dp[i-1][0]+abs(B[i]-1),dp[i-1][1]+abs(B[i]-B[i-1]));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
}

int main() {
    vector<int> v={ 10, 1, 10, 1, 10};
    cost_dp_solution(v);
    return 0;
}
