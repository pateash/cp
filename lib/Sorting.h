//
// Created by ashish on 27/1/18.
//

#ifndef SAMPLE_SORTING_H
#define SAMPLE_SORTING_H

//
// Created by ashish on 26/1/18.
//
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

template<typename T>
int quick_sort_partition(vector<T> &v,int l,int r){

    int i=l-1;
    int pivot=r;

    for (int j = l; j < r ; ++j) {
       // if we find any element at J less than pivot, i++ and swap i and j
        if(v[j]<v[pivot]){
            i++;
            swap(v[j],v[i]);
        }

    }
    //now we can place pivot at its right position which is i+1
    swap(v[pivot],v[i+1]);

    return i+1; // this is new pivot
}

template<typename T>
void quick_sort(vector<T> &v, int low,int high){

    //if only one element
    if(high<=low) return;

    //partition by pivot
    int pivot=quick_sort_partition(v,low,high);

    // go for both partitions
    quick_sort(v,low,pivot-1);
    quick_sort(v,pivot+1,high);
}

int main()
{
    vi v = {10, 7, 8, 9, 1, 5};
    quick_sort(v, 0, v.size()-1);

    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    return 0;
}

#endif
