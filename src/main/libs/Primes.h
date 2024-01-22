//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_PRIMES_H
#define SAMPLE_PRIMES_H

#include "CommonLibs.h"


/*
 * sieve of erorsthenesis
 * O(nlog(log(n))
 */
#define SIEVE_LIMIT int(1e7+10) //must be some greater than 'max_number'
class Sieve{
private:
    long long _sieve_size; // size for bitset[0....max_number] for storing 0/1
    bitset<SIEVE_LIMIT> bs; //10^7 should be enough for most cases _sieve_size<10^7
    vector<long long> primes;//storing all primes from [2..max_number]

public:
    Sieve(long long max_number) {
        //building list of primes from [2..max_number]
        _sieve_size = max_number + 1; //from 0 to max_number
        bs.set(); //set all to prime
        bs[0] = bs[1] = 0; //0 and 1 are not prime

        for (long long i = 2; i <= _sieve_size; i++) {
            if (bs[i]) {
                //if it is an prime then cut all which are large than it and have it as factor
                primes.push_back(i);
                for (long long j = i * i;
                     j <= _sieve_size; j += i) // all less than i*i would have been already cutted by others
                    bs[j] = 0;
            }
        }
    }

    void printPrimes() {
        //print Primes from 2 to max_number
        for (auto p: primes)
            cout << p << "\n";
        cout << endl;
    }

    bool isPrimeSieve(long long N) {
        if (N <= _sieve_size) return bs[N];

        //if it is not inside the max_number
        // we can use stored primes to find if it is prime or not
        // only can check if N<=(largest Prime)^2

        for (auto p: primes) {
            if (N % p == 0) return false;
        }
        return true;
    }

};

/*
 * return if a number is prime or not
 * O(sqrt(n))
 */
bool isPrimeSimple(int n) {
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 3, sz = sqrt(n); i <= sz; i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// log(N)
bool isPrimeFast(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;

    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }
    return true;
}

#endif
