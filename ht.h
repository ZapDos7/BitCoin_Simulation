#ifndef _HT_H_
#define _HT_H_

class ht_node
{
private:
    int size;
    int aa; //aukson airthmos xD - me auto sugkrinoume gia to apotelesma tou hash function

public:
    ht_node(/* args */);
    ~ht_node();
};


//ousiastika sta HT exoume to istoriko twn transactions
class ht
{
private:
    int size; //h1 or h2
    ht_node * myNodes;
public:
    ht(/* args */);
    ~ht();
    int hash_fun(/* sth*/);
};


#endif