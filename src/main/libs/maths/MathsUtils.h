//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_MATHSUTILS_H
#define SAMPLE_MATHSUTILS_H

#include "../CommonLibs.h"

//utility functions

template<typename T> T mod(T x){ //this function return |x| value
    return x<0? -x:x;
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

/*
 * NO. of perfect squares between A and B (inclusive)
 *
 * source - https://www.geeksforgeeks.org/find-number-perfect-squares-two-given-numbers/

 floor(sqrt(b)) - ceil(sqrt(a)) + 1

    We take floor of sqrt(b) because we need to consider
    numbers before b.

    We take ceil of sqrt(a) because we need to consider
    numbers after a.

    For example, let b = 24, a = 8.  floor(sqrt(b)) = 4,
    ceil(sqrt(a)) = 3.  And number of squares is 4 - 3 + 1
    = 2. The two numbers are 9 and 16.
 * */

ll numberOfPerfectSquaresBw(ll a, ll b){
    // note - sqrt() doesn't work for long long some so use sqrtl() instead.
    // if we do not want to include both just remove +1, same as simple range count;
    ll ans=floor(sqrtl(b)) - ceil(sqrtl(a)) + 1;
    return ans;
}



void testMathUtils(){
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


    assert( nCr(5,2) == 10
            && nCr(5,1) == 5
            && nCr(10,3) == 120
    );

    assert(numberOfPerfectSquaresBw(1,100) == 10
    &&
     numberOfPerfectSquaresBw(9,25) == 3
    );
}
#endif
