//
// Created by ashish on 27/1/18.
//

#ifndef SAMPLE_MODARITHMETIC_H
#define SAMPLE_MODARITHMETIC_H

//
// Created by ashish on 26/1/18.
//
#include<bits/stdc++.h>
using namespace std;


//these will be used to store results for euclid's extendex algorithm
int x,y,d;
long long powerMod(int i,int c,int MOD){
    if(c==0) return 1;
    if (c==1) {
        return i%MOD;
    }
    /*ans is required long long, as ans*ans might get heavy
     * before mod applied */
    long long ans=powerMod(i,c/2,MOD);
    ans=(ans*ans)%MOD;
    if(c%2==1) ans=(ans*i)%MOD;
    return ans;
}
void extendedEuclid(int a,int b) {
    if(b==0) {
        d=a;
        x=1;
        y=0;
        return;
    }
    extendedEuclid(b,a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int modIFerm(int A,int M){
    /*applying fermat's theorem A^-1=A^(M-2)%M
     * applicable only when M is prime
     * */
    return powerMod(A,M-2,M);
}
int modIEuclid(int A,int M){
    /* applying extended euclid algo
     * applicable only when A and M are co-prime ie. GCD(A,M)=1
     * */
    extendedEuclid(A,M);
    return (x%M+M)%M;
    //as x could be negative, first reduce it(even if negative)
    //and then make it between [0,M-1] by taking modulo
}



#endif //SAMPLE_MODARITHMETIC_H
