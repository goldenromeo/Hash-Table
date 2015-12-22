/*****************************************
** File:    HashLibrary.h
** Project: CMSC 341 Project 5, Fall 2015
** Author:  Rommel Trejo
** Date:    12/01/15
** Section: 4
** E-mail:  rommel1@umbc.edu
**
**   This file contains the code definitions for the Hash Library hash functions
 *
 *  static int lengthHash(std::string plain, int modBase, int base=0);  hashes based on lenght(string)
 *  static int sumHash(std::string plain, int modBase, int base=0);     hashes based on sum ( value(i))
 *  static int sumProdHash(std::string plain, int modBase, int base=0);     hashes bases on ith char in string sum ( value(i) * i+1)
 *  static int polynomialHash(std::string plain, int modBase, int base);    hashes based  on ith char in string sum( value(i) *k^i )
 *  static std::vector<int> randomPrimeGenerator(int min,int max):   generate random prime numbers
 *  static bool prime(int i) : checks whether a given number is a prime
 *
 *
 *
**
***********************************************/

#ifndef PROJECT5_HASHLIBRARY_H
#define PROJECT5_HASHLIBRARY_H
#define test false


#include <string>
#include <vector>

class HashLibrary {

public:


    /**
     * Hasfunction(std::string plain, int modBase, int base=0);
     * plain : the string to be hashed
     * modbase : the size of the bucket
     * k : the base, only used n polynomial hashfunction
     *
     * returns an int with hash value
     *
    */


    static int lengthHash(std::string plain, int modBase, int base=0);
    static int sumHash(std::string plain, int modBase, int base=0);
    static int sumProdHash(std::string plain, int modBase, int base=0);
    static int polynomialHash(std::string plain, int modBase, int base);

    /*
     *generates random primes from min to max, inclusive on both ends
     */

    static std::vector<int> randomPrimeGenerator(int min, int max);

private:
    /**
     * checks whether the value i is a prime
     */
    static bool prime(int i);
};


#endif //PROJECT5_HASHLIBRARY_H
