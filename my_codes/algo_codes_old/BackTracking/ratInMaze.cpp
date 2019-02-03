#include <iostream>
#include <vector>
/*
this is a classic rat in maze problems
Problem--
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block
i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1].
A rat starts from source and has to reach destination. The rat can move only in two directions: forward and down.
*/
using namespace std;
vector<vector<int>>maze;
int xsize,ysize;
vector<vector<int>>path;
void show2d(vector<vector<int>>v){
    cout<<"your 2d vector is"<<endl;
    for(auto it=v.begin();it!=v.end();it++){
        for(auto i=it->begin();i!=it->end();i++)
            cout<<*i<<" ";
        cout<<endl;
    }
    cout<<endl;
}
bool find_path(int x,int y){
    if(x==xsize-1&&y==ysize-1)//if destination is reached
        return true;
       if(x+1<xsize&&maze[x+1][y]==1){//trying at down
            path[x+1][y]=1;
        if(find_path(x+1,y))
            return true;
        else
            path[x+1][y]=0;
       }
       if(y+1<ysize&&maze[x][y+1]==1){//trying at right
        path[x][y+1]=1;
        if(find_path(x,y+1))
            return true;
        else
            path[x][y+1]=0;
       }
return false;//if we can't get true from any try
}
void initPath(vector<vector<int>>& v){
    //initialising path to xsize*ysize all zero matrix
   for(int i=0;i<xsize;i++){
     vector<int>temp(ysize);
    v.push_back(temp);
  }
}
int main()
{
    cout<<"enter the x size"<<endl;
    cin>>xsize;
    cout<<"enter the y size"<<endl;
    cin>>ysize;
    int temp;
    cout<<"enter the maze"<<endl;
    for (int i=0;i<xsize ;i++ )
    {
        vector<int>tv;
        maze.push_back(tv);
        for(int j=0;j<ysize;j++)
        {
            cin>>temp;
            maze[i].push_back(temp);

        }
    }
    show2d(maze);
    initPath(path);
    path[0][0]=1;//we are taking as the source will always be open
    if(find_path(0,0))
        show2d(path);
    else
        cout<<"path could not be found"<<endl;
    return 0;
}
