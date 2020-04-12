#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include "libs/CommonLibs.h"

int main() {
    //// We have input for Adjacency Matrix/List/EdgeList

    // Adj Matrix
    //   for each line: |V| entries, 0 or the weight

    // Adj List
    //   for each line: num neighbors, list of neighbors + weight pairs

    // Edge List
    //   for each line: a-b of edge(a,b) and weight

    if (
            freopen("graph_input.txt", "r", stdin));
    else {
        cout << "ERROR: " << strerror(errno) << endl;
        exit(0);
    }

    int V, E, total_neighbors, id, weight, a, b;
    int AdjMat[100][100];//first way
    vector<vii> AdjList;//second way
    priority_queue< pair<int, ii> > EdgeList;   // third way

/**********WAY 1 (using adjacency matrix)**********************/
    scanf("%d", &V);                         // we must know this size first!
    // remember that if V is > 100, try NOT to use AdjMat!
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &AdjMat[i][j]);

    puts("*************");
    puts("Adjacency Matrix(weight)");
    puts("*************");

    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++)
            printf("%3d ",AdjMat[i][j]);
        nl;
    }
    nl;
    printf("Neighbors of vertex 0:\n");
    for (int j = 0; j < V; j++)                                     // O(|V|)
        if (AdjMat[0][j])
            printf("Edge 0-%d (weight = %d)\n", j, AdjMat[0][j]);
    nl;

/**********WAY 2 (using adjacency  list)**********************/
    puts("*************");
    puts("AdjList(edge,weight)");
    puts("*************");
    scanf("%d", &V); // no.  of vertices

    AdjList.assign(V, vii()); // quick way to initialize AdjList with V entries of vii(constructor of empty vactors) using assign(n,value);

    //popuating our adjList by knowing neighbours
    for (int i = 0; i < V; i++) {
        scanf("%d", &total_neighbors);
        for (int j = 0; j < total_neighbors; j++) {
            scanf("%d %d", &id, &weight);
            // some index adjustment(because our index is 0 for vertex no. 1)
            AdjList[i].push_back(ii(id - 1, weight));
        }
    }

    show_pair2d(AdjList);
    printf("Neighbors of vertex 0:\n");
    for (vii::iterator j = AdjList[0].begin(); j != AdjList[0].end(); j++)
        // AdjList[0] contains the required information
        // O(k), where k is the number of neighbors
        printf("Edge 0-%d (weight = %d)\n", j->first, j->second);

nl;
/**********WAY 3 (using edge list)**********************/
    puts("*************");
    puts("EdgeList(u,v,weight)");
    puts("*************");

    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &weight);
        EdgeList.push(make_pair(-weight, ii(a-1, b-1)));  //adjusting indices for same all over
        // - use as a trick to reverse sort order(or use Greater<int> in declaration)
    }

    // edges sorted by weight (smallest->largest)
    for (int i = 0; i < E; i++) {
        pair<int, ii> edge = EdgeList.top(); EdgeList.pop();
        // negate the weight again
        printf("weight: %d (%d-%d)\n", -edge.first, edge.second.first, edge.second.second);
    }

    return 0;
}
