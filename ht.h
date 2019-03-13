#ifndef _T_H_
#define _T_H_

#include "wallet.h"

//hash table
class HT
{
private:
    int size;
    wallet ** table;
public:
    HT(int sz);
    ~HT();
    void set_size(int sz);
    int get_size();
    wallet * get_table();
    void set_table(wallet ** table1);
    int hash_fun(wallet w);
    wallet * insert_wallet(wallet w);
    //update wallet function for each transaction
};

#endif