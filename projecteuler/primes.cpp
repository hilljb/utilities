
// Jason B. Hill (jason@jasonbhill.com) 2014
// Project Euler C++ Utilities Library

// primes.cpp - prime/factorization classes and member functions

/********** LICENSED UNDER THE GPLv3 *****************************************/
/* This file is part of Jason B. Hill's Project Euler C++ Utilities.         */
/*                                                                           */
/* Foobar is free software: you can redistribute it and/or modify            */
/* it under the terms of the GNU General Public License as published by      */
/* the Free Software Foundation, either version 3 of the License, or         */
/* (at your option) any later version.                                       */
/*                                                                           */
/* Foobar is distributed in the hope that it will be useful,                 */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU General Public License for more details.                              */
/*                                                                           */
/* You should have received a copy of the GNU General Public License         */
/* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.           */
/*****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <cstdbool>

#include <set>
#include <unordered_map>

#include <cstdio>

#include "primes.hpp"


/*****************************************************************************/
/* Project Euler namespace                                                   */
/* ------------------------------------------------------------------------- */
/* This namespace is shared with other Project Euler utilities. Here, it     */
/* contains the primes subnamespace, which is used mostly for factoring      */
/* lists of integers and doing other tasks (e.g., perfect number testing).   */
/*****************************************************************************/
namespace PE {


/* function to find the square root of an integer (needed for sieves) ------ */
/* input: a uint64_t n                                                       */
/* output: a uint64_t representing the floor of the square root of n         */
uint64_t sqrt_uint64(uint64_t n) {
    uint8_t             shift = 1;
    uint64_t            res, s;
 
    while ((1<<shift) < n) shift += 1;
    res = (1<<((shift>>1) + 1));
    while (1) {
        s = (n/res + res) >> 1;
        if (s >= res) return res;
        res = s;
    }
}


/*****************************************************************************/
/* primes namespace                                                          */
/* ------------------------------------------------------------------------- */
/* Contains Sieve class (uses a sieve to form a list of primes), needed in   */
/* the Factors class (uses STL containers to record prime factors and the    */
/* corresponding exponents for factored integers). The current design is     */
/* primarily focused on factoring (large) lists of consecutive integers, as  */
/* many of the Project Euler problems require this. There isn't currently a  */
/* concentration on factoring of individual (random/large) integers, and     */
/* thus there is no quadratic sieve or elliptic curve method here. Keep in   */
/* mind that such methods are designed for solitary integers. Here, we're    */
/* considering lists of integers, which are more efficiently factored with a */
/* sieve. The only function here requiring much math is that which computes  */
/* the sum of divisors of an integer from the known prime factors.           */
/*****************************************************************************/
namespace primes {


/*****************************************************************************/
/* Prime sieve class                                                         */
/* ------------------------------------------------------------------------- */
/* Constructs a prime sieve and determines all primes less than some limit   */
/*****************************************************************************/

/* constructor ------------------------------------------------------------- */
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

/* destructor -------------------------------------------------------------- */
Sieve::~Sieve() {
    delete[] sieve;
    delete[] primes;
}

/* function to determine if an integer is prime ---------------------------- */
bool Sieve::isPrime(uint64_t n) { return sieve[n]; }

/* procedure to form a list of primes - called at construction ------------- */
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
/* ------------------------------------------------------------------------- */
/* Stores prime factor information for an integer                            */
/*****************************************************************************/

/* constructor ------------------------------------------------------------- */
Factors::Factors() {
    // store the integer being factored
    n = 0;
    // create a set to hold primes that factor the integer
    //primes = new std::set<uint64_t>;
    // create an unordered_map to hold exponent information for primes
    //exponents = new std::unordered_map<uint64_t,uint8_t>;
}

/* destructor -------------------------------------------------------------- */
Factors::~Factors() { }

/* compute factor data directly by sieve (useful for a single integer) ----- */
void Factors::computeBySieve() {
    
    // create a prime sieve
    Sieve *S = new Sieve(n+1);

    // if n is prime
    if (S->isPrime(n)) {
        // add the prime and 1 to the set of prime divisors
        primes.insert(1);
        primes.insert(n);
        // add the exponents for each divisor
        exponents.emplace(1,1);
        exponents.emplace(n,1);
    } else { // if n is not prime
        uint64_t    temp_n = n;
        // here you should factor individual integers using a sieve
    }

    delete(S);
}

/* function to determine if a prime p divides the integer n ---------------- */
bool Factors::divides(uint64_t p) {
    return primes.find(p) != primes.end();
}

/* print the factorization of n -------------------------------------------- */
void Factors::print() {

    std::cout << "test output for factors" << std::endl;
}


/*****************************************************************************/
/* FactorRange class                                                         */
/* ------------------------------------------------------------------------- */
/* Factors a range of integers between 1 and some limit n                    */
/*****************************************************************************/

/* constructor ------------------------------------------------------------- */
FactorRange::FactorRange(uint64_t n) {
    uint64_t        i,j,p;

    // set the upper limit of the factor range to n
    limit = n;
    // create a sieve of all primes up to and including limit
    sieve = new Sieve(limit + 1);
    // create a list of Factor class objects
    factors = new Factors[limit+1];
    // store integer values
    for (i=1;i<=n;i++) factors[i].n = i;

    // for each prime in S->primes, consider multiples
    for (i=0;i<sieve->numPrimes;i++) {
        p = sieve->primes[i];
        j = p;
        while (j <= limit) {
            factors[p].primes.insert(p);
            j += p;
        }
    }
}

/* destructor -------------------------------------------------------------- */
FactorRange::~FactorRange() {
    delete sieve;
    delete[] factors;
}





} // namespace primes
} // namespace PE


















int main() {

    //PE::primes::Sieve S = PE::primes::Sieve(100000000);
    //std::cout << "-- done" << std::endl;
    //std::cout << "there are " << S.numPrimes << " primes below " << S.limit << std::endl;

    //std::cout << S.primes[0] << S.primes[1] << S.primes[2] << std::endl;
    //std::cout << S.primes[S.numPrimes-1] << std::endl;

    PE::primes::FactorRange* F = new PE::primes::FactorRange(5);

    for (uint64_t i=1;i<=5;i++) {
        std::cout << F->factors[i].n << std::endl;
    }

    delete F;

    return 0;
}
