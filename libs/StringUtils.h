#ifndef SAMPLE_STRING_UTILS_H
#define SAMPLE_STRING_UTILS_H

#include "CommonLibs.h"


/*works for vectors etc. also just change type*/
class StringUtils{

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
};

/*
 int main()
{
    string s="abcd";

    StringUtils::generateSubStrings(s); // 10
    cout<<"------------"<<endl;
    StringUtils::generateSubSequences(s);

}
 */

/* OUTPUT
following substrings are there for: abcd
a
ab
abc
abcd
b
bc
bcd
c
cd
d
------------
following subSequences are there for: abcd

a
b
ab
c
ac
bc
abc
d
ad
bd
abd
cd
acd
bcd
abcd
 */
#endif
