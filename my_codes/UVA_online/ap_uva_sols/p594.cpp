#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;

 while(scanf("%d",&n)!=EOF){
    bitset<32>bs(n);
    string s=bs.to_string();
  // cout<<s<<endl;
    string temp="";
    temp+=string(s.begin()+24,s.end());
    temp+=string(s.begin()+16,s.begin()+24);
    temp+=string(s.begin()+8,s.begin()+16);
    temp+=string(s.begin(),s.begin()+8);
  // cout<<temp<<endl;
  bitset<32>news(temp);
 // cout<<news<<endl;
   cout<<n<<" converts to "<<(int)news.to_ulong()<<endl;
 }
}
