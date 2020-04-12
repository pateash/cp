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


void solve(){
}
int power(int a,int b){
    if(b==0)return 1;
    if(b==1){ return a;}
    int sol=power(a,b/2);
    sol=sol*sol;
    if(b&1){
        sol*=a;
    }
    return sol;
}
struct corner{
    int weight;
    ll potency;
    corner():weight(0),potency(0){}
};
int main()
{
 /* if(
      freopen("C:\\Users\\ashish_patel\\Documents\\CodeBlocks Project\\Sample\\in.txt","r",stdin)
      &&
      freopen("C:\\Users\\ashish_patel\\Documents\\CodeBlocks Project\\Sample\\out.txt", "w", stdout)
      );
     else {
     cout << "ERROR: " << strerror(errno) << endl;
     exit(0);
    }
*/
    //code
    int n;
    while(sc(n)!=EOF){
     int nofcorners=power(2,n);
        vector<corner>corner(nofcorners);

   //reading data of all corners
     rep(nofcorners){
        sc(corner[i].weight);
     }

   //finding potency of each corner
        repi(i,nofcorners){
            repi(j,n){
               corner[i].potency+=corner[(i^(1<<j))].weight;
            }
        }
      ll sum=0;
        repi(i,nofcorners){
            repi(j,n){
               sum=max(sum,corner[i].potency+corner[(i^(1<<j))].potency);
            }
        }
   cout<<sum<<endl;
    }
    return 0;
}
