
#include <iostream>
#include <vector>


using namespace std;


using vi=vector<int>;


vi ts;
enum{VISITED, UNVISITED};
vi visited;
void dfs(int u){
    //VISTED, UNVISTED
    visited[u]=VISITED;
}

int main(){
    // 0 is the first graph node
    int n=10;
    for (size_t i = 0; i < n; i++)
    {
        cout<<"HELLO"<<endl;
    }
    // vi visited(n,UNVISITED);
    // dfs(0);
    return 0;

}