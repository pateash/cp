//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_GRAPHTRAVERSAL_H
#define SAMPLE_GRAPHTRAVERSAL_H

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


void bfs_ssp(int u, vvii& AdjList,vi& distance){
    // start from u, add it to the queue and  continue until queue is not empty
    queue<int> q;
    q.push(u); // add source
    distance[u]=0; //add its distance from source = 1

    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto p:AdjList[x]){
            int e = p.first;
            if(distance[e]==INF){ // if not reached yet
                distance[e]=distance[x]+1; // distance will be neighbour + 1
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

void testGraphTraversals() {
    //// We have input for Adjacency Matrix/List/EdgeList ( all for same graph )

    // Adj Matrix
    //   for each line: |V| entries, 0 or the weight

    // Adj List
    //   for each line: num neighbors, list of neighbors + weight pairs

    // Edge List
    //   for each line: a-b of edge(a,b) and weight

    if (
            freopen("src/resources/libs/graph_input_adjlist.txt", "r", stdin));
    else {
        cout << "ERROR: " << strerror(errno) << endl;
        exit(0);
    }

    int V, E, total_neighbors, id, weight, a, b;
    vector<vii> AdjList;//second way

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
    tracker.assign(V,UNVISITED); //distance of all from source (u)

    bfs(0, AdjList,tracker,output); // start from zero

    assert(output.size()==expected_output.size());
    for(int i=0;i<output.size();i++) {
        write2(output[i]);
        assert(output[i]==expected_output[i]);
    }
    nl;


/****
 BFS could be used to find single source sortest path if all the weights are 1 ( or there are no weights)
 in place of tracker, here we will use distance array ( initally all are INF )
 * */
    puts("*************");
    puts("BFS SSP");
    puts("*************");
    output.clear();
    expected_output={0,1,2,2,1,3};
    vi distance(V,INF);


    // Note - even though in input file we do have weights,
    // we are just using all weight as 1
    bfs_ssp(0, AdjList,distance); // start from zero

    assert(expected_output.size()==distance.size());
    for(int i=0;i<distance.size();i++) {
        write2(distance[i]);
        assert(distance[i]==expected_output[i]);
    }
    nl;

}

#endif

