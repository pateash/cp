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
#define call(c) (c).begin(),(c).end()
//debug
#define show(a) std::cout<<#a<<" : "<<a<<std::endl;

using namespace std;

//testing functions
template <typename T> void show_2d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        for(auto it2=it->begin();it2!=it->end();it2++)
            cout<<*it2<<" ";
        cout<<endl;
    }
    cout<<endl;
}
template <typename T> void show_pair1d(T container){
    for(auto it=container.begin();it!=container.end();it++){
        cout<<it->first<<" --> "<<it->second;
        cout<<endl;
    }
    cout<<endl;
}
template <typename T,typename R> void show_pair(pair<T,R> p){
    cout<<p.first<<"-> "<<p.second<<endl;
}
template <typename T> void show_1d(T &container){
    cout<<"data in container is: "<<endl;
    for(auto it=container.begin();it!=container.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
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

//utility classes
class UnionFind{
    vi par,rank,setSize;
    int numsets;

public:
    UnionFind(int n){
        par.assign(n,0);rank.assign(n,0);
        setSize.assign(n,1);
        numsets=n;
        for(int i=0;i<n;i++) par[i]=i;
    }
    bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    int findSet(int i){
        return par[i]==i?i:par[i]=findSet(par[i]);
    }
    void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]) {
                par[y] = x;
                setSize[x]+=setSize[y];
            }
            else{
                par[x]=y;
                setSize[y]+=setSize[x];
                if(rank[x]==rank[y])
                    rank[y]++;
            }
            numsets--;
        }
    }
    int numDisjointSets(){
        return numsets;
    }
    int sizeOfSet(int i){
        return setSize[i];
    }
};

//utility functions
ll power(int i,int c,int MOD){
    if(c==0) return 1;
    if (c==1) {
        return i%MOD;
    }
    /*ans is required long long, as ans*ans might get heavy
     * before mod applied */
    ll ans=power(i,c/2,MOD);
    ans=(ans*ans)%MOD;
    if(c%2==1) ans=(ans*i)%MOD;
    return ans;
}
template<typename T> T mod(T x){ //this function return |x| value
    return x<0? -x:x;
}
template<typename T> T gcd(T a,T b){
    if(b==0) return a;
    return gcd(b,a%b);
}


//these will be used to store results for euclid's extendex algorithm
int x,y,d;

void extendedEuclid(int a,int b) {
    if(b==0) {
        d=a;
        x=1;
        y=0;
        return;
    }
    extendedEuclid(b,a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}
int modIFerm(int A,int M){
    /*applying fermat's theorem A^-1=A^(M-2)%M
     * applicable only when M is prime
     * */
    return power(A,M-2,M);
}
int modIEuclid(int A,int M){
    /* applying extended euclid algo
     * applicable only when A and M are co-prime ie. GCD(A,M)=1
     * */
    extendedEuclid(A,M);
    return (x%M+M)%M;
    //as x could be negative, first reduce it(even if negative)
    //and then make it between [0,M-1] by taking modulo
}
void solve(){

}
int main() {
    string curdir="/home/ashish/Documents/code/";
    if(
            freopen(string(curdir+"in.txt").c_str(),"r",stdin)
            &&
            freopen(string(curdir+"out.txt").c_str(), "w", stdout)
            );
    else {
        cout << "ERROR: " << strerror(errno) << endl;
        exit(0);
    }
//    test_working();
    clock_t t1=clock(),t2;
    read(t);
    while(t--){
        solve();
    }
    t2=clock();
    //   cout<<endl<<"time is "<<(t2-t1)/(1.0*CLOCKS_PER_SEC)<<" seconds"<<endl;
    return 0;
}