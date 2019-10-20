//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_MATHSUTILS_H
#define SAMPLE_MATHSUTILS_H

#include "CommonLibs.h"

//utility functions

template<typename T> T mod(T x){ //this function return |x| value
    return x<0? -x:x;
}
template<typename T> T gcd(T a,T b){
    if(b==0) return a;
    return gcd(b,a%b);
}


//O(log n) power function without mod
long long  power(int i,int c){
    if(c==0) return 1;
    if (c==1) {
        return i;
    }
    long long ans=power(i,c/2);
    ans=(ans*ans);
    if(c%2==1) ans=(ans*i);
    return ans;
}

long long factorial_recursive(int n){
    if(n==1) return 1;
    return n * factorial_recursive(n-1);
}

long long factorial_iterative(int n){
    if(n==1 || n==0 ) return 1;
    long long fact=1;
    for(int i=2;i<=n;i++)
        fact=fact*i;
    return fact;
}

int main(){
    assert(factorial_recursive(1)==1
    && factorial_recursive(1)==0 
    && factorial_recursive(4)==24
       && factorial_recursive(6)==720);


    assert(factorial_iterative(1)==1
           && factorial_iterative(1)==0
           && factorial_iterative(4)==24
           && factorial_iterative(6)==720);
}

#endif