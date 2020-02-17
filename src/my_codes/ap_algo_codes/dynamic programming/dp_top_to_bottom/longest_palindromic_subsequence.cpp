/*PROBLEM-
Given a sequence, find the length of the longest palindromic subsequence in it.
 For example, if the given sequence is “BBABCBCAB”, 
 then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. 
 “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.

SOLUTIONS-
//here dp[i][j] represents length of the LPS from i to j
algo solve(str,i,j)
{
if(i>j)//may be when i=i+1 and j=j-1 in last case
return 0;
if(i==j)
	return s[i]==s[j]?1:0;
else if(s[i]==s[j])
   return 2+solve(str,i+1,j-1);
else 
   return max(solve(str,i+1,j),solve(str,i,j-1))
 }
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;
vector<vector<int>>dp_table;
//here dp_table[i][j] represents max. palindromic subsequence from i to j

int solve(string &s ,int start,int end){
    if (dp_table[start][end]!=-1)
        return   dp_table[start][end];
    if(start>end)
        dp_table[start][end]=0;
    else if(start==end)
        dp_table[start][end]=(s[start]==s[end])?1:0;
    else if(s[start]==s[end])
        dp_table[start][end]= 2+solve(s,start+1,end-1);
    else
        dp_table[start][end]= max(solve(s,start+1,end),solve(s,start,end-1));
    return dp_table[start][end];
}
//GENERATING THE LPS FROM DP(tushar roy's videos)
string lps_subseq(string & s,int length,int lastIndex)
{//this produces any one the subsequence of max length(there may be many)
    //we know that we get ans at 0,lastIndex
    string seq;
    seq.resize(length);//making string of size needed
    int i=0,j=lastIndex;//starting from last ans block
    int index=0;
    while(true){
        if(dp_table[i][j]==0)
            break;
        if(dp_table[i][j]==1)
        {
            seq[index]=s[i];//+1 karna solution dekhke
            seq[seq.size()-index-1]=s[j];//-1 karna pada ya pahle do no ko adjust karlo phir assign karo
            index++;
            break;
        }
        //ek se bhi match kare to us par chale jao(left ya down)
        //agar na kare to dekho ki diagonally aye the kya(jab dono equal the)
        if(dp_table[i][j]==dp_table[i+1][j])
        {
            i++;
        }
        else if(dp_table[i][j]==dp_table[i][j-1])
            j--;
        else if(dp_table[i][j]==dp_table[i+1][j-1]+2)
        {
            //go  and add both characters

            seq[index]=s[i];//-1/+1 nahi karna pada pahle ki kar liya
            seq[seq.size()-index-1]=s[j];
         index++;
         i++;j--;
        }
    }
    return seq;
}


template<typename  T>
void show_2d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        for(auto it2=it->begin();it2!=it->end();it2++) {
            if(*it2==-1)

                cout << setw(5) << "N";
            else
                cout << setw(5) << *it2;
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    string s="geeksforgeeks";
    // cin>>s;
    dp_table.resize(s.size());
    for(int i=0;i<s.size();i++){
        dp_table[i].resize(s.size(),-1);
    }
    int seqLength=solve(s,0,s.size()-1);
    cout<<"longest palindric substring lenght:"<<seqLength;
    cout<<"dp_table is "<<endl;
    show_2d(dp_table);
    cout<<"subsequence is "<<lps_subseq(s,seqLength,s.size()-1);
    return 0;
}
