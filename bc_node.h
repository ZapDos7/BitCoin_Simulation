#ifndef _BC_N_
#define _BC_N_

#include <cstdlib> //exit

#include "bc.h"

class bitcoin_node
{
private:
    bitcoin me;
    bitcoin_node * next;
public:
    //bitcoin_node(int meid, int meval);
    //~bitcoin_node();
    bitcoin_node * create(bitcoin bme, bitcoin_node* bnext);
    bitcoin_node * prepend(bitcoin_node * head, bitcoin data); //head -> new_node
    //bool is_empty();
    //bitcoin_node& operator=(const bitcoin_node& b);
    //int search(bitcoin_node head, int bid);
};

#endif