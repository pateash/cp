
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
    warshall();//function which find path matrix and displays
   return 0;
}
