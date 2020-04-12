#include<bits/stdc++.h>
#include<string>
#define llu long long unsigned int
#define ll long long int
#define mp make_pair
#define pr(n)  printf("%d",n)
#define prl(n) printf("%lld",n)
#define prf(n) printf("%f",n)
#define nl printf("\n")
#define sp printf(" ")
#define sc(n)  scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scf(n) scanf("%f",&n)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define vi vector<int>
#define vl vector<long>
using namespace std;
bool allgreater(vector<int>&a,vector<int>&b,int x){
    if(b[0]>a[1]&& x>a[1])
            return true;
    return false;
}
bool twogreater(vector<int>&a,vector<int>&b,int x){
   if(b[0]>a[2]&&b[1]>a[2]||b[0]>a[2]&&x>a[2]||b[1]>a[2]&&x>a[2])
    return true;
   else
    return false;
}
int solve(vector<int>&a,vector<int>&b,bool cards[]){
  int i=1;
  while(cards[i]){
    i++;
  }
   int x=i;
    if(x>52)
    return -1;
   if(allgreater(a,b,x)||twogreater(a,b,x))
    return x;


   i=a[1]+1;
  while(cards[i]){
    i++;
  }
   x=i;

   if(x>52)
    return -1;
   if(allgreater(a,b,x)||twogreater(a,b,x))
    return x;
   i=a[2]+1;
  while(cards[i]){
    i++;
  }
   x=i;

   if(x>52)
    return -1;
   if(allgreater(a,b,x)||twogreater(a,b,x))
    return x;
   return -1;
}
int main()
{
    vector<int>a(3),b(2);

 int x=1,ans=false;;
 while(cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]){
    if(a[0]||a[1]||a[2]||b[0]||b[1]){
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
    bool cards[53]={false};
    for(int i=0;i<a.size();i++)
        cards[a[i]]=true;
    for(int i=0;i<b.size();i++)
        cards[b[i]]=true;
    cout<<solve(a,b,cards)<<endl;
    }
     else
        break;
 }
return  0;
}
/*
10 20 30 40 50
10 20 30 4 5 
10 20 30 4 50
10 20 30 25 50 
10 20 30 15 50 
10 20 30 5 50
10 20 30 5 25
10 20 30 25 26
10 20 30 15 26  



*/
