/*****************************************
** File:    HashLibrary.cpp
** Project: CMSC 341 Project 5, Fall 2015
** Author:  Rommel Trejo
** Date:    12/01/15
** Section: 4
** E-mail:  rommel1@umbc.edu
**
**   This file contains the source code for the Hash Library hash functions
 *
    static int lengthHash(std::string plain, int modBase, int base=0);  hashes based on lenght(string)
    static int sumHash(std::string plain, int modBase, int base=0);     hashes based on sum ( value(i))
    static int sumProdHash(std::string plain, int modBase, int base=0);     hashes bases on ith char in string sum ( value(i) * i+1)
    static int polynomialHash(std::string plain, int modBase, int base);    hashes based  on ith char in string sum( value(i) *k^i )
    static std::vector<int> randomPrimeGenerator(int min,int max):   generate random prime numbers
    static bool prime(int i) : checks whether a given number is a prime
 *
 *
 *
**
***********************************************/
#include "HashLibrary.h"
#include <cmath>
#define test false
using namespace std;

/**lengthHash
 * returns the length of the string passed
 */

int HashLibrary::lengthHash(std::string plain, int modBase, int base) {

    int key=(int)plain.length();

    return key%modBase;
}
/*sumHash
 * gets sum of integer values of the keys
 * ascii values (unless thy workstation uses something different)
 */
int HashLibrary::sumHash(std::string plain, int modBase, int base) {
    int key=0;

    for(int i=0;i<plain.length();i++)
    key += (int)plain[i];

    return key%modBase;
}

/**sumProdHash
 * Gets the ascii value of the ith char in the string,
 * multiplies it by i+1, and  adds the result to the key sum
 */
int HashLibrary::sumProdHash(std::string plain, int modBase, int base) {
    int key=0;

    for(int i=0;i<plain.length();i++)
    key += (int)plain[i]*(i+1);
    return key%modBase;
}

int HashLibrary::polynomialHash(std::string plain, int modBase, int base) {
    long key=0;

    for(int i=0;i<plain.length();i++)
    {key += (int)plain[i]*(pow(base,i));
       // std::cout<<(int)plain[i]*(pow(base,i))<<std::endl;
      //  std::cout<<(int)key<<std::endl;
    }


    return (int)(key%modBase);
}


std::vector<int> HashLibrary::randomPrimeGenerator(int min, int max) {
    std::vector<int> numbers;
    int nm=0;
    for (int i=min;i<=max;i++){
        if(prime(i)){
            numbers.push_back(i);
      //  std::cout<<i<<endl;
        nm++;
        }
    }//cout<<nm;
    return numbers;
}

bool HashLibrary::prime(int number) {
    bool isPrime= true;

    //by def a prime is greater than onr
    if(number<2)
        return !isPrime;


    for (int j=2;j<=sqrt(number);j++)
        if(number%j ==0)
            return !isPrime;

    return isPrime;
}
