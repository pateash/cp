#include<bits/stdc++.h>
//types
#define llu long long unsigned int
#define ll long long int
#define vi vector<int>
#define li list<int>
#define vl vector<long>
#define vpii vector<pair<int,int> >
//IO
#define pr(n)  printf("%d",n)
#define prl(n) printf("%lld",n)
#define prf(n) printf("%f",n)
#define nl printf("\n")
#define sp printf(" ")
#define sc(n)  scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scf(n) scanf("%f",&n)

//function and loops
#define mp make_pair
#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define repn(n) for(ll i=0;i<n;i++)
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
void show_arr(T arr[],ll size){
    cout<<"content in array is here"<<endl;
    for (ll i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

//START CODING HERE
#define MOD 10000007

ll power(ll a,ll b){
    if(b==0)
        return 1;
    if(b==1)
     return a;
    ll ans=power(a,b/2);
    if(b&1)
        return (((ans*ans)%MOD)*b)%MOD;
    else
        return (ans*ans)%MOD;
}

ll solve(){
  ll n,k;
    scl(n);scl(k);
    ll b[n];
    ll s=0;

    repn(n) {
        scl(b[i]);
     s=(s+b[i])%MOD;
    }
    string sstr=to_string(s);
    if(sstr.length()==1)
        return -1;
    ll length=sstr.length();
  //  cout<<"sstr is "<<sstr<<endl;
    ll c=s%100;
    ll a=s/(power(10,length-2));
    //cout<<"a:"<<a<<" b:"<<c<<endl;
    //cout<<"power "<<power(a,c)<<endl;
    return power(a,c)/k;
}

int main()
{
    int t;
    sc(t);
    while(t--){
       prl(solve());
        nl;
    }
    return 0;
}
