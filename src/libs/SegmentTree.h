//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_SEGMENTTREE_H
#define SAMPLE_SEGMENTTREE_H

#include "CommonLibs.h"

//RANGE MIN QUERY WITH SIMPLE SEGMENT TREE

//find notes for segments tree in notes/

class SegmentTree{

private:

    vector<int> st,A;
    int n;
    /*
     * there are two kinds of indexes here
     * 1 - i,j which is for navigating into underlying array
     * 2 - p which is for navigating to segment tree
    */
    int left(int p){
        return p<<1;
    }
    int right(int p){

        // we can't do return p<<1+1; because of priority of << is less than +
        return (p<<1)+1;
    }

    void build(int p,int l,int r){
        if(l==r){
            st[p]=A[l];
            return ;
        }
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        st[p]=min(st[left(p)],st[right(p)]);
        //we storing value as it works always( in all types of problems like range sum) , and index works only when we have to find single value
    }

    int rmq(int p,int l,int r,int i,int j){
        /* there are 3 total possibility of range occurring between two range
         *  1- [l-r] lies fully inside [i,j]
         *  2- [l-r] lies outside [i,j], either in left or right
         *  3- some part of [i,j] lies inside [l,r], in this case go breaking [l,r]
         *  so we can get full part
         *  Note - i & j are never changing, only l and r are changing with each recursion
         */
        if(r<i || l>j) return INVALID; //out or range
        if(l>=i && r<=j) return st[p]; //this segment is inside what is required

        int min1= rmq(left(p),l,(l+r)/2,i,j);
        int min2= rmq(right(p),(l+r)/2+1,r,i,j);
        if(min1==INVALID) return min2;
        if(min2==INVALID) return min1;
        //if both are not INVALID, return min

        return min(min1,min2);
    }

    void updateRange(int p,int l,int r,int i,int j,int value){
        //here we really updating value and not looking on lazy things etc.
        //we just update value and coming back we will just find min. of two childs
        // to get min again
        if( l>j || r<i ) //out of range
            return; //not thing has to be done

        /*
         * NOTE- here important thing to note is that if we are not using any lazy
         *         kind of thing, then it is not possible to check for condition
         *         if(l>=i && r<=j)  //this segment is inside what is required,
         *         and update whole array at once, because in this way underlying segment tree will
         *         will never get updated, so either we have to rebuild it , which will take much more time(nlog(n)),
         *         or a better option to just go to every individual element and update it, in this way when we come
         *         upward we will automatically update our underlying tree.
                NOTE - In lazy we are not changing underlying st[] and put here value in lazy[], but that facility is not here,
                so we have to go to each element and update it and while coming back recurse to get new values.

                here in place of  if(l>=i && r<=j) ( if fully inside)
                we are going to each element and then updating
         */

        if(l==r) {
            st[p] = value; //found one element, so update
            return;
        }

        //if more than 1 element in this range and it is to be updated
        updateRange(left(p),l,(l+r)/2,i,j,value);
        updateRange(right(p),(l+r)/2+1,r,i,j,value);

        st[p]=min(st[left(p)],st[right(p)]); //collect values to make it valid again
    }
public:
    SegmentTree(vector<int> &A){
        this->A=A;
        this->n=A.size();
        st.resize(4*n,INVALID);//INVALID
        this->build(1,0,n-1);
//        show_1d(st);
    }

    // range min query
    int rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }
    void updateRange(int i,int j,int value){
        // this function updates range [i,j] with st[p]=value

        for(int k=i;k<=j;k++)
            A[k]=value; //modifying underlying array, its actually not required but good to have same data in A also

        updateRange(1,0,n-1,i,j,value);
//        show_1d(st);
    }

    void display(){
        cout<<"Showing Segment Tree - "<<endl;
        for(int i=0;i<st.size();i++){
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }

};

#endif

//range min query
/* int main() {

    int n=10;
    vector<int> A;
    for(int i=0;i<n;i++) A.push_back(i+1); // stores 1 to 10

    SegmentTree S(A);
    cout<<S.rmq(0,3)<<endl;
    cout<<S.rmq(3,6)<<endl;
    S.updateRange(0,3,50);
    cout<<S.rmq(0,4)<<endl;
    return 0;
}
*/

//output
//1
//4
//5
