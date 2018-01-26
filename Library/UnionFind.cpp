//
// Created by ashish on 26/1/18.
//

class UnionFind{
public:
    vi par,rank,setSize;
    int numsets;
    UnionFind(int n){
        par.assign(n,0);rank.assign(n,0);
        setSize.assign(n,1);
        numsets=n;
        for(int i=0;i<n;i++) par[i]=i;
    }
    bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    int findSet(int i){
        return par[i]==i?i:par[i]=findSet(par[i]);
    }
    void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]) {
                par[y] = x;
                setSize[x]+=setSize[y];
            }
            else{
                par[x]=y;
                setSize[y]+=setSize[x];
                if(rank[x]==rank[y])
                    rank[y]++;
            }
            numsets--;
        }
    }
};