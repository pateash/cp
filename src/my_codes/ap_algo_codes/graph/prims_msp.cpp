
#include<bits/stdc++.h>
#define MAX 100
#define INF 1e9
#define NIL -1
#define TEMP 0
#define PERM 1
using namespace std;
int n;
int adj[MAX][MAX];
struct edge{
  int u,v;
};
struct edge tree[MAX];//array of edges
int length[MAX], status[MAX], pred[MAX];
void show(int arr[MAX][MAX], int n) {
	for (int i = 0;i<n;i++) {
		for (int j = 0;j<n;j++)
		{
			if (arr[i][j] == INF)
				cout << "INF ";
			else
				cout << arr[i][j] << " ";
		}

		cout << endl;
	}
}
int find_min() {
	int minv = NIL;
	int min = INF;
	for (int i = 0;i < n;i++) {
		if (status[i] == TEMP&&min>length[i])
		{
			min = length[i];
			minv = i;
		}
   }
	return minv;
}
void prims(int r) {
    int ecount=0;//counts the number of vertex has been included to find connected or not
	 //initialiation
	for (size_t i = 0; i < n; i++)
	{
		length[i] = INF;
		status[i] = TEMP;
		pred[i] = NIL;
    }
    length[r]=0;
	while (true) {
		int cur = find_min();
		cout<<"cur comes "<<cur<<endl;
		if (cur == NIL)
        {
            if(ecount==n-1)//n-1 edges has been include
              break;
            else{
                cout<<"not connected a graph\n";
                exit(0);
            }
        }
        status[cur] = PERM;
        if(cur!=r)//so that in first iteration edge not included
        {
           ecount++;//a new edge is going to be inserted
           tree[ecount].u=pred[cur];
           tree[ecount].v=cur;
        }
        //updating all the vertices connected to cur and are temperary having less length
         for (int i = 0;i < n;i++) {
			if (status[i] == TEMP&&adj[cur][i] != 0) {
				if (length[i] > adj[cur][i])//old distance from any permanent is greater than this permanent
				{
					length[i] = adj[cur][i];
					pred[i] = cur;
				}
			}
		}
	}
}

void create_graph(){
    cout << "enter the number of vertex" << endl;
	cin >> n;
	int max_edges;
		max_edges = (n*(n - 1)) / 2;//undirected
	int u, v, w;
	cout << "enter the edge (u,v,w), enter (-1,-1,-1) for stop\n";
	for (int i = 0;i<max_edges;i++) {
		cin >> u >> v >> w;
		if (u == -1 || v == -1 || w == -1)
			break;
		adj[u][v] = w;//undirected dono sides se same
		adj[v][u]=w;
	}
}

int main(){
    create_graph();
	cout << "adjacency matrix" << endl;
	show(adj, n);
	int r;
	cout<<"enter the root "<<endl;
	cin>>r;
  	prims(r);
	cout << "pred matrix" << endl;
	for (int i = 0;i<n;i++)
		cout << pred[i] << " --> ";
	cout << endl;
	cout << "length matrix" << endl;
	for (int i = 0;i<n;i++)
		cout << length[i] << " ";
	cout << endl;
	cout<<"following edges are needed to be inserted in a tree having root "<<r<<endl;
    int min_weight=0;
	for(int i=1;i<=n-1;i++)//ecounter 1 se start 0 par kuchh nahi likha hai
    {
        cout<<tree[i].u<< "-->" <<tree[i].v<<endl;
        min_weight+=adj[tree[i].u][tree[i].v];
    }
    cout<<"minimum weight is "<<min_weight<<endl;
	return 0;
}
