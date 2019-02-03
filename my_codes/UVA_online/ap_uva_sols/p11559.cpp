#include<bits/stdc++.h>
//types
#define llu long long unsigned int
#define ll long long int
//container
#define vl vector<long long>
#define vll vector<pair<ll,ll> >
//IO
#define pr(n) printf("%lld",n)
#define prd(n) printf("%lf",n)
#define nl printf("\n")
#define sp printf(" ")
#define sc(n) scanf("%lld",&n)
#define scd(n) scanf("%lf",&n)

//function and loops
#define mp make_pair
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repn(n) for(int i=0;i<n;i++)
#define repi(c) for(auto it=(c).begin();it!=(c).end();it++)
#define inf (ll)1e18
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

int main()
{
    ll n,b,h,w;
    while(cin>>n>>b>>h>>w)
    {
        ll priceArr[h];
        ll beds[h][w];

        for (int j = 0; j < h; ++j) {
            sc(priceArr[j]);
            for (int k = 0; k < w; ++k) {
                sc(beds[j][k]);
            }
        }
        ll minprice=inf;
        for (int i = 0; i < h; ++i) {
            ll price=0;
            for (int j = 0; j < w; ++j) {
                if(beds[i][j]<n)
                    price=inf;
                else
                    price=n*priceArr[i];

                if(minprice>price)
                    minprice=price;
            }

        }
        if(minprice>b)
            puts("stay home");
        else {
            pr(minprice);
            nl;
        }
    }

    return 0;
}
