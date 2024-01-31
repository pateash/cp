//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_GCD_LCM_UTILS_H
#define SAMPLE_GCD_LCM_UTILS_H

#include "../CommonLibs.h"

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

void testGcdLcmUtils(){

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
}
#endif
