#ifndef _WHT_H_
#define _WHT_H_

#include "wallet.h"

//walletHT
class walletHT
{
private:
    int size;
    wallet * table;
public:
    walletHT(int sz);
    ~walletHT();
    void set_size(int sz);
    int get_size();
    wallet * get_table();
    void set_table(wallet * table1);
};

#endif