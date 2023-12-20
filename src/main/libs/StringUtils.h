#ifndef SAMPLE_STRING_UTILS_H
#define SAMPLE_STRING_UTILS_H

#include "CommonLibs.h"


/*works for vectors etc. also just change type*/
class StringUtils{

    static void generatePermutationUtils(int i, string &s){
        /* if i has come to last of string*/
        if(i==s.size()-1) {
            cout<<s<<endl;
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            swap(s[i],s[j]);
            generatePermutationUtils(i+1,s);
            swap(s[i],s[j]); //backtrack
        }
    }

public:
     static void generateSubStrings(string &s){

        /* total possible substring: n(n+1)/2 , O(n^2) */
         cout<<"following substrings are there for: "<<s<<endl;
         for (int i = 0; i < s.size(); ++i) {
             string substr="";
             for (int j = i; j < s.size() ; ++j) {
                 substr+=s[j];
                 cout<<substr<<endl;
             }
         }
    }

     static void generateSubSequences(string &s){
        /* total possible substring: 2^n ( one is empty) , O(2^n*n) */
         cout<<"following subSequences are there for: "<<s<<endl;

         int n=pow(2,s.size());

         for (int i = 0; i < n; ++i) { // all subsequences
             string substr="";

             for (int j = 0; j <s.size(); ++j) { // finding set bit and accordingly creating subsequence
                 if(i & (1<<j))
                     substr+=s[j];
             }
             cout<<substr<<endl;
         }
    }

     static void generateAllPermutations(string &s){
        /* total possible permutations: !n, time complexity - O(n*n!)
         * Algo link - https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
         * */
         cout<<"following permutations are there for: "<<s<<endl;
          generatePermutationUtils(0,s);
        }

        /* code for encoding and decoding problem  -
         * https://onedrive.live.com/view.aspx?resid=9B1BD26B02F2442D%21153&id=documents&wd=target%28LeetCode%20Problems%2FArray%20and%20Hashing.one%7C5F798AC7-7179-E64C-84A2-FB1CD88468EC%2FEncode%20and%20Decode%20Strings%20-%20H%7C01B8C7E8-6458-5944-A3A5-B1E1939AFA1C%2F%29
onenote:https://d.docs.live.net/9b1bd26b02f2442d/Documents/notes/Competetive%20Programming%20Notes/LeetCode%20Problems/Array%20and%20Hashing.one#Encode%20and%20Decode%20Strings%20-%20H&section-id={5F798AC7-7179-E64C-84A2-FB1CD88468EC}&page-id={01B8C7E8-6458-5944-A3A5-B1E1939AFA1C}&end
        */
        static string encode(vector<string> &s){

        }

        static vector<string> decode(string &s){

        }
};

void testStringUtils()
{
//    assert(false);
//    assert(
//            ArrayUtils<int>::findSumOfAbsoluteDifferenceOfAllPairs({1,2,3,4,5})
//            == 20);
//    assert(
//            ArrayUtils<int>::findSumOfAbsoluteDifferenceOfAllPairs({2,3,5,7})
//            == 17);
    cout<<"------------"<<endl;
}

/*
 int main()
{
    string s="abc";

    StringUtils::generateSubStrings(s); // 10
    cout<<"------------"<<endl;

    StringUtils::generateSubSequences(s);
    s="abc";
    StringUtils::generateAllPermutations(s);
}
*/
/* OUTPUT
/Users/ashish/Desktop/code/cmake-build-debug/Sample
following substrings are there for: abc
a
ab
abc
b
bc
c
------------
following subSequences are there for: abc

a
b
ab
c
ac
bc
abc
following permutations are there for: abc
abc
acb
bac
bca
cba
cab
 */
#endif
