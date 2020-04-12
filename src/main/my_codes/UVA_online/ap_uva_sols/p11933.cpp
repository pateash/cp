#include<bits/stdc++.h>
//types
#define llu long long unsigned int
#define ll long long int
//container
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
//IO
#define pr(n)  printf("%d",n)
#define prl(n) printf("%lld",n)
#define prf(n) printf("%f",n)
#define nl printf("\n")
#define sp printf(" ")
#define sc(n)  scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scf(n) scanf("%f",&n)
#define scd(n) scanf("%f",&n)
//function and loops
#define mp make_pair
#define repab(a,b) for(int i=(a);i<(b);i++)
#define rep(n) for(int i=0;i<n;i++)
#define repi(i,n) for(int (i)=0;(i)<n;(i)++)
#define repit(c) for(auto it=(c).begin();it!=(c).end();it++)
//reading all once
#define read(n) int n;sc(n)
#define readl(n) ll n;scl(n)
#define readf(n) float n;scf(n)
#define readd(n) double d;scd(n)
using namespace std;
template <typename T>
void show_2d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        for(auto it2=it->begin();it2!=it->end();it2++)
            cout<<*it2<<" ";
        cout<<endl;
    }
    cout<<endl;
}
template <typename T>
void show_pair1d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        cout<<it->first<<" --> "<<it->second;
        cout<<endl;
    }
    cout<<endl;
}
template <typename T,typename R>
void show_pair(pair<T,R> p){
    cout<<p.first<<"-> "<<p.second<<endl;
}
template <typename T>
void show_1d(T &container){
    cout<<"data in container is: "<<endl;
    for(auto it=container.begin();it!=container.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
template <typename  T>
void show_arr(T arr[],int size){
    cout<<"content in array is here"<<endl;
    for (int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}



int main()
{
 /*if(
      freopen("C:\\Users\\ashish_patel\\Documents\\CodeBlocks Project\\Sample\\in.txt","r",stdin)
      &&
      freopen("C:\\Users\\ashish_patel\\Documents\\CodeBlocks Project\\Sample\\out.txt", "w", stdout)
      );
     else {
     cout << "ERROR: " << strerror(errno) << endl;
     exit(0);
    }
 */  int n;
    while(sc(n),n){
        bitset<32>bs(n);
        string a,b;
        char turn='a';
        for(int i=0;i<32;i++){
            if(bs[i]){
                if(turn=='b') {
                    b +='1';
                    a += '0';
                    turn ='a';
                }
                else{
                    a+='1';
                    b+='0';
                    turn='b';
                }
            }
            else
            {a+='0';b+='0';}
            }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
     //   cout<<a<<" " <<b<<endl;

        bitset<32>ansa(a);
        bitset<32>ansb(b);
        cout<<int(ansa.to_ulong())<<" "<<int(ansb.to_ulong())<<endl;


    }

}
