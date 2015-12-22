/*****************************************
** File:    HashTable.H
** Project: CMSC 341 Project 5, Fall 2015
** Author:  Rommel Trejo
** Date:   November 28, 2015, 1:49 PM
** Section: 4
** E-mail:  rommel1@umbc.edu
**
**   This file contains the code definitions for the Hash Table hash functions
 *
 * struct LinkedList: a node  that acts as a linked list.
 * HashTable(int bucketSize, int (*myHashFunction)(std::string, int, int), int k1=1): creates a hashtable with
 *      bucket size, hashfunction, and possibly a "k" base.
 * void insert(std::string)     inserts a string into hashtable
 * int getNumberofCollisions()  returns the number of collisions
 *
 *
 *
**
***********************************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <list>
#define test false

#ifndef HASHTABLE_LinkedList_H
#define HASHTABLE_LinkedList_H

/*This is more like a node * but what I need it to do
std:list was not sufficient
too needy :(
 */

struct LinkedList
{
public:
    LinkedList(std::string theData, LinkedList *theBack=NULL, LinkedList *theNext=NULL);

    std::string data ;
    LinkedList *previous;
    LinkedList *next;

};
#endif

class HashTable{

private:

    int collisions;
    int size;
    std::vector<LinkedList*> buckets; //I finally learned vectors I feel like I deserve a price. such coding , much computer science,
                                                                                // very programming
    int (*hashFunction)(std::string,int modBase,int base) ;
    int k;  //the base used on polinomial function.

public:


    /** Constructor
     * receives bucketSize = size of bucket array
    * hashfunction = function used to hash
    * k used on polynomial hash function as power base
    */
    HashTable(int bucketSize, int (*myHashFunction)(std::string, int, int), int k1=1);

    /** inserts a string into the hastable
     * hashes string
     * then inserts into righ bucket
     *
     */
    void insert(std::string);

    /**
     *returns the number of collisions
     */
    int getNumberofCollisions(){
        return collisions;
    }




};





#endif /* HASHTABLE_H */

