#ifndef _WHT_H_
#define _WHT_H_

#include "wallet.h"

//hash table
class wHT
{
private:
    int size;
    wallet ** table;
public:
    wHT(int sz);
    ~wHT();
    void set_size(int sz);
    int get_size();
    wallet * get_table();
    void set_table(wallet ** table1);
    int hash_fun(wallet w);
    wallet * insert_wallet(wallet w);
    //update wallet function for each transaction
};

#endif