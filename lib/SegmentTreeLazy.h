//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_SEGMENTTREELAZY_H
#define SAMPLE_SEGMENTTREELAZY_H
#include <bits/stdc++.h>
using namespace std;

//RANGE SUM QUERY WITH LAZY SEGMENT TREE
//update(i,j) update all values from [i,j] by value;
/*
 * IDEA-
 *   the idea is that we always update lazyness whenever we got any node,
 *   and propogate lazyness to its child and so on.
 */
#define INVALID -999999  //invalid will be something which can't be ther be there in segment tree
#define LAZY_DEFAULT -1 //lazy default could be something which can't be there in lazy
//INVALID will be used in query() to find which part is correct and not out of bound

class SegmentTreeLazy{
    vector<int> st,lazy,A;
    int n;
    int left(int p){return p<<1;}

    int right(int p){return left(p)+1;}

    void build(int p,int l,int r){
        if(l==r){
            st[p]=A[l];
            return;
        }
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        st[p]=st[left(p)]+st[right(p)];
    }

    int query(int p,int l,int r,int i,int j){
        //TODO: ENHANCEMENT lazy updation could be added in a different function
        if(lazy[p]!=LAZY_DEFAULT){
            //yaha tak aaye to update kardo
            st[p]=(r-l+1)*lazy[p]; //this value will be when updated

            //we have to check if it is not a leaf node
            if(l!=r)
                lazy[left(p)]=lazy[right(p)]=lazy[p];
            lazy[p]=LAZY_DEFAULT;
        }
        if(i>r || j<l ) //case1
            return INVALID;

        //In query we have to resolve only previous lazyness
        //but in update we have to also do current query update with value
        if(i<=l && r<=j) //case2
            //lazyness already resolved we can return this
            return st[p];
        else{//case3
            int ans1=query(left(p),l,(l+r)/2,i,j);
            int ans2=query(right(p),(l+r)/2+1,r,i,j);
            if(ans1==INVALID) return ans2; //we can also return 0 here as it will not harm
            if(ans2==INVALID) return ans1;
            return ans1+ans2;
        }

    }

        //update  A[i..j] as value
    void update(int p,int l,int r, int i,int j,int value){
        if(lazy[p]!=LAZY_DEFAULT){
            //yaha tak aaye to update kardo
            st[p]=(r-l+1)*lazy[p]; //this value will be when updated

            //we have to check if it is not a leaf node
            if(l!=r)
                lazy[left(p)]=lazy[right(p)]=lazy[p];
            lazy[p]=LAZY_DEFAULT;
        }

        if(i>r || j<l ) return;  //case1

        if(i<=l && r<=j) {//case2
            //IMP: lazy was of before, now we have to update a/c to current query
            st[p]=(r-l+1)*value; //update this node
            if(l!=r)  //pass lazyness to childs
                lazy[left(p)]=lazy[right(p)]=value;
            return;
        }
        else{ //case3
            update(left(p),l,(l+r)/2,i,j,value);
            update(right(p),(l+r)/2+1,r,i,j,value);
            st[p]=st[left(p)]+st[right(p)];
            //because we have updated we have to recollect
        }
    }

public:
    SegmentTreeLazy(vector<int> &A){
        this->A=A;
        n=A.size();
        st.assign(4*n,0);
        lazy.assign(4*n,LAZY_DEFAULT);
        build(1,0,n-1);
       // show_1d(st);
       // cout<<"---------"<<endl;
    }
    int query(int i,int j){
        return query(1,0,n-1,i,j);
    }
    void update(int i,int j,int value){
        //update  A[i..j] as value
        update(1,0,n-1,i,j,value);
    }
};

//FOR TESTING

/*
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
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    SegmentTreeLazy st(v);
    int q;cin>>q;

    for(int k=0;k<q;k++){
        int type;
        cin>>type;
        if(type==0)//query
        {
            int i,j;
            cin>>i>>j;
            cout<<st.query(i,j)<<endl;
        }else{
            int i,j,value;
            cin>>i>>j>>value;

            //update [i,j] with value,
            //similary we can code to add value to [i,j]
            st.update(i,j,value);
        }
    }
    return 0;
}
*/

/*
INPUT
5
1 2 3 4 5
8
0 1 3
0 0 4
1 1 3 6
0 1 3
1 2 4 3
0 2 3
0 1 3
0 0 4

OUTPUT
9
15
18
6
12
16

 */
#endif