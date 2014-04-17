
// Jason B. Hill (jason@jasonbhill.com) 2014
// Project Euler C++ Utilities Library

// primes.hpp - header for prime/factorization classes and member functions

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

#ifndef PROJECT_EULER_PRIMES
#define PROJECT_EULER_PRIMES

namespace PE { //------------------ Project Euler namespace -------------------

/*****************************************************************************/
/* Function to find the square root of a number (needed for sieves)          */
/* Input: a uint64_t integer n                                               */
/* Output: a uint64_t integer representing the floor of sqrt(n)              */
/*****************************************************************************/
uint64_t sqrt_uint64(uint64_t n);


namespace primes { //-------------- primes namespace --------------------------

/*****************************************************************************/
/* Prime sieve class                                                         */
/* Constructs a prime sieve and determines all primes less than some limit   */
/*****************************************************************************/
class Sieve {
    private:
    bool*       sieve;

    public:
    uint64_t    limit; // the sieve has indices 0<=x<limit for integers x
    uint64_t    numPrimes; // how many primes are found by the sieve
    uint64_t*   primes; // list of primes (must be initialized)

    /*************************************************************************/
    /* class constructor                                                     */
    /*************************************************************************/
    Sieve(uint64_t m);

    /*************************************************************************/
    /* class destructor                                                      */
    /*************************************************************************/
    ~Sieve();

    /*************************************************************************/
    /* Function to determine if a given number n is prime                    */
    /*************************************************************************/
    bool isPrime(uint64_t n);

    /*************************************************************************/
    /* Function to create a list of primes from a sieve                      */
    /*************************************************************************/
    private:
    void initPrimesList();

};


/*****************************************************************************/
/* Factors class                                                             */
/* Stores prime factor information for an integer                            */
/*****************************************************************************/
class Factors {
    public:
    uint64_t                                n; // the integer being factored
    std::set<uint64_t>*                     primes; // set (BST) of primes
    std::unordered_map<uint64_t,uint8_t>*   exponents; // prime exponent values

    /*************************************************************************/
    /* class constructor                                                     */
    /*************************************************************************/
    Factors(uint64_t m);

    /*************************************************************************/
    /* Calculate the prime/exponent data directly with a sieve               */
    /* This can be replaced later by something more efficient                */
    /*************************************************************************/
    void computeBySieve();

    /*************************************************************************/
    /* Function to determine if a prime divides an integer                   */
    /*************************************************************************/
    bool divides(uint64_t p);

    /*************************************************************************/
    /* Function to print the prime factorization of an integer               */
    /*************************************************************************/
    void print();

};


/*****************************************************************************/
/* FactorRange class                                                         */
/* Uses a sieve to factor a range of integers between 1 and some integer m   */
/*****************************************************************************/
class FactorRange {
    private:
    // for each integer in range, maintain a mapping prime->exponent
    std::unordered_map<uint64_t,uint16_t>*       factors;

    public:
    FactorRange(uint64_t m);

};



} // namespace primes
} // namespace PE

#endif
