
#include <bits/stdc++.h>
#define MAX 100
#define INF 1e9
#define NIL -1
#define TEMP 0
#define PERM 1
using namespace std;
int n;
int adj[MAX][MAX];
int path_length[MAX],pred[MAX];
bool isInQ[MAX];//isInQ will be used to find whether an vertex is there in Q
void create_graph(){
 cout<<"enter the number of vertex"<<endl;
    cin>>n;
    cout<<"choose one of the following option \n1-Undirected\n2-Directed\n";
    int choice;
    cin>>choice;
    int max_edges;
    if(choice==1)
        max_edges=(n*(n-1))/2;
    else
        max_edges=n*(n-1);
    int u,v,w;
    cout<<"enter the edge (u,v,w), enter (-1,-1,-1) for stop\n";
    for(int i=0;i<max_edges;i++){
        cin>>u>>v>>w;
        if(u==-1||v==-1||w==-1)
            break;
        adj[u][v]=w;
    }

}
void show(int arr[MAX][MAX],int n){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
      {
          if(arr[i][j]==INF)
            cout<<"INF ";
          else
            cout<<arr[i][j]<<" ";
      }

    cout<<endl;
    }
}

void find_path(int s,int v){
    int count=1;
    int dest=0;
    int path[n];
     while(s!=v){
        path[count++]=v;
        int u=pred[v];
        cout<<"u and v are "<< u << " "<<v <<endl;
        cout<<"distance between u and v are "<<adj[u][v]<<endl;
        dest+=adj[u][v];
        v=u;
     }
     path[count]=s;

    cout<<"no. of vertices used : "<<count<<endl;
    cout<<"total distance used : "<<dest<<endl;
    cout<<"path is following "<<endl;
    for(int i=count;i>=1;i--){
        cout<<path[i] <<" ";

    }

    cout<<endl;

}
int bellman_ford(int source){
   queue<int>q;//queue to store the vertices
   //initialising
   for(int i=0;i<n;i++){
     isInQ[i]=false;//0 means not
    path_length[i]=INF;
    pred[i]=NIL;
    }
    path_length[source]=0;
    q.push(source);
    isInQ[source]=true;
    int k=0;
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        isInQ[cur]=false;
        if(cur==source){
         k++;
        }
        if(k>n)
            return -1;
        for(int i=0;i<n;i++){
            if(adj[cur][i]!=0){
                if(path_length[i]>path_length[cur]+adj[cur][i])
                {
                    path_length[i]=path_length[cur]+adj[cur][i];
                    pred[i]=cur;
                    if(!isInQ[i])
                    {
                      q.push(i);
                      isInQ[i]=true;
                    }

                }

            }
        }

    }
  return 1;
}

int main()
{
    create_graph();
    cout<<"adjacency matrix"<<endl;
    show(adj,n);
    cout<<"Enter source"<<endl;
    int s;
    cin>>s;
    int ans=bellman_ford(s);
    if(ans==-1){
        cout<<"negative cycle is present in graph"<<endl;

    }
    cout<<"pred matrix"<<endl;
    for(int i=0;i<n;i++)
        cout<<pred[i]<<" ";
    cout<<endl;
     cout<<"length matrix"<<endl;
    for(int i=0;i<n;i++)
        cout<<path_length[i]<<" ";
    cout<<endl;

    cout<<"after finding shortest path"<<endl;
    for(int i=0;i<4;i++){
    cout<<"enter destination ";
    int dest;
    cin>>dest;
    find_path(s,dest);
     cout<<endl;
    }

   return 0;
}
