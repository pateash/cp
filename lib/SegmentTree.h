//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_SEGMENTTREE_H
#define SAMPLE_SEGMENTTREE_H
#include<iostream>
#include<cstdio>
#include <cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<unordered_map>
#include<unordered_set>
//types
#define llu long long unsigned int
#define ll long long int
//container
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
//IO
#define pr(n)  printf("%d",n)
#define prl(n) printf("%lld",n)
#define prf(n) printf("%f",n)
#define nl printf("\n")
#define sp printf(" ")
#define sc(n)  scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scf(n) scanf("%f",&n)
#define scd(n) scanf("%lf",&n)
//function and loops
#define mp make_pair
#define repab(a,b) for(int i=(a);i<(b);i++)
#define rep(n) for(int i=0;i<n;i++)
#define repi(i,n) for(int (i)=0;(i)<n;(i)++)
#define repit(c) for(auto it=(c).begin();it!=(c).end();it++)
//reading all once
#define read(n) int n;sc(n)
#define readl(n) ll n;scl(n)
#define readf(n) float n;scf(n)
#define readd(n) double n;scd(n)
#define call(c) (c).begin(),(c).end()
//debug
#define show(a) std::cout<<#a<<" : "<<a<<std::endl;
using namespace std;

//RANGE MIN QUERY WITH SIMPLE SEGMENT TREE

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
        //we storing value as it works always , and index works only when we have to find single value
    }
    int rmq(int p,int l,int r,int i,int j){
        /* there are 3 total possibility of range occurance between two range
         *  1- [l-r] lies fully inside [i,j]
         *  2- [l-r] lies outside [i,j], either in left or right
         *  3- some part of [i,j] lies inside [l,r], in this case go breaking [l,r]
         *  so we can get full part
         */
        if(r<i || l>j) return -1; //out or range
        if(l>=i && r<=j) return st[p]; //this segment is inside what is required

        int min1= rmq(left(p),l,(l+r)/2,i,j);
        int min2= rmq(right(p),(l+r)/2+1,r,i,j);
        if(min1==-1) return min2;
        if(min2==-1) return min1;
        //if both are not -1, return min
        int ans=min(min1,min2);
        return ans;
    }

    void updateRange(int p,int l,int r,int i,int j,int value){
        //here we really updating value and not looking on lazy things etc.
        //we just update value and coming back we will just find min. of two childs
        // to get min again
        if(r<i || l>j) //out of range
            return; //not thing has to be done

        /*
         * NOTE- here important thing to note is that if we are not using any lazy
         *         kind of thing, then it is not possible to check for condition
         *         if(l>=i && r<=j)  //this segment is inside what is required,
         *         and update whole array at once, because in this way underlying segment tree will
         *         will never get updated, so either we have to rebuild it , which will take much more time(nlog(n)),
         *         or a better option to just go to every individual element and update it, in this way when we come
         *         upward we will automatically update our underlying tree.
                NOTE - in lazy we are changind underlying st, when needed but that facility is not here.
         */

        if(l==r) {//only one element in range, and not of range means we have to update it
            st[p] = value; //so update
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
        st.resize(4*n,-1);//-1 represent nothing
        this->build(1,0,n-1);
//        show_1d(st);
    }

    int rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }
    void updateRange(int i,int j,int value){
        // this function updates range [i,j] with st[p]=value

// for(int k=0;k<=j;k++) A[k]=value;//modifying underlying array remove if not required

        updateRange(1,0,n-1,i,j,value);
//        show_1d(st);
     }
};

#endif


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
//    test_working();
    clock_t t1=clock(),t2;
       int n=10;
    vector<int> A;
    for(int i=0;i<n;i++) A.push_back(i+1);

  SegmentTree S(A);
    cout<<S.rmq(0,3)<<endl;
    cout<<S.rmq(3,6)<<endl;
    S.updateRange(0,3,50);
    cout<<S.rmq(0,4)<<endl;
    t2=clock();
    //   cout<<endl<<"time is "<<(t2-t1)/(1.0*CLOCKS_PER_SEC)<<" seconds"<<endl;
    return 0;
}
*/

//output
//1
//4
//5
