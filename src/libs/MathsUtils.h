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

/***** GCD of 2 ELEMENTS ****/

template<typename T> T gcd(T a,T b){
    if(b==0) return a;
    return gcd(b,a%b);
}


/***
GCD OF N ELEMENTS
--------------------
take ans=arr[0](as gcd of 1 element is itself)
similary lcm of n elements can be found by iterating through while array and using
ans as a and a[i] as b;
*/

template<typename T>
T gcdArray(vector<T> v){
    int ans=v[0];
    for(int i=0; i < v.size(); i++)
        ans=gcd(ans, v[i]);
    return ans;
}

/***** LCM of 2 ELEMENTS ****/

template<typename T> T lcm(T a,T b){
    return a*b/gcd(a,b);
}



/***
LCM OF N ELEMENTS
------------------
NOTE- formual lcm*gcd=a*b only hold for two values, for three value it doesn't
so we can find it like
take ans=arr[0](as lcm of 1 element is itself)
lcm(ans,a[i])=(ans*arr[i])/(gcd(ans,a[i]))
*/

template<typename T>
int lcmArray(vector<T> v) {
    int ans= v[0];
    for (int i = 0; i < v.size(); i++) {
        ans= ans * v[i] / gcd(ans, v[i]);
    }
    return ans;
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
    if(n==1 || n==0) return 1;
    return n * factorial_recursive(n-1);
}

long long factorial_iterative(int n){
    if(n==1 || n==0 ) return 1;
    long long fact=1;
    for(int i=2;i<=n;i++)
        fact=fact*i;
    return fact;
}

/*
 * C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1
 * */

#define LIMIT 21
llu dp_nCr[LIMIT][LIMIT]; // Note - don't forget to initialize it in main()

// dp solution
llu nCrDPSolution(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    llu &x=dp_nCr[n][r];
    if(x != -1)
        return x;
    x=nCrDPSolution(n-1,r) + nCrDPSolution(n-1,r-1);
    return x;
}

llu nCr(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    return nCr(n-1,r) + nCr(n-1,r-1);
}

void testMathUtils(){

    // gcd and lcm
    assert(gcd(10,25)==5
            && gcd(30,45) == 15
            && lcm(10,25) == 50
            && lcm(30,45) == 90
            );

    vector<int> v1= {1, 2,3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v2= { 30, 15, 60, 100};

    assert(
            gcdArray(v1) == 1
            &&  lcmArray(v1) == 2520
    );

    assert(
            gcdArray(v2) == 5
            &&  lcmArray(v2) == 300
    );

    assert(factorial_recursive(1)==1
           && factorial_recursive(0)==1
           && factorial_recursive(4)==24
           && factorial_recursive(6)==720);


    assert(factorial_iterative(1)==1
           && factorial_iterative(0)==1
           && factorial_iterative(4)==24
           && factorial_iterative(6)==720);

    memset(dp_nCr, -1, sizeof(dp_nCr));

    assert( nCrDPSolution(5,2) == 10
            && nCrDPSolution(5,1) == 5
            && nCrDPSolution(10,3) == 120
    );


    assert( nCr(5,2) == 100
            && nCr(5,1) == 5
            && nCr(10,3) == 120
    );
}

#endif
