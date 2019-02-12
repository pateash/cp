#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
/*
PROBLEM-
Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once.
A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that,
there is an edge (in graph) from the last vertex to the first vertex of the Hamiltonian Path.
Determine whether a given graph contains Hamiltonian Cycle or not.If it contains, then print the path.
Input:
A 2D array graph[V][V]
Output:
An array path[V] that should contain the Hamiltonian Path.
example-
For example, a Hamiltonian Cycle in the following graph is {0, 1, 2, 4, 3, 0}.
There are more Hamiltonian Cycles in the graph like {0, 3, 4, 2, 1, 0}(starting and ending should be same)
(0)--(1)--(2)
 |   / \   |
 |  /   \  |
 | /     \ |
(3)-------(4)
*/
using namespace std;
// GLOBALS
int n;//no. of vertices in graph
vector<vector<int>>graph;
vector<int>path;
//it will have n+1 elements showing path from 0 to 0
//as we can start from any node as it will be present in the cycle
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
void show_1d(T container){

  for(auto it=container.begin();it!=container.end();it++){
    cout<<*it<<" ";

  }
  cout<<endl;
}



bool isSafe(int node){
 //we have to check if it is safe to add node in path

 //check if this node is connected to previously path added node
 if(graph[path[path.size()-1]][node]==0){
   cout<<"due to condition 1 , ";
   printf("graph[%d][%d]==0  ",path.size()-1,path.size()-1);
    return false;
 }


 //checking if node already present in path
 vector<int>::iterator it=find(path.begin(),path.end(),node);
   if(it!=path.end()){//if node is present in path

   cout<<"due to condition 2";
    return false;
   }
 return true;
}

bool solveHamiltonian(){
    if(path.size()==n){
        //if n+1 nodes already added
        cout<<"size becomes n+1"<<endl;
        //if path between last and 0 exists
        if(graph[path[path.size()-1]][0]==1){
           path.push_back(0);
           return true;
        }
    }
    //as 0 already added
    for(int i=1;i<n;i++){
    //trying to add all nodes and seeing if satisfy
        if(isSafe(i)){
                cout<<i <<" is safe"<<endl;
               path.push_back(i);
         if(solveHamiltonian())
            return true;
        else//backtracking
            path.pop_back();
        cout<<i<<" removed"<<endl;
        }
        else
            cout<<i <<" is not safe"<<endl;;
    }
    return false;
}

int main()
{
   cout<<"enter the number of vertices in graph"<<endl;
   cin>>n;

   cout<<"enter the adjacency matrix"<<endl;
   for(int i=0;i<n;i++){
        vector<int>v;
     for(int j=0;j<n;j++){
        int temp;
        cin>>temp;
        v.push_back(temp);
     }
     graph.push_back(v);
   }
   cout<<"graph "<<endl;
   show_2d(graph);
    cout<<"solution starts"<<endl;
    //0 node already added
    path.push_back(0);
   if(solveHamiltonian())
   {
       cout<<"the ans is "<<endl;
       show_1d(path);
    }else{
   cout<<"No cycle found!!!"<<endl;
   }

    return 0;
}
