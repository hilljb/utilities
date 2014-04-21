#!/usr/bin/python2

import time


class Sieve:
    """
    Creates a prime sieve and forms all primes less than some limit.
    """
    def __init__(self, limit, verbose=False):
        self.limit = limit
        self.primes = []
        self.numPrimes = 0
        if verbose:
            print "forming sieve of size", self.limit
            start = time.time()
        self.sieve = [True] * self.limit
        self.sieve[0], self.sieve[1] = False, False
        for key,val in enumerate(self.sieve):
            if val:
                self.primes.append(key)
                self.numPrimes += 1
                for k in range(key*2,self.limit,key):
                    self.sieve[k] = False
        if verbose:
            elapsed = time.time() - start
            print "found %s primes in %s seconds" % (self.numPrimes, elapsed)

    def __repr__(self):
        """
        Machine representation of Sieve class object.
        """
        return "%s(%r)" % (self.__class__, self.__dict__)

    def __str__(self):
        """
        String representation of Sieve class object.
        """
        return "%s object with %s primes below %s" % (self.__class__, self.numPrimes, self.limit)

    def isPrime(self, n):
        """
        Returns True if n is prime and False otherwise.
        """
        return self.sieve[n]


class Factors:
    """
    Stores prime and exponent information for an integer.
    """
    def __init__(self, n):
        self.n = n
        self.primes = set()
        self.exponents = {}

    def __repr__(self):
        """
        Machine representation of Factors class object.
        """
        return "%s(%r)" % (self.__class__, self.__dict__)

    def __str__(self):
        """
        String representation of Factors class object.
        """
        s = "%s :" % self.n
        for p in sorted(self.exponents.keys()):
            s += " %s^%s" % (p,self.exponents[p])
        return s

    def addPrime(self, p):
        """
        Include the prime p as a prime divisor or n.
        """
        self.primes.add(p)
        e = 0
        f = self.n
        while f % p == 0:
            e += 1
            f /= p
        self.exponents[p] = e

    def isDivisible(self, p):
        """
        Returns true if n is divisible by p and returns false otherwise.
        """
        if p in self.primes:
            return True
        else:
            return False

    def isPerfect(self):
        """
        Return true if n is a perfect number.
        """
        if self.sumDivisors() - self.n == self.n:
            return True
        else:
            return False

    def sumDivisors(self):
        """
        Returns the sum of the divisors of n.

        Example: n=28 returns 1+2+4+7+14+28=56.
        """
        s = 1
        for p in self.primes:
            s *= (p**(self.exponents[p]+1)-1)/(p-1)
        return s

    def initBySieve(self):
        """
        Use a (newly formed) sieve to factor n. Inefficient if used iteratively.
        """
        S = Sieve(self.n + 1)
        for p in S.primes:
            if self.n % p == 0:
                self.addPrime(p)


class FactorRange:
    """
    Factor a range of integers using a sieve. each factored integer is stored a
    Factors class instance.
    """
    def __init__(self, n):
        self.sieve = Sieve(n+1)
        self.factors = {}
        for i in range(1,n+1,1):
            self.factors[i] = Factors(i)
        for p in self.sieve.primes:
            for i in range(p,n+1,p):
                self.factors[i].addPrime(p)
    def __repr__(self):
        """
        Machine representation of FactorRange class object.
        """
        return "%s(%r)" % (self.__class__, self.__dict__)



def sumDivisors(n, sieve=None):
    """
    Factor n using a sieve and return the sum of its factors.
    """
    if not sieve:
        sieve = Sieve(n+1)
    f = Factors(n)
    for p in sieve.primes:
        if p <= n and n % p == 0:
            f.addPrime(p)
    return f.sumDivisors()


def sumProperDivisors(n, sieve=None):
    return sumDivisors(n, sieve) - n


def isPerfect(n, sieve=None):
    """
    Return True if n is a perfect number.
    """
    if sumProperDivisors(n, sieve) == n: return True
    return False
