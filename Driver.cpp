/*****************************************
** File:    Driver.cpp
** Project: CMSC 341 Project 5, Fall 2015
** Author:  Rommel Trejo
** Date:    12/01/15
** Section: 4
** E-mail:  rommel1@umbc.edu
**
**   This file contains the main driver program for Project 5.
** This program reads the file specified as the first command line
** counts the numbers of words in input file. then test to see what the best option
**on Hastable is
 *
 * stdError() : prints an error when input was wrong
 * createWordsList(std::vector<string> &words, char *filename): adds words in filename to words
 * recomend(std::vector<string> wordsList, std::vector<int> buckets); recommends the best bucket size
 * main(): main function : initializes and calls all data
 *
 *
**
***********************************************/
#include <iostream>
#include "HashTable.h"
#include "HashLibrary.h"
#include <unistd.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#define test false
using namespace std;
/**
 * value 0 size min
 * value 1 size max
 * value 2 base min
 * value 3 base max
 */
int values[4]{0,0,0,0};


/**
 * error output is wrong
 */
void stdError();

/**
 * addd all words in filename to words vector
 */
void createWordsList(vector<string> &words, char *filename);

/**
 * recomends the hash function to use
 */

void recomend(std::vector<string> wordsList, std::vector<int> buckets);

/*
 * checks if input fits the requirements and sets up wordlist
 * and sets values[]
 * if any inconsistency calls stdError
 * and exits
 */

bool isFitsrequirements(int argc, char **arguments, vector<string> &wordList) {

    // check if right number of arguments
    //4 no base and 6 with offered base

#if test
    argc =4;
    arguments[1]="/home/enum/ClionProjects/project5/input.txt";
    arguments[2]="1";
    arguments[3]="38";
    arguments[4]="1";
    arguments[5]="4";

#endif


    if (argc != 4 && argc != 6){
        stdError();
        return false;
    }

    //check if parameters are good

    //check if string is good

    if ( ( access( arguments[1], F_OK ) != -1 ))
        createWordsList(wordList, arguments[1]);
    else
    { cout<<"Read file <"<<arguments[1]<<"> failed!!! Terminating.";
        return 1;}
    //end string check


    ////////////////////////beging check numbers

    int minSize, maxSize;
    stringstream(arguments[2]) >> minSize;
    values[0]=1;
    stringstream(arguments[3]) >> maxSize;
    values[1]=maxSize;


    if(minSize >= maxSize)
    {stdError();
        return 1;}
    if( (minSize < 1 && arguments[2] != 0) )
    {stdError();
        return 1;}

    //check bases
    if(argc==6){

        int minBase, maxBase;
        stringstream(arguments[4]) >> minBase;
        values[2]=minBase;
        stringstream(arguments[5]) >> maxBase;
        values[3]=maxBase;


        if(minBase >= maxBase)
        { stdError();
            return 1;}
        if( (minBase < 1 && arguments[2] != 0) )
        {stdError();
        return 1;}


    }


    return true;
}
/**
 * adds all the words to the list
 */
void createWordsList(vector<string> &words, char *filename) {
    string currentWord;
    ifstream myfile(filename);
    if (myfile.is_open()) { while(!myfile.eof()){
            getline(myfile,currentWord,' ');

            currentWord.erase(std::remove(currentWord.begin(), currentWord.end(), ' '), currentWord.end());
            currentWord.erase(std::remove(currentWord.begin(), currentWord.end(), '\n'), currentWord.end());
            currentWord.erase(std::remove(currentWord.begin(), currentWord.end(), '\t'), currentWord.end());

            if (!(currentWord =="\t"))
            if (!(currentWord ==""))
            if (!(currentWord ==" "))
            if (!(currentWord =="\n"))


            {
                words.push_back(currentWord);}
        }}
    myfile.close();
}

/**
 *  prints out the error
 */
void stdError() {
    cout << "Usage: make run INPUT=<filename> MIN_SIZE=<positive integer>\n"
            "MAX_SIZE=<positive integer larger than MIN_SIZE> [MIN_BASE=<positive\n"
            "integer> MAX_BASE=<positive integer larger than MIN_BASE>]";
}



int main(int argc, char* argv[]) {

    vector<string> wordList;
    vector <int> buckets;

    if(!isFitsrequirements(argc, argv, wordList))
    { return 1;}


    //post check
    buckets= HashLibrary::randomPrimeGenerator(values[0], values[1]);

    if(buckets.size()<1)
    {stdError();
        return 1;}


    cout<<"Bucket sizes: ";
    for(int i=0; i<buckets.size();i++)
    {cout<<buckets[i];
        if( (i+1) < buckets.size())
            cout<<", ";

    }cout<<endl;

    cout<<"loaded "<<wordList.size()<<" words from data.";
    recomend(wordList, buckets);


    return 0;
}

void recomend(std::vector<string> wordsList, std::vector<int> buckets) {
    int best_bucket_size = 214748322;
    int best_collision=214748322;
    int best_k_size = 214748322;
    bool special=false;
    if(values[3]!=0) {
        special = true;



        //HashTable(int bucketSize, int (*myHashFunction)(std::string, int, int), int k1=1);

//outer looop j values

        for(int j =0;j<buckets.size();j++){
            //inner loop k values;

            for (int k = values[2]; k <= values[3]; k++) {
                HashTable table0(buckets[j], HashLibrary::polynomialHash, k);

                //   cout <<table0.getNumberofCollisions()<< endl;
                for(int l=0; l < wordsList.size(); l++)
                {
                    table0.insert(wordsList[l]);


                }
                if(table0.getNumberofCollisions()<best_collision)
                {best_bucket_size=buckets[j];
                    best_collision=table0.getNumberofCollisions();
                    best_k_size=k;}
#if test
                cout <<"size: " <<buckets[j]<<". Base : "<<k<<". Collisions: "<<table0.getNumberofCollisions()<<endl;
#endif
            }
        }

        cout <<endl<<"Recommend polynomial-based hash function with size: " <<best_bucket_size<<
        ". Base : "<<best_k_size<<". Collisions: "<<best_collision<<endl;

    }










    else{
        for(int j =0 ;j < buckets.size();j++){
            //inner loop k values;

            for (int k = 0; k <= 3; k++) {
                //decide fucntion
                //decide fucntion
                int (*myHashFunction)(std::string, int, int);



                switch (k){
                    case 0:          myHashFunction=&HashLibrary::lengthHash;
                        break;
                    case 1:         myHashFunction=&HashLibrary::sumHash;

                        break;
                    case 2:         myHashFunction=&HashLibrary::sumProdHash;
                        break;
                }

                HashTable table0= HashTable(buckets[j], myHashFunction);

                myHashFunction==NULL;

                //   cout <<table0.getNumberofCollisions()<< endl;
                for(int l=0; l < wordsList.size(); l++)
                {
                    table0.insert(wordsList[l]);


                }

                //comparison to see if smallest of all
                if(table0.getNumberofCollisions()<best_collision){

                       best_bucket_size=buckets[j];
                        cout<<"new bucket: "<<best_bucket_size<<endl;
                        best_collision=table0.getNumberofCollisions();
                        cout<<"new col: "<<best_collision<<endl;
                        best_k_size=k;
                        cout<<"new k: "<<best_k_size<<endl;
                        //     cout<<k;

                }
#if test
                cout <<"size: " <<buckets[j]<<". fucntion : ";

                    if(k==0)
                    cout<<"length";

                    if(k==1)
                        cout<<"sum";

                    if (k==2)
                        cout<<"sum product";

                cout<<". Collisions: "<<table0.getNumberofCollisions()<<endl;
#endif
            }
        }


        cout <<endl<<"Recommend ";

        if(best_k_size==0)
            cout<<"length";

        if(best_k_size==1)
            cout<<"sum";

        if (best_k_size==2)
            cout<<"sum product";

        cout<<" hash function with size: " <<best_bucket_size<<  ". Collisions: "<<best_collision<<endl;

    }


}



