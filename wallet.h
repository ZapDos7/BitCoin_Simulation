#ifndef __WELEMS_H__
#define __WELEMS_H__

#include <cstring>
#include <stdio.h>
#include <cstdlib>

#include "bc_node.h"
//wallets
class wallet
{
private:
    char name[51]; //50 + '\0'
    bitcoin_node * bcHead;
    int myBalance;
public:
    //wallet(char * nm);
    wallet(char * nm, int meid, int meval);
    ~wallet();
    void set_id(char*id);
    void print_id();
    void init_bclist(int bcid, int val);
    bitcoin_node* add_bc(int bcid, int val);
    void print_bc();
    char * get_name();
    void set_balance();
    int get_balance();
};

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
};


#endif