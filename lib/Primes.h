//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_PRIMES_H
#define SAMPLE_PRIMES_H
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
using namespace std;

/*
 * sieve of erorsthenesis
 * O(nlog(log(n))
 */
#define SIEVE_LIMIT int(1e7+10) //must be some greater than 'upperbound'
class Sieve{
private:
    long long _sieve_size; // size for bitset[0....upperbound] for storing 0/1
    bitset<SIEVE_LIMIT>bs; //10^7 should be enough for most cases _sieve_size<10^7
    vector<long long> primes;//storing all primes from [2..upperbound]

public:
    Sieve(long long  upperbound){
        //building list of primes from [2..upperbound]
        _sieve_size=upperbound+1; //from 0 to upperbound
        bs.set(); //set all to prime
        bs[0]=bs[1]=0; //0 and 1 are not prime

        for(long long i=2;i<=_sieve_size;i++){
            if(bs[i]){
                //if it is an prime then cut all which are large than it and have it as factor
                primes.push_back(i);
                for(long long j=i*i;j<=_sieve_size;j+=i) // all less than i*i would have been already cutted by others
                    bs[j]=0;
            }
        }
    }

    void printPrimes(){
        //print Primes from 2 to upperbound
        for(auto p:primes)
            cout<<p<<"\n";
        cout<<endl;
    }

    bool isPrimeSieve(long long N){
        if(N<=_sieve_size) return bs[N];

        //if it is not inside the upperbound
        // we can use stored primes to find if it is prime or not
        // only can check if N<=(largest Prime)^2

        for(auto p:primes){
            if(N%p==0) return false;
        }
        return true;
    }

};

bool isPrimeSimple(int n){
    /*
     * return if a number is prime or not
     * O(sqrt(n))
     */
    for(int i=2;i*i<=n;i++){
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

#endif