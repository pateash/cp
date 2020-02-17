#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>

/*
Given two strings s1 and s2 and below operations that can performed on s1.
Find minimum number of edits (operations) required to convert ‘s1′ into ‘s2′.
1-Insert
2-Remove
3-Replace
All of the above operations are of equal cost.(if not then we can modify easily)
NOTE- we have to change only s1 and convert into s2
*/
using namespace std;

// non DP simple solution
//let first s1[0....n],second s2[0....m]
// worst case(when both fn are called)
int edit_distance_nondp(string s1, int m, string s2, int n) {
  //we can also start from first of both or last(same as the lcs)
  if (m < 0)
    //s1 becomes empty(we have traversed all)
    // now to convert we have to insert n remaining character
    // If first string is empty, the only option is to
    // insert all n characters of second string into first
    return n+1;//n+1 chars (n is index)
  else if (n < 0)
    //s2 become empty(we have traversed all)
    //now we have to remove all from s1(s1 has but should not)
    // If second string is empty, the only option is to
    // remove all m characters of first string
    return m+1;//m+1 chars (m is index)
  if (s1[m] == s2[n])//if same then no operation has to be done
    return edit_distance_nondp(s1, m - 1, s2, n - 1);
  else
  {
    //if not same then have to try all and return their min
    int ifinsertinS1 = edit_distance_nondp(s1, m, s2, n - 1);
    //if we insert in s1 then this mth character will be traversed in next round
    //but nth character of s2 is done because we have placed same char as s2[n] in s1
    int ifRemovefromS1 = edit_distance_nondp(s1, m - 1, s2, n);
    //if we remove mth character from s1 then mth character is done
    //but nth of s2 need to be done later
    int ifReplaceinS1 = edit_distance_nondp(s1, m - 1, s2, n-1);
    //if we replace s1[m] with s2[n] then both the chars are done
    //and we can move to the next chars of both the strings
    return 1 + min(ifinsertinS1, min(ifRemovefromS1, ifReplaceinS1));
    //we have to return the minimum cost
  }
}
//DP solution
//time complexity = total size of table(or max no. of queries) * work in each query
//O(m*n)
vector<vector<int> >dp_table;
#define NIL -1
//for checking availability in dp(use value which can never appear in table)
int edit_distance_dp(string s1, int m, string s2, int n) {
  if (m < 0)//insert all n+1 chars(here n is index total chars are n+1)
    return n+1;
  else if (n < 0)//remove all m+1 chars(m is index)
    return m+1;
  if (dp_table[m][n] != NIL)//if already calculated
    return dp_table[m][n];
  if (s1[m] == s2[n])
    return edit_distance_dp(s1, m - 1, s2, n - 1);
  else {

    int x = edit_distance_dp(s1, m, s2, n - 1);//insert
    int y = edit_distance_dp(s1, m - 1, s2, n);//delete
    int z = edit_distance_dp(s1, m - 1, s2, n - 1);//replace
    dp_table[m][n] = 1 + min(x, min(y, z));//one is cost of each
    return dp_table[m][n];
  }
}
int main() {
  string s1, s2;
  cout << "enter both strings" << endl;
  getline(cin, s1);
  getline(cin, s2);
  int m = s1.size();
  int n = s2.size();
  //non dp solution
  cout << "NON_DP:";
  cout << edit_distance_nondp(s1, m - 1, s2, n - 1) << endl;
  //dp solution

  //initialising dp_table m*n all to NIL
  for (int i = 0; i <m; i++)
  {
    vector<int>temp(n, NIL);
    dp_table.push_back(temp);
  }
  cout << "DP: " << edit_distance_dp(s1, s1.size() - 1, s2, s2.size() - 1) << endl;
  /*for (auto x : dp_table)
  {
    for (auto y : x)
      cout << y << " ";
    cout << endl;
  }
  system("pause");
  */
}
