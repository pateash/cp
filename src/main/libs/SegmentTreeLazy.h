//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_SEGMENTTREELAZY_H
#define SAMPLE_SEGMENTTREELAZY_H

#include "CommonLibs.h"

//find notes for segments tree in notes/

//RANGE SUM QUERY WITH LAZY SEGMENT TREE
//update(i,j) update all values from [i,j] by value;
/*
 * IDEA-
 *   the idea is that we always update lazyness whenever we got any node,
 *   and propagate laziness to its child and so on.
 */

// it is possible to keep INVALID and LAZY_DEFAULT same, but its better to keep them different
#define INVALID -999999  //invalid will be something which can't be ther be there in segment tree
#define LAZY_DEFAULT -1 //lazy default could be something which can't be there in lazy

//INVALID will be used in query() to find which part is correct and not out of bound also could be used to initially set values in SegmentTree

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

    //this function will do lazy update when we reach at that node in segment tree in query or update
    void  lazy_update(int p,int l,int r){
        if(lazy[p]!=LAZY_DEFAULT){

            //yaha tak aaye to update kardo
            st[p]=(r-l+1)*lazy[p]; //this value will be when updated

            //we have to check if it is not a leaf node,
            // there couldn't be a case where a node having one child only(left or right) as we are deviding binarily, so
            // possible childs are only 2 or 0

            if(l!=r)
                lazy[left(p)]=lazy[right(p)]=lazy[p]; //we will never get out of bound as we have enough space 4*N
            lazy[p]=LAZY_DEFAULT;
        }
    }
    //range sum query
    int query(int p,int l,int r,int i,int j){
        //update the lazy_tree, if we have arrived here
        // without lazy_update, value could be wrong(dirty) as there might be some updating in lazy[]
        lazy_update(p,l,r);

        if(i>r || j<l ) //case1
            return INVALID;

        //In query we have to resolve only previous lazyness
        //but in update we have to also do current query update with value
        if(i<=l && r<=j) //case2
            //laziness already resolved we can return this
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
        //update the lazy_tree, if we have arrived here
        lazy_update(p,l,r);

        if(i>r || j<l ) return;  //case1

        if(i<=l && r<=j) {//case2
            //IMP: lazy was of before, now we have to update a/c to current query
            // we can't do just lazy[p]=value, here because when we go back we have to provide correct value to parents,
            // as they have lazy[p]=LAZY_DEFAULT
            st[p]=(r-l+1)*value; //update this node
            if(l!=r)  //pass laziness to children
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
        st.assign(4*n,INVALID);
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
    void display(){
        cout<<"Showing Segment Tree - "<<endl;
        for(int i=0;i<st.size();i++){
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }

};

//FOR TESTING

/* int main() {

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
INPUT-1
5
1 2 3 4 5
5
0 1 3
1 1 3 6
0 1 3
1 2 4 3
0 2 3

OUTPUT-1
9
18
6

 */
/*
INPUT-2
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

OUTPUT-2
9
15
18
6
12
16

 */
#endif
