/*
 *  Dijistra's Algorithm
 *  Author @ Ashish Patel
 *
 */

#include <iostream>
#include<vector>
#define INF 999999999//nearly equal to 2*10^9
using namespace std;
int min_index(int l[],int n)
{
    int mine=0;
    int i;
        for( i=0;i<n;i++)
    {
        if(l[i]<l[mine])
            mine=i;
    }
    return mine;
}
void shortest_path(vector<vector<int>>vect)
{
    int n=vect.size();
    int l[n];
    for(int i=0;i<n;i++)
        l[i]=INF;
    l[0]=0;
    int dest;
    cout<<"enter destination index\n";
    cin>>dest;
    int mine=0;
    int path_lengh=0;
    while(mine!=dest){
        path_lengh+=l[mine];//adding to path length as we will not consider it any more for finding minimum
        for(int i=0;i<n;i++)
        {
           if(vect[mine][i]!=0)//updating all connected to it
           {
               l[i]=min(l[i],l[mine]+vect[mine][i]);
           }
        }
        l[mine]=INF;//jisse ange minimum ye kabhi na aa jaye
        mine=min_index(l,n);//neeche kyoki jaise hi destination mile khatam ho jaye
    }
    cout<<"minimum distance betwee 0 and "<<dest<<" is "<<path_lengh<<endl;
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
