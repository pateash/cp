#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
    string INVALID="0";
    string solve(string &s, int i, int j) {
// BASE CASEs
        if(j==i) return string(1,s[i]); // one length 1, it is an palindrome
        if(j<i) return ""; // also a palindrome
        // if(j==i+1){
        //   if(s[i]==s[j]) return string(2,s[i]); // length 2, and character matches so its a palindrome
        //   else return INVALID; // length 2, but doesn't match any one can be expect
        // }

// OTHER CASES
        if(s[i] == s[j]) { // this can be included in palindrome
          auto x= solve(s,i+1,j-1);
          cout<<"matched"<<endl;
           cout<<x<<endl;
          if(x!=INVALID)
            return s[i]+x+s[j];
          else return INVALID;
        }
        else{ // cant match boundry try both sides
         auto x = solve(s, i+1,j);
          cout<<"not matched"<<endl;

          cout<<x<<endl;

         auto y= solve(s,i,j-1);
          cout<<y<<endl;

         if(x==INVALID) return y;
         if(y==INVALID) return x;
         if(x.size()>y.size()) return x;
         else return y;
        }
    }
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        return solve(s,0,s.size()-1);
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();

    cout<<s->longestPalindrome("aacabdkacaa")<<endl;

    return 0;
}
