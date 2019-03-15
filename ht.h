#ifndef _HT_H_
#define _HT_H_

#include "transaction.h"
#include "bucket.h"

class ht_node
{
private:
    //int size;
    transaction * myTrans;
    int myKey; //me auto sugkrinoume gia to apotelesma tou hash function
    ht_node * next;
    //bucket * bucket; //list of overflowin buckets
public:
    ht_node();
    ~ht_node();
};


//ousiastika sta HT exoume to istoriko twn transactions
class ht
{
private:
    int size; //h1 or h2
    ht_node ** myNodes;
public:
    ht(int sz);
    ~ht();
    int hash_fun(/* sth*/);
    void add_bucket(int where);
    void remove_bucket(int where);
};


#endif