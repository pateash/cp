#include <iostream>
#include <vector>
#include <cstdio>
/*
PROBLEM-
Given an undirected graph and a number m,
determine if the graph can be colored with at most m colors
such that no two adjacent vertices of the graph are colored with same color.
Here coloring of a graph means assignment of colors to all vertices.
INPUT-
1-A 2D array graph[V][V] where V is the number of vertices in graph and
 graph[V][V] is adjacency matrix representation of the graph
2-An integer m which is maximum number of colors that can be used.
OUTPUT-
An array color[V] that should have numbers from 1 to m.
color[i] should represent the color assigned to the ith vertex.
The code should also return false if the graph cannot be colored with m colors.
TIME COMPLEXITY-(backtracking Algorithm)
 m^n where, m-max no. of colors can be used
            n-no. of vertices
*/
using namespace std;
// GLOBALS
int m;//m is max no. of colors could be given
int n;//no. of vertices in graph
vector<vector<int>>graph;

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

bool isSafe(int node,int color,vector<int>colorArr){
 //we have to check if it is safe to give this color to node
 for(int i=0;i<n;i++){
    if(graph[node][i]==1&&colorArr[i]==color)//if a node is connected to the node and having same color
        return false;
 }
 return true;
}

bool solveGraphColoring(int colorNode,vector<int>&colorArr){//colorArray may able to change as new color may added
    // colorNumber represents the color no. to be given now(1 to m)
    // colorNode represents the node to be colored (from 0 to n-1)
    if(colorNode==n){//if all done and for n is called
      cout<<"colorNode=="<<n<<", returning true"<<endl;
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(colorNode,i,colorArr)){
        //we are going to give it only if it is safe(no other adjacent of same color)
        //if color becomes more than m which will mean all upto m are not safe
        // and after loop false will be automatically returned
            printf("it is safe to put %d color at node %d\n",i,colorNode);
             show_1d(colorArr);
            colorArr[colorNode]=i;//putting i color at node
             colorNode++;
        if(solveGraphColoring(colorNode,colorArr))
            return true;
        else{//backtracking
            colorArr[colorNode]=0;
            colorNode--;
        }
      }
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
   cout<<"enter the value of m"<<endl;
   cin>>m;
   cout<<"graph "<<endl;
   show_2d(graph);
   vector<int>colorArr(n);
   //color starts from 1 to m , here all indexes (0 to n-1) initiallised to 0
   //contains the information about coloring of nodes
 cout<<"coloring array is "<<endl;
    show_1d(colorArr);
    cout<<"solution starts"<<endl;
   if(solveGraphColoring(0,colorArr))
   {
       cout<<"the ans is "<<endl;
       show_1d(colorArr);
    }else{
   cout<<"No way found!!!"<<endl;
   }

    return 0;
}
