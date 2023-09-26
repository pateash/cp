/*
* Author : Ashish Patel
* Handle: ashishpatel0720
*/

/********   All Required Header Files ********/
#include<iostream>
#include<cstdio>
#include <cmath>
#include<cstring>
#include <cassert>
#include<climits>
#include<algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
//types
#define llu long long unsigned int
#define ll long long int
#define llu long long unsigned int
//container
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>> // could be used for graph adjacency list

//function and loops
#define mp make_pair
#define repab(a,b) for(int i=(a);i<(b);i++)
#define rep(n) for(int i=0;i<n;i++)
#define repi(i,n) for(int (i)=0;(i)<n;(i)++)
#define repit(c) for(auto it=(c).begin();it!=(c).end();it++)
//reading all once
#define call(c) (c).begin(),(c).end()
#define MOD int(1e9+7)
#define INF int(1e9+1)
//debug
using namespace std;


/****** Template Debugs *********/
#define DEBUG(a) std::clog<<#a<<" : "<<a<<std::endl;

#define DEBUGN(args...)     (Debugger()) , args
class Debugger
{
public:
    Debugger(const std::string& _separator = " - ") :
            first(true), separator(_separator){}

    template<typename ObjectType> Debugger& operator , (const ObjectType& v)
    {
        if(!first)
            std:cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger() {  std:cerr << endl;}

private:
    bool first;
    std::string separator;
};

//testing functions
template <typename T> void show_2d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        int s = it->size();
        for(auto it2=it->begin();it2!=it->end();it2++)
        {
             cout<<*it2<< " ";
             if(it2==(it->begin()+s-1)) // only do at last line
                 cout<<endl;
        }
    }
    cout<<endl;
}
template <typename T> void show_pair1d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        cout<<"["<<it->first<<","<<it->second<<"]";
        cout<<endl;
    }
    cout<<endl;
}
template <typename T> void show_pair2d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        for(auto it2=it->begin();it2!=it->end();it2++)
            cout<<"["<<it2->first<<","<<it2->second<<"],";
        cout<<endl;
    }
    cout<<endl;
}

template <typename T,typename R> void show_pair(pair<T,R> p){
    cout<<p.first<<"-> "<<p.second<<endl;
}
template <typename T> void show_1d(T &container){
    cout<<"[";
    for(auto it=container.begin();it!=container.end();it++){
        cout<<*it<<", ";
    }
    cout<<"]"<<endl;
}
template <typename  T> void show_arr(T arr[],int size){
    cout<<"content in array is here"<<endl;
    for (int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
template<typename T> void show_graph(T AdjList){
    cout<<"-----------"<<endl;
    cout<<"showing graph"<<endl;
    int i=0;
    for(auto v: AdjList){
        cout<<i++;
        for(auto e:v){
            cout<<"->"<<"["<<e.first<<","<<e.second<<"]";
        }
        cout<<endl;
    }
    cout<<"-----------"<<endl;
}
void test_working(){
    string string1;
    cin>>string1;
    cout<<"its working and \nfirst line input:"<<string1;
    exit(EXIT_SUCCESS);
}

void solve(){

    int n,k;
    cin>>n>>k;

    int x;
    bool found=false;
    rep(n) {
        cin>>x;
//        DEBUG(x);
        if(x==k)
        {
            found=true;
        }
    }
    if(found)
            puts("YES");
    else
   puts("NO");
}

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
//    pass the path to resources in command line args eg. '/Users/ashish/Desktop/code/src/resources/'
    string curdir = argv[1];
    if (
            freopen(string(curdir + "in.txt").c_str(), "r", stdin)
            &&
            freopen(string(curdir + "out.txt").c_str(), "w", stdout)
            );
    else {
        cout << "ERROR: " << strerror(errno) << endl;
        exit(0);
    }
#endif

//    test_working();
//    clock_t t1=clock(),t2;
    int t;
    cin>>t;
//    DEBUG(t)
    while(t--){
        solve();
    }
//    t2=clock();
    //   cout<<endl<<"time is "<<(t2-t1)/(1.0*CLOCKS_PER_SEC)<<" seconds"<<endl;
    return 0;
}
