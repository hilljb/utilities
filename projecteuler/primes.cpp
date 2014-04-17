
// Jason B. Hill (jason@jasonbhill.com) 2014
// Project Euler C++ Utilities Library

// primes.cpp - prime/factorization classes and member functions

/********** LICENSED UNDER THE GPLv3 *****************************************/
/*  This file is part of Jason B. Hill's Project Euler C++ Utilities.        */
/*                                                                           */
/*  Foobar is free software: you can redistribute it and/or modify           */
/*  it under the terms of the GNU General Public License as published by     */
/*  the Free Software Foundation, either version 3 of the License, or        */
/*  (at your option) any later version.                                      */
/*                                                                           */
/*  Foobar is distributed in the hope that it will be useful,                */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            */
/*  GNU General Public License for more details.                             */
/*                                                                           */
/*  You should have received a copy of the GNU General Public License        */
/*  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.          */
/*****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <cstdbool>

#include <set>
#include <unordered_map>

#include <cstdio>

#include "primes.hpp"

namespace PE { //------------------ Project Euler namespace -------------------

/*****************************************************************************/
/* Function to find the square root of a number (needed for sieves)          */
/* Input: a uint64_t integer n                                               */
/* Output: a uint64_t integer representing the floor of sqrt(n)              */
/*****************************************************************************/
uint64_t sqrt_uint64(uint64_t n) {
    uint8_t             shift = 1;
    uint64_t            res, s;
 
    while ((1<<shift) < n) shift += 1;
    res = (1<<((shift>>1) + 1));
    while (1) {
        s = (n/res + res)/2;
        if (s >= res) return res;
        res = s;
    }
}


namespace primes { //-------------- primes namespace --------------------------

/*****************************************************************************/
/* Prime sieve class                                                         */
/* Constructs a prime sieve and determines all primes less than some limit   */
/*****************************************************************************/

/*****************************************************************************/
/* class constructor                                                         */
/*****************************************************************************/
Sieve::Sieve(uint64_t m) {
    uint64_t    i,j,sqrt_limit;

    limit = m;
    sqrt_limit = sqrt_uint64(limit);
    sieve = new bool[limit];
    numPrimes = 0;

    // set all values in sieve initially to 1 except 0 and 1
    sieve[0] = 0;
    sieve[1] = 0;
    for (i=2; i<limit; i++) sieve[i] = 1;

    // sieve out non-primes
    for (i=2; i<sqrt_limit+1; i++) {
        if (sieve[i]==1) {
            for (j=2*i; j<limit; j+=i) sieve[j] = 0;
        }
    }

    // count primes
    for (i=2; i<limit; i++) {
        if (sieve[i]==1) numPrimes += 1;
    }

    // make list of primes
    initPrimesList();
}

/*****************************************************************************/
/* class destructor                                                          */
/*****************************************************************************/
Sieve::~Sieve() {
    delete[] sieve;
    delete[] primes;
}

/*****************************************************************************/
/* Function to determine if a given number n is prime                        */
/*****************************************************************************/
bool Sieve::isPrime(uint64_t n) { return sieve[n]; }

/*****************************************************************************/
/* Function to create a list of primes from a sieve                          */
/*****************************************************************************/
void Sieve::initPrimesList() {
    uint64_t    i,j;
    // create a list of primes
    primes = new uint64_t[numPrimes];
    // fill the list with primes from the sieve
    j=0;
    for (i=0;i<numPrimes;i++) {
        while (!sieve[j]) j++;
        primes[i] = j;
        j++;
    }
}


/*****************************************************************************/
/* Factors class                                                             */
/* Stores prime factor information for an integer                            */
/*****************************************************************************/
Factors::Factors(uint64_t m) {
    // store the integer being factored
    n = m;
    // create a set to hold primes that factor the integer
    primes = new std::set<uint64_t>;
    // create an unordered_map to hold exponent information for primes
    exponents = new std::unordered_map<uint64_t,uint8_t>;
}

/*****************************************************************************/
/* Calculate the prime/exponent data directly with a sieve                   */
/* This can be replaced later by something complete/efficient                */
/*****************************************************************************/
void Factors::computeBySieve() {
    
    // create a prime sieve
    Sieve *S = new Sieve(n+1);

    // if n is prime
    if (S->isPrime(n)) {
        // add the prime and 1 to the set of prime divisors
        primes->insert(1);
        primes->insert(n);
        // add the exponents for each divisor
        exponents->emplace(1,1);
        exponents->emplace(n,1);
    } else { // if n is not prime
        uint64_t    temp_n = n;
        // here you should factor individual integers using a sieve
    }

    delete(S);
}

/*****************************************************************************/
/* Function to print the prime factorization of an integer                   */
/*****************************************************************************/
void Factors::print() {
    // the first implementation won't use ordering
    std::cout << n << " : ";
    for (auto it = exponents->begin(); it != exponents->end(); ++it) {
        if (it != exponents->begin()) std::cout << " * ";
        std::cout << it->first << "^" << (int)it->second;
    }
    std::cout << std::endl;
}











/*****************************************************************************/
/* FactorRange class                                                         */
/* Uses a sieve to factor a range of integers between 1 and some integer m   */
/*****************************************************************************/
FactorRange::FactorRange(uint64_t m) {
    uint64_t    i,j,p;
    uint8_t     k=2;

    // create a sieve of primes
    Sieve* S = new Sieve(m);
    // create a factor record for all integers in range
    factors = new std::unordered_map<uint64_t,uint16_t>[m];

    // for each prime in S.primes, add prime and exponents to factor records
    for (i=0;i<S->numPrimes;i++) {
        p = S->primes[i];
        for (j=p;j<m;j+=p) {
            // factors[j][p] = 1;
            factors[j].emplace(p,k);
        }
    }

    //for (auto& x: factors[39])
    //    std::cout << x.first << ": " << x.second << std::endl;

    //for (auto it = factors[39].begin(); it != factors[6].end(); ++it) {
    //    std::cout << it->first << ":" << sizeof(it->second) << std::endl;
    //}

    std::unordered_map<uint64_t,uint8_t> mymap;
    mymap.emplace(2,1);
    mymap.emplace(20,3);
    mymap.emplace(200,34);

    //for (auto it = mymap.begin(); it != mymap.end(); ++it) {
    //    std::cout << it->first << ":" << (int)it->second << std::endl;
    //    printf("%lld : %d\n", it->first, it->second);
   // }

}


} // namespace primes
} // namespace PE


















int main() {

    //PE::primes::Sieve S = PE::primes::Sieve(100000000);
    //std::cout << "-- done" << std::endl;
    //std::cout << "there are " << S.numPrimes << " primes below " << S.limit << std::endl;

    //std::cout << S.primes[0] << S.primes[1] << S.primes[2] << std::endl;
    //std::cout << S.primes[S.numPrimes-1] << std::endl;

    //PE::primes::FactorRange F = PE::primes::FactorRange(100);

    PE::primes::Factors G = PE::primes::Factors(29);
    G.computeBySieve();
    G.print();

    return 0;
}
