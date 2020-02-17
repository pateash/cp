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
#define repi(c) for(auto it=(c).begin();it!=(c).end();it++)
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

int main()
{
 /*   if(freopen("C:\\Users\\ashish_patel\\Documents\\CodeBlocks Project\\Sample\\in.txt","r",stdin) && freopen("C:\\Users\\ashish_patel\\Documents\\CodeBlocks Project\\Sample\\out.txt", "w", stdout));
    else{cout<<"ERROR: "<<strerror(errno)<<endl; exit(0);}
*/
 //start coding here

    int sz,p;
    while(scanf("%d %d",&sz,&p),(sz||p)){
   /*     int arr[sz][sz];
        for (int l = 0; l < sz; ++l) {
            for (int k = 0; k < sz; ++k) {
            arr[l][k]=0;
            }
        }
   */
        int val=1;
        int i=sz/2;
        int j=sz/2;
        bool vert=true;
        int delta=-1;
        //arr[i][j]=val;
        while(val!=p){
            if(vert){
                if(p>val+abs(delta)){
                       i+=delta;
                        val+=abs(delta);
                }
                    else{
                for(int k=0;k<abs(delta)&&p!=val;k++) {
                    if (delta < 0)
                        i--;
                    else
                        i++;

                    val++;
                }
        //            arr[i][j]=val;
                }
                vert=false;
            }
            else{

                if(p>val+abs(delta)){
                    j+=delta;
                    val+=abs(delta);
                }
                else {
                    for (int k = 0; k < abs(delta) && p != val; k++) {
                        if (delta < 0)
                            j--;
                        else
                            j++;
                        val++;
                        //          arr[i][j]=val;

                    }
                }
                vert=true;
                if(delta<0){
                    delta=1-delta;

                }else
                    delta=-1-delta;

            }
        }
     /*   cout<<endl;
        for (int l = 0; l < sz; ++l) {
            for (int k = 0; k < sz; ++k) {
                cout<<setw(5)<<arr[l][k]<<" ";

            }
            cout<<endl;

        }
     */
        //printf("i:%d j:%d\t",i,j);
        printf("Line = %d, column = %d.\n",sz-i,j+1);
     

    }
    return 0;
}
