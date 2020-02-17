#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include <string>
#include<algorithm>
/*
PROBLEM-
You are given an string as input which represents a path. You have to normalize that path inplace(NO EXTRA SPACE).

	e.g.
	     input : "\a\b\c\..\..\file.txt"
	     output: "\a\file.txt"
Hint: Double dot(..) means you have to skip the previous parent.

*/


using namespace std;
void leftShift(string&s,int start,int index){
    //shift the string so that the letters between start and index removed
  int offset=start;
  for(int i=index;i<s.size();i++){
    s[offset]=s[i];
    offset++;
  }
 }
string find_string(string &s){
 for(int i=s.size()-1;i>=2;i--){
   int count=0;
   //cout<<"character is "<<s[i]<<endl;
    while(i>=2&&s[i]=='\\' &&s[i-1]=='.'&&s[i-2]=='.')
    {
        count++;
        i-=3;
    }
   int     letterCut=3*count;//the letter to be cutted because they are ..\

   while(count!=0){
      do{
        letterCut++;//the letter to be cutted because they are parent directrory
        i--;
      }while(i>=0&&s[i]!='\\');
      leftShift(s,i+1,i+letterCut+1);
      count--;
   }
     s.resize(s.size()-letterCut);//resize after calculating total letter to be cut

  }
  return s;
}
int main() {
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    cout<<"ans: "<<find_string(s)<<endl;
    cout<<endl<<endl;
    }



}
