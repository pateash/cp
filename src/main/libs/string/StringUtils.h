#ifndef SAMPLE_STRING_UTILS_H
#define SAMPLE_STRING_UTILS_H

#include "../CommonLibs.h"

/*works for vectors etc. also just change type*/
class StringUtils{
public:
    static const char ENCODING_DELIMITER = '#';
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
     static int generateSubStrings(string &s){
        int count=0;
        /* total possible substring: n(n+1)/2 , O(n^2) */
         cout<<"following substrings are there for: "<<s<<endl;
         for (int i = 0; i < s.size(); ++i) {
             string substr="";
             for (int j = i; j < s.size() ; ++j) {
                 substr+=s[j];
                 cout<<substr<<endl;
                 count++;
             }
         }
         return count;
    }

     static int generateSubSequences(string &s){
        /* total possible substring: 2^n ( one is empty) , O(2^n*n) */
         cout<<"following subSequences are there for: "<<s<<endl;
         int count =0;
         int n=pow(2,s.size());

         for (int i = 0; i < n; ++i) { // all subsequences
             string substr="";

             for (int j = 0; j <s.size(); ++j) { // finding set bit and accordingly creating subsequence
                 if(i & (1<<j))
                     substr+=s[j];
             }
             count++;
             cout<<substr<<endl;
         }
         return count;
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
        static string encode(vector<string> &inputStrs){
            string encodedStr = "";
            for(auto s: inputStrs){
                encodedStr+= to_string(s.size())+ENCODING_DELIMITER+s;
            }
            return encodedStr;
        }

        static vector<string> decode(string &encodedStr){
            vector<string> decodedStrs;
            int index=0; // will always be on the starting or length
            while(index<encodedStr.size())
            {
                // search for the first occurence of delimiter after i index in string and return index of first find
                // string::npos if no occurence found
               auto delIndex =  encodedStr.find(ENCODING_DELIMITER,index);
               // length will be between i and pos
               auto strLength = stoi(encodedStr.substr(index,delIndex-index+1)); // pos, length need to be passed
               //actual string is starting from delIndex+1, and with strLength
               auto actualStr = encodedStr.substr(delIndex+1, strLength);
               decodedStrs.push_back(actualStr);
               // now index will move to new length
               index = delIndex+strLength+1;
            }
           return decodedStrs;
        }
};

void testStringUtils()
{
    vector<string> str = {"lint","code","love","you"};
    string encodedStr = StringUtils::encode(str);
    assert(encodedStr=="4#lint4#code4#love3#you");
    vector<string> decodedStrs = StringUtils::decode(encodedStr);
    for(int i=0;i<str.size();i++)
        assert(str[i]==decodedStrs[i]);

    str = {"we", "say", ":", "yes"};
    encodedStr = StringUtils::encode(str);
    assert(encodedStr=="2#we3#say1#:3#yes");
    decodedStrs = StringUtils::decode(encodedStr);
    for(int i=0;i<str.size();i++)
        assert(str[i]==decodedStrs[i]);

    // Substrings
    string s="abc";
    assert(StringUtils::generateSubStrings(s)==6);
    cout<<"------------"<<endl;

    assert(StringUtils::generateSubSequences(s)==8);
    StringUtils::generateAllPermutations(s); // 6
}
#endif
