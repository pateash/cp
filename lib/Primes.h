//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_PRIMES_H
#define SAMPLE_PRIMES_H
#include<bits/stdc++.h>
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