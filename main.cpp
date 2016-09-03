#include <bits/stdc++.h>
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
void show_pair(T container){
    for(auto it=container.begin();it!=container.end();it++){
        cout<<it->first<<" --> "<<it->second;
        cout<<endl;
    }
    cout<<endl;
}

template <typename T>
void show_1d(T container){

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

int find(){
  int c;
  cin>>c;
  int type[7]={0};
  int temp;
  rep(i,0,c)
     {
         sc(temp);
         type[temp]++;
     }
     sort(type,type+7,[](int a,int b){return a>b;});
    // cout<<"type after sorting";
    // show_arr(type,7);
     int min_6=*min_element(type,type+6);
     if(min_6>0){
        for_each(type,type+6,[min_6](int &a){a-=min_6;});
     }
     sort(type,type+7,[](int a,int b){return a>b;});
     int min_5=*min_element(type,type+5);
    if(min_5>0){
        for_each(type,type+6,[min_5](int &a){a-=min_5;});
     }
    sort(type,type+7,[](int a,int b){return a>b;});
    int min_4=*min_element(type,type+4);
    if(min_4>0){
        for_each(type,type+6,[min_4](int &a){a-=min_4;});
     }
     cout<<"("<<min_4<<","<<min_5<<","<<min_6<<")";
     return c+min_4+2*min_5+4*min_6;
}

void solve(){
  int n;
  cin>>n;//no. of players
  int winner_index=-1;
  int max_score=INT_MIN;
  int ambiguity_max=INT_MIN;
  for(int j=0;j<n;j++){
    int score=find();
    cout<<"score of player "<<j+1 <<": "<<score<<" and max_Score:"<<max_score<<endl;
    if(score>max_score){
        winner_index=j;
        max_score=score;
    }
    else if(score==max_score){
       cout<<"AMBIGUITY "<<score<<" , "<<max_score<<endl;
        ambiguity_max=score;
    }
  }
  cout<<"WINNER IS ";
  if(ambiguity_max==max_score){
    cout<<"tie"<<endl;

       cout<<"AMBIGUITY bahar "<<ambiguity_max<<" , "<<max_score<<endl;
  }
  else if(winner_index==0){
    cout<<"chef"<<endl;
  }
  else
    cout<<winner_index+1<<endl;
}
int main()
{
  int t;
  cin>>t;
  while(t--){
  solve();
}


    return 0;
}
