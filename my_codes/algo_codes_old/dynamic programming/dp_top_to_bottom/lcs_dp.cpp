#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>

/*
* LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
* A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
* For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
*  So a string of length n has 2^n different possible subsequences.
*        RECURSION TREE
                           lcs("AXYT", "AYZX")
                           /                \
            lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
              /            \                  /               \
   lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
   note-  as we can see there is overlapping subproblem lcs("AXY", "AYZ")  and  lcs("AXY", "AYZ")
*
*/
using namespace std;

// non DP simple solution
//let first s1[0....n],second s2[0....m]
// worst case(when both fn are called)
//T(n,m)=T(n-1,m)+t(n,m-1)= nearly 2^(n)(if n==m nearly equals)
int LCS(string s1, int i, string s2, int j) {
  if (i<0 || j<0)//all indexes of at least one string is done
    return 0;
  if (s1[i] == s2[j])
    return 1 + LCS(s1, i - 1, s2, j - 1);
  else
    return max(LCS(s1, i - 1, s2, j), LCS(s1, i, s2, j - 1));
}
//DP solution
//time complexity = total size of table(or max no. of queries) * work in each query 
//O(m*n)
vector<vector<int> >dp_table;
#define NIL -1 
//for checking availability in dp(use value which can never appear in table)
int lcs_dp(string s1, int i, string s2, int j)
{
  if (i < 0 || j < 0)
    return 0;
  if (dp_table[i][j] != NIL)
    return dp_table[i][j];
  if (s1[i] == s2[j])
    dp_table[i][j] = 1+ lcs_dp(s1, i - 1, s2, j - 1);
  else
    dp_table[i][j] = max(lcs_dp(s1, i, s2, j - 1), lcs_dp(s1, i - 1, s2, j));
  return dp_table[i][j];
}
int main() {
  string s1, s2;
  cout << "enter both strings" << endl;
  getline(cin,s1);
  getline(cin, s2);
  int m = s1.size();
  int n = s2.size();
  //non dp solution
  cout << "NON_DP:";
  cout << LCS(s1, m-1, s2, n-1)<<endl;
//dp solution
  
  //initialising dp_table m*n all to NIL
  for (int i = 0; i <m; i++)
  {
    vector<int>temp(n,NIL);
    dp_table.push_back(temp);
  }
  cout << "DP: "<<lcs_dp( s1, s1.size() - 1, s2, s2.size() - 1)<<endl;
  system("pause");
}