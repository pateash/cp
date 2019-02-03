/*
  this program is to find all possible palindromic partition of a string
  example - nitin
     these are possible partitions-
     1- n , i , t , i , n
     2- n , iti , n
     3- nitin

*/




#include<bits/stdc++.h>
using namespace std;
bool isPal(string&temp,int start,int end){//to check if a part of string is palindrome or not
    while(start<end){
        if(temp[start]!=temp[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void find_pal_partition(vector<vector<string>>&allParts,vector<string>&curPart,int start,int n,string& s){
//this fn generates all possible palindrome partitions and store to print when we want
    if(start==n){
     allParts.push_back(curPart);
     return;
   }

   for(int  i=start;i<n;i++){
      if(isPal(s,start,i))//if this part is palindrome then we can partition here and go on for another partition
      {
        curPart.push_back(s.substr(start,i+1-start));//jitna start se ange hai utne hi aur lelo
        find_pal_partition(allParts,curPart,i+1,n,s);//here we will start looking from i+1 because till i we have already partitioned
        //backtracking after done with generating all possible for a partition
        curPart.pop_back();
      }

   }
}
int main(){
  cout<<"enter the string"<<endl;
  string s;
  cin>>s;
  vector<vector<string>>allParts;//for storing all possible combinations n*n possible
  vector<string>curPart;//to store partition  on single time
  find_pal_partition(allParts,curPart,0,s.size(),s);
 cout<<"showing all parts"<<endl;
   for(int i=0;i<allParts.size();i++){
      for(int j=0;j<allParts[i].size();j++)
        cout<<allParts[i][j]<<" ";
    cout<<endl;
   }

return 0;
}
