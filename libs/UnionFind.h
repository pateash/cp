//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_UNIONFIND_H
#define SAMPLE_UNIONFIND_H

#include "CommonLibs.h"

class UnionFind{
private:
    vector<int> par,rank,setSize;
    /*
     * par - parent array, par[i] store top most known parent of set in which 'i' is present
     * rank - rank[i] height of the tree
     * setSize - setSize[i] is number of elements in the set having 'i'
     */
    int numsets;
public:
    UnionFind(int n){
        par.assign(n,0); //will assign it to themself as their parent
        for(int i=0;i<n;i++) par[i]=i;

        rank.assign(n,0);// initially all have 0 height
        setSize.assign(n,1);
        numsets=n;
    }
    bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }

    /*
     * returns the top most parent(root) of tree having 'i', because each set is
     * represented by it's root
     */
    int findSet(int i){
        return par[i]==i?i:par[i]=findSet(par[i]);
    }
    void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]) { // if height of x is greater than y
                par[y] = x;
                setSize[x]+=setSize[y];
            }
            else{
                par[x]=y;
                setSize[y]+=setSize[x];
                if(rank[x]==rank[y]) //if height of both is same then height of one will increase
                    rank[y]++;
            }
            numsets--;
        }
    }
    int sizeOfSet(int i) {
      //this function return size of set having i element
        return setSize[findSet(i)]; //we need to go to root of the group
    }
     int numDisjointSets() {
        //return total number of elements at an instance
        return numsets;
        }
};
#endif




/*
//FOR TESTING
int main() {

    string curdir = "/home/ashish/Documents/code/";
    if (
            freopen(string(curdir + "in.txt").c_str(), "r", stdin)
            &&
            freopen(string(curdir + "out.txt").c_str(), "w", stdout)
            );
    else {
        cout << "ERROR: " << strerror(errno) << endl;
        exit(0);
    }

    printf("Assume that there are 5 disjoint sets initially\n");
    UnionFind UF(5); // create 5 disjoint sets
    printf("%d\n", UF.numDisjointSets()); // 5
    UF.unionSet(0, 1);
    printf("%d\n", UF.numDisjointSets()); // 4
    UF.unionSet(2, 3);
    printf("%d\n", UF.numDisjointSets()); // 3
    UF.unionSet(4, 3);
    printf("%d\n", UF.numDisjointSets()); // 2
    cout<<endl;
    printf("isSameSet(0, 3) = %d\n", UF.isSameSet(0, 3)); // will return 0 (false)
    printf("isSameSet(4, 3) = %d\n", UF.isSameSet(4, 3)); // will return 1 (true)
    cout<<endl;
    for (int i = 0; i < 5; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    UF.unionSet(0, 3);
    printf("%d\n", UF.numDisjointSets()); // 1
    for (int i = 0; i < 5; i++) // findSet will return 3 for {0, 1, 2, 3, 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));

    return 0;
}
*/

/*
OUTPUT
----------
Assume that there are 5 disjoint sets initially
5
4
3
2

isSameSet(0, 3) = 0
isSameSet(4, 3) = 1

findSet(0) = 1, sizeOfSet(0) = 2
findSet(1) = 1, sizeOfSet(1) = 2
findSet(2) = 3, sizeOfSet(2) = 3
findSet(3) = 3, sizeOfSet(3) = 3
findSet(4) = 3, sizeOfSet(4) = 3
1
findSet(0) = 3, sizeOfSet(0) = 5
findSet(1) = 3, sizeOfSet(1) = 5
findSet(2) = 3, sizeOfSet(2) = 5
findSet(3) = 3, sizeOfSet(3) = 5
findSet(4) = 3, sizeOfSet(4) = 5
*/
