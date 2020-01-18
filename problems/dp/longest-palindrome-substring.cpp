// A C++ dynamic programming
// solution for longest palindrome

#include "libs/CommonLibs.h"
using namespace std;

// This function prints the longest palindrome substring
// It also returns the length of the longest palindrome
int longestPalSubstr(string &str)
{
    // get length of input string
    int n = str.size();

    // dp[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else dp[i][j] will be true
    bool dp[n][n];

    memset(dp, 0, sizeof(dp)); // initially all marked as false

    // All substrings of length 1 are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Length is: " <<maxLength<<endl;
    cout << "Longest palindrome substring is: \n";
    cout<<str.substr(start,maxLength)<<endl;

    // return length of LPS
    return maxLength;
}

// Driver Code
int main()
{
    string curdir = "/Users/ashish/Desktop/code/";
    if (
            freopen(string(curdir + "in.txt").c_str(), "r", stdin)
            &&
            freopen(string(curdir + "out.txt").c_str(), "w", stdout)
            );
    else {
        cout << "ERROR: " << strerror(errno) << endl;
        exit(0);
    }
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        longestPalSubstr( str );
        cout<<"---------\n";
    }
    return 0;
}

/* Input
4
abbac
addaa
abcd
abcbcabbacba
 */

/* OUTPUT
Length is: 4
Longest palindrome substring is:
abba
---------
Length is: 4
Longest palindrome substring is:
adda
---------
Length is: 1
Longest palindrome substring is:
a
---------
Length is: 8
Longest palindrome substring is:
bcabbacb
---------
 */
