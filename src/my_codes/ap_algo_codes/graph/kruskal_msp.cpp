
#include<bits/stdc++.h>
#define MAX 100
#define INF 1e9
#define NIL -1
#define TEMP 0
#include<conio.h>
#define PERM 1
using namespace std;
int n;
struct pq{//for making a priority queue for edges
    int u,v;
    int w;//for storing weight
    pq*next;
};

pq * start=nullptr;
struct pq tree[MAX];//array of edges
void insert_pq(pq**pstart,int u,int v,int w){
   pq*p=(pq*)malloc(sizeof(pq));
    p->u=u;
    p->v=v;
    p->w=w;
    p->next=nullptr;
    if(*pstart== nullptr|| (*pstart)->w>w)
    {
        if(*pstart== nullptr)
        *pstart=p;
        else
        {
            p->next=*pstart;
            *pstart=p;
        }
        return;
    }
    pq*temp=*pstart;
    pq*prev= nullptr;
    while(temp!=nullptr&&temp->w<w)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=p;
    p->next=temp;
}
pq delete_pq(pq**pstart){//returns first element which is has most priority
  pq temp;//for storing data of first to be deleted
    pq*p=*pstart;
    *pstart=p->next;
    temp= *p;//copy constructor
    free(p);
    return temp;
}
bool isEmpty(pq*start)
{

    return (start==NULL);
}
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
void create_graph(){//let the graph is undirected
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
          insert_pq(&start,u,v,w);
          cout<<u<<" --> "<<v <<" has been inserted"<<endl;
          //
        }
    cout<<"all has been  inserted"<<endl;
}
int father[MAX];
void kruskals(){
    int count=0;
    cout<<"kruskal has been called"<<endl;
       //initialising fathers of all to NIL
    for(int i=0;i<n;i++)
        father[i]=NIL;
    while(!isEmpty(start)||count<n-1)//ya to que khatam ho
    {

            pq temp=delete_pq(&start);
            int u=temp.u;
            int v=temp.v;
            int w=temp.w;
            cout<<"u v and w are "<<u<<" "<<v<<" "<<w<<endl;
            int paru=NIL,parv=NIL;
            for(int i=0;i<n;i++){
                cout<<father[i]<<" ";
            }
            cout<<endl;

            while(u!=NIL){//to find the root of u because when u becomes NIl paru have its root
                paru=u;
                u=father[u];
            }

            while(v!=NIL){//to find the root of v
                parv=v;
                v=father[v];
            }

            if(parv!=paru||(parv==NIL&paru==NIL))//pahle case me
            {
                  count++;
                  tree[count].u=temp.u;
                  tree[count].v=temp.v;
                  tree[count].w=temp.w;
                  father[parv]=paru;//left wale ko father bana do
            }
    }
    if(count<n-1)
    {

        cout<<"graph is not connected\n";
        exit(1);
    }

}
int main(){
    create_graph();
    cout<<endl;
    kruskals();
    int min_weight=0;
    for(int i=1;i<=n-1;i++)//count has stored starting from 1
    {
        cout<<tree[i].u<<" -->" <<tree[i].v<<endl;
        min_weight+=tree[i].w;
    }
    cout<<"minimum weight is "<<min_weight<<endl;
    return 0;
}
