#include <iostream>
#include<stack>
enum{unprocessed,waiting,processed};
using namespace std;
 int main()
{
     cout<<"Enter the number of elements in the graph"<<endl;
     int n;
     cin>>n;
     int adj[n][n];
     int status[n];
     for(int i=0;i<n;i++)
        status[i]=unprocessed;
     cout<<"Enter adjency matrix "<<endl;
     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
             cin>>adj[i][j];
     int source;
   cout<<"enter the source\n";
     cin>>source;
     //Dfs starts here
     stack<int>s;
     s.push(source);
     status[source]=waiting;
     while(!s.empty()){
         int temp=s.top();s.pop();
         status[temp]=processed;
         cout<<temp<<" ";
         for(int i=0;i<n;i++){
             if(adj[temp][i]==1&&status[i]==unprocessed)
             {
                 s.push(i);
                 status[i]=waiting;
             }
         }
    }
    return 0;
}
