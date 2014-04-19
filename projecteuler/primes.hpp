
// Jason B. Hill (jason@jasonbhill.com) 2014
// Project Euler C++ Utilities Library

// primes.hpp - header for prime/factorization classes and member functions

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

#ifndef PROJECT_EULER_PRIMES
#define PROJECT_EULER_PRIMES


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
uint64_t sqrt_uint64(uint64_t n);


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
class Sieve {
    private:
    bool*       sieve;

    public:
    uint64_t    limit; // the sieve has indices 0<=x<limit for integers x
    uint64_t    numPrimes; // how many primes are found by the sieve
    uint64_t*   primes; // list of primes (must be initialized)

    /* constructor --------------------------------------------------------- */
    Sieve(uint64_t m);

    /* destructor ---------------------------------------------------------- */
    ~Sieve();

    /* function to determine if an integer is prime ------------------------ */
    bool isPrime(uint64_t n);

    /* procedure to form a list of primes - called at construction --------- */
    private:
    void initPrimesList();
};


/*****************************************************************************/
/* Factors class                                                             */
/* ------------------------------------------------------------------------- */
/* Stores prime factor information for an integer                            */
/*****************************************************************************/
class Factors {
    public:
    uint64_t                                n; // the integer being factored
    std::set<uint64_t>                      primes; // set (BST) of primes
    std::unordered_map<uint64_t,uint8_t>    exponents; // prime exponent values

    /* constructor --------------------------------------------------------- */
    Factors();

    /* destructor ---------------------------------------------------------- */
    ~Factors();

    /* compute factor data directly by sieve (useful for a single integer) - */
    void computeBySieve();

    /* function to determine if a prime p divides the integer n ------------ */
    bool divides(uint64_t p);

    /* print the factorization of n ---------------------------------------- */
    void print();

};


/*****************************************************************************/
/* FactorRange class                                                         */
/* ------------------------------------------------------------------------- */
/* Factors a range of integers between 1 and some limit n                    */
/*****************************************************************************/
class FactorRange {
    public:
    uint64_t    limit; // factor all integers in [1,n]
    Factors*    factors; // Factor class instance for each integer in [1,n]
    Sieve*      sieve; // sieve for all primes up to n/2

    /* constructor --------------------------------------------------------- */
    FactorRange(uint64_t n);

    /* destructor ---------------------------------------------------------- */
    ~FactorRange();
};













} // namespace primes
} // namespace PE

#endif
