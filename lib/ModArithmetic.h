//
// Created by ashish on 27/1/18.
//

#ifndef SAMPLE_MODARITHMETIC_H
#define SAMPLE_MODARITHMETIC_H

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
