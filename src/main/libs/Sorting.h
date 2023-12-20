//
// Created by ashish on 27/1/18.
//

#ifndef SAMPLE_SORTING_H
#define SAMPLE_SORTING_H

//
// Created by ashish on 26/1/18.
//

#include "CommonLibs.h"

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

void testSorting()
{
    vi v = {10, 7, 8, 9, 1, 5};
    quick_sort(v, 0, v.size()-1);
    vi ans = { 1, 5, 7, 8, 9,10};

    for (int i = 0; i < v.size(); ++i) {
//        cout<<v[i]<<" ";
        assert(v[i]==ans[i]);
    }
}

#endif
