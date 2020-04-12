//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_GRAPH_H
#define SAMPLE_GRAPH_H

#include "../CommonLibs.h"

enum {UNVISITED, VISITED}; // will be used for traversal

// COMPLEXITY O(V+E) for AdjList and O(V^2) for AdjMatrix

/*
Note - BFS is also used for finding minimum shortest path(if weight of all is 1)
 */

void bfs(int u, vvii& AdjList,vi& tracker, vi&output){
    // start from u, add it to the queue and  continue until queue is not empty
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x=q.front();q.pop();
        if(tracker[x]==UNVISITED){
            output.push_back(x);
            tracker[x]=VISITED;
        }
        for(auto p:AdjList[x]){
            int e = p.first;
            if(tracker[e]==UNVISITED){
                q.push(e);
            }
        }
    }
}

void dfs(int u, vvii& AdjList ,vi& dfs_num, vi&output){
    dfs_num[u]=VISITED;
    output.push_back(u);

    //going to all neighbours of 'u'
    for(auto p : AdjList[u]){
        int e=p.first; // vertex
        if(dfs_num[e]== UNVISITED)
            dfs(e,AdjList,dfs_num,output);
    }
}

void testGraph() {
    //// We have input for Adjacency Matrix/List/EdgeList ( all for same graph )

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

    /*** Traversals */
    vi tracker;
    vi output;
    vi expected_output;

    puts("*************");
    puts("DFS");
    puts("*************");

    tracker.assign(V,UNVISITED); // set all to unvisited
    dfs(1, AdjList,tracker,output); // start from zero

    expected_output={1,0,4,3,2,5};
    assert(output.size()==expected_output.size());
    for(int i=0;i<output.size();i++) {
        write2(output[i]);
        assert(output[i]==expected_output[i]);
    }
    nl;

    puts("*************");
    puts("BFS");
    puts("*************");
    output.clear();
    expected_output={0,1,4,2,3,5};
    tracker.assign(V,UNVISITED);

    bfs(0, AdjList,tracker,output); // start from zero

    assert(output.size()==expected_output.size());
    for(int i=0;i<output.size();i++) {
        write2(output[i]);
        assert(output[i]==expected_output[i]);
    }
    nl;
}

#endif

