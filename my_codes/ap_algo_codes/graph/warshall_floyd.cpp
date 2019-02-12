
#include <bits/stdc++.h>
#define MAX 100
#define INF 1e9
#define NIL -1
#define TEMP 0
#define PERM 1
using namespace std;
int n;
int adj[MAX][MAX];
int spath[MAX][MAX];
int path_length[MAX],pred[MAX][MAX];//here predecessor matrix will also be 2d because 1 row will form for 1 source
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
  if(spath[s][v]==INF){
        cout<<"there is no path"<<endl;
        return;
    }
    int count=1;
    int dist=0;
    int path[n];
     while(s!=v){
        path[count++]=v;
        int u=pred[s][v];//now here pred of v will be in row having s because we are taking s as source
        dist+=adj[u][v];//distance between u and v
        v=u;
     }
     path[count]=s;

    cout<<"no. of vertices used : "<<count<<endl;
    cout<<"total distance used : "<<dist<<endl;
    cout<<"path is following "<<endl;
    for(int i=count;i>=1;i--){
        cout<<path[i] <<" ";

    }

    cout<<endl;

}

void warshall_floyd()
{
    //initiallising spath matrix from adjacency
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]!=0)
            {//if direct path exists between i and j
               spath[i][j]=adj[i][j];
               pred[i][j]=i;
            }
            else
            {
                    spath[i][j]=INF;
                    pred[i][j]=NIL;
            }
        }
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
              if(spath[i][j]>spath[i][k]+spath[k][j])
              {
                  spath[i][j]=spath[i][k]+spath[k][j];
                  pred[i][j]=pred[k][j];
              }
            }
  for(int i=0;i<n;i++){
         if(spath[i][i]<0)
         {
             cout<<"negative cycle"<<endl;
             exit(0);
         }

     }
}
int main()
{
    create_graph();
    cout<<"adjacency matrix"<<endl;
    show(adj,n);
    warshall_floyd();//spath is a matrix which stores all

    cout<<"after finding shortest path"<<endl;
    show(spath,n);

     cout<<"predecessor matrix is "<<endl;
     show(pred,n);


    for(int i=0;i<6;i++){
    cout<<"Enter source"<<endl;
     int s;
      cin>>s;
    cout<<"enter destination";
    int dest;
    cin>>dest;
    find_path(s,dest);
     cout<<endl;
    }

   return 0;
}
