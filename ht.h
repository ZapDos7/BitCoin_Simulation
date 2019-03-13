#ifndef _HT_H_
#define _HT_H_

#include "wallet.h"

class ht_node
{
private:
    wallet myData;

public:
    ht_node();
    ~ht_node();
    int hash_fun(wallet w, int size);
};

#endif