#include <iostream>
#include <queue>
enum {unprocessed,waiting,processed};
using namespace std;


int main()
{
  cout<<"enter the number of nodes\n";
  int n;
  cin>>n;
  int status[n];
  for (int i=0;i<n;i++)
     status[i]=unprocessed;
  cout<<"enter adjency matrix of "<<n<<" * "<<n<<endl;
  int adj[n][n];
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
        cin>>adj[i][j];
  int source;
  cout<<"enter source vertex\n";
  cin>>source;
   //BFS starts here
   queue<int>q;
   q.push(source);
   status[source]=waiting;
   while(!q.empty()){
        int temp=q.front(); q.pop();
        status[temp]=processed;
        cout<<temp<<" ";
        for(int i=0;i<n;i++){//how many are connected to that which has poped
            if(adj[temp][i]==1&&status[i]==unprocessed){//which is unprocessed process that one
                q.push(i);
                status[i]=waiting;
            }
        }
    }
   return 0;
}
