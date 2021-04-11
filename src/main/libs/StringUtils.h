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
};

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
