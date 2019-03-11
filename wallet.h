#ifndef __WELEMS_H__
#define __WELEMS_H__

#include <cstring>
#include <stdio.h>
#include <cstdlib>

#include "bc.h"

//wallets
class wallet
{
private:
    char name[51]; //50 + '\0'
    bitcoin * myBitCoins;
public:
    wallet(char * nm);
    ~wallet();
    void set_id(char*id);
    void print_id();
    char * get_name();
};

//walletHT
class walletHT
{
private:
    int size;
    wallet ** table;
public:
    walletHT(int sz);
    ~walletHT();
    void set_size(int sz);
    int get_size();
    wallet ** get_table();
};


#endif