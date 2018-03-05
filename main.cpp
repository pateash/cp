#include<bits/stdc++.h>
//types
#define llu long long unsigned int
#define ll long long int
//container
#define vi vector<int>
#define vl vector<ll>
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
#define scd(n) scanf("%lf",&n)
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
#define readd(n) double n;scd(n)
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

void printGraph(){
    //this function will be used to get proper format show that we can put that in to input file
    vector<vi>G={{0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0}, {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
                 {0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0}, {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
                 {0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0}, {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                 {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                 {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0}};

    show_2d(G);
    int vCount=G.size();
    int eCount=0;
    rep(vCount){
        repi(j,vCount){
            if(G[i][j]==1) {
                eCount++;
            }
        }
    }
    cout<<"v="<<vCount<<","<<"e="<<eCount<<endl;
}

vector<vi>adjMat;
vii dfs_arr;
vi color_set;

void dfs(int index){
    vector<bool>visited(adjMat.size());
    stack<int>s;
    s.push(index);
    int count=0;
    while(!s.empty()){
        int i=s.top();s.pop();
        if(!visited[i]) {
            dfs_arr.push_back(ii(count++, i));
            visited[i] = true;
        }
        for (int j = 0; j < adjMat.size(); ++j) {
            if(adjMat[i][j]==1 && visited[j]==false){
                s.push(j);
            }
        }
    }
//    show_pair1d(dfs_arr);
}
int graph_coloring(){
    dfs(0);
    int n=adjMat.size();
    color_set.assign(n,0);

    rep(n) color_set[i]=i; //initially assign a different color to every body

    //for dfs_arr, applying algorithm
    for(int i=0;i<color_set.size();i++){
        int actualNode=dfs_arr[i].second;
//        cout<<"for "<<actualNode;
        vi colorTaken(n,false);//let noone is taken

        for(int j=0;j<i;j++){//for all those having smaller indexes
            int actualNeighbour=dfs_arr[j].second;
            int neighbourColor=color_set[j];
//            cout<<"for actual Neighbour"<<actualNeighbour
            if(adjMat[actualNode][actualNeighbour]==1){//if both are connected
                colorTaken[neighbourColor]=true;

            }
        }

        //assigning first color from color set
        for (int j = 0; j <colorTaken.size() ; ++j) {
            if(colorTaken[j]==false){
                color_set[i]=j;//color of ith willbe 'j'
//                cout<<" -> "<<j<<endl;
                break;//go for next node from dfs_num
            }
        }
    }

    int colorCount=0;

    vi temp_color_set=color_set;
    sort(call(temp_color_set));
    auto it=unique(call(temp_color_set));
    int num_colors=distance(temp_color_set.begin(),it);
    cout<<"num colors:"<<num_colors<<endl;
    return num_colors;
}

int main() {

    string curdir = "/home/ashish/Documents/code/";
    if (
            freopen(string(curdir + "in.txt").c_str(), "r", stdin)
            &&
            freopen(string(curdir + "out.txt").c_str(), "w", stdout)
            );
    else {
        cout << "ERROR: " << strerror(errno) << endl;
        exit(0);
    }
//    printGraph();
    read(t);
    for (int k = 0; k <t ; ++k) {
        read(v);
        read(c);//chromatic number in reality
        adjMat.resize(v, vi(v, 0));
        repi(i, v) {
            repi(j, v) {
                sc(adjMat[i][j]);
            }
        }
//        show_2d(adjMat);
        int num_colors=graph_coloring();
        if(c!=num_colors){
            cout<<"TEST CASE #"<<k+1<<" FAILED"<<endl;
            show_pair1d(dfs_arr);
            cout<<endl<<"colors assigned are as follows\n";
            show_1d(color_set);
        }
        assert(num_colors==c);
        cout<<"TEST CASE #"<<k+1<<" PASSED"<<endl;

        //clear for next test case
        adjMat.clear();
        dfs_arr.clear();
        color_set.clear();
        cout << "--------------------" << endl;
    }
    return 0;
}
