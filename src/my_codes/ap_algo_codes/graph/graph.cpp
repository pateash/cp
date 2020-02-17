
#include <bits/stdc++.h>
#define MAX 100
#define INF 1e9
#define NIL -1
#define TEMP 0
#define PERM 1
using namespace std;
int n;
int adj[MAX][MAX];
int path_length[MAX],status[MAX],pred[MAX];
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
void warshall(){
   int path[MAX][MAX];
  for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
          path[i][j]=adj[i][j];

  for(int k=0;k<n;k++)
     for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
           path[i][j]=path[i][j]||(path[i][k]&&path[k][j]);

  cout<<"path matrix is "<<endl;
   show(path,n);
}
int find_min(){
    int min=INF;
    int minv=NIL;
    for(int i=0;i<n;i++){
        if(status[i]==TEMP&&min>path_length[i]){//sare lengths me se min nikalni jo abhi select nahi hui h
            min=path_length[i];
            minv=i;
        }

    }
    return minv;
}

void dijistra(int s){
      for(int i=0;i<n;i++){
      path_length[i]=INF;
      status[i]=TEMP;
      pred[i]=NIL;
    }
    path_length[s]=0;
    int cur;
    while(true){
        cur=find_min();
        if(cur==NIL)
            break;
        status[cur]=PERM;
        for(int i=0;i<n;i++){
            if(status[i]==TEMP&&adj[cur][i]!=0)
            {
                if(path_length[i]>(path_length[cur]+adj[cur][i])){
                     path_length[i]=path_length[cur]+adj[cur][i];
                     pred[i]=cur;
                }
            }
        }
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
int main()
{
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
    cout<<"adjacency matrix"<<endl;
    show(adj,n);
    cout<<"Enter source"<<endl;
    int s;
    cin>>s;
    dijistra(s);
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
    cout<<"enter destination";
    int dest;
    cin>>dest;
    find_path(s,dest);
     cout<<endl;
    }

   return 0;
}
