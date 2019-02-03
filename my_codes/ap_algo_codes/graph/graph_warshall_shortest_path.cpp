/*
 *  Warshall's Algorithm
 *  Author @ Ashish Patel
 *
 */

#include <iostream>
#include<vector>
#define INF 999999999//nearly equal to 2*10^9
using namespace std;
void shortest_path(vector<vector<int>>vect)
{
    int n=vect.size();
   int path[n][n];
   //initialisation of shortest path matrix for adjacency matrix
   for(int i=0;i<vect.size();i++){
    for(int j=0;j<vect[i].size();j++)
        if(vect[i][j]==0)
           path[i][j]=INF;
        else
           path[i][j]=vect[i][j];
   }
   cout<<"showing path matrix after initialisation"<<endl;
   for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
         cout<<path[i][j]<<" ";
   cout<<endl;
 }
    //starting warshall's algorithm
     for(int k=0;k<vect.size();k++)//same baar chalani hai number of vertices ke
      for(int i=0;i<vect.size();i++)
        for(int j=0;j<vect[i].size();j++)
           path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
    cout<<"showing path matrix after calculations"<<endl;
     for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
         cout<<path[i][j]<<" ";
   cout<<endl;
 }
}
void show(vector<vector<int>>vect)
{
    for(int i=0;i<vect.size();i++){
        for (int j=0;j<vect[i].size();j++ )
         cout<<vect[i][j]<<" ";
        cout<<endl;
    }
}
 int main()
{
     cout<<"Enter the number of elements in the graph"<<endl;
     int n;
     cin>>n;
     vector<vector<int>>vect;
     cout<<"Enter adjency matrix "<<endl;
     for(int i=0;i<n;i++)
     {
         vector<int>temp(n);
       for(int j=0;j<n;j++)
       {
           cin>>temp[j];
       }
       vect.push_back(temp);
       temp.clear();
     }

   cout<<"showing adjacency matrix after initialisation"<<endl;
     show(vect);
     cout<<"shortest path is "<<endl;
     shortest_path(vect);
    return 0;
}
