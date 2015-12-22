
#include"HashTable.h"
#include "HashLibrary.h"


using namespace std;





HashTable::HashTable(int bucketSize, int (*myHashFunction)(std::string, int, int), int k1)
        : collisions(0),size(bucketSize),buckets(size), hashFunction(myHashFunction),k(k1) {}


void HashTable::insert(std::string plainText) {
    int hashNumber=hashFunction(plainText,size,1);

    //check if empty
    if(buckets[hashNumber]==NULL)
    {
        buckets[hashNumber]= new LinkedList(plainText);
    }else{
            //increase collision number
                collisions++;
        //find space and add
            LinkedList *t = buckets[hashNumber];
            while(t->next != NULL){
                t=t->next;
            }
            t->next=new LinkedList(plainText);
            t->next->previous=t;


    }




}



//linked list constructor

LinkedList::LinkedList(std::string theData, LinkedList *theBack , LinkedList *theNext)
        : data(theData), previous(theBack),next(theNext){}


