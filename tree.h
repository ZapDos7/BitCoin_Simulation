#ifndef _TREE_H_
#define _TREE_H_

#include <cstring>
#include "bc.h"

class root
{
private:
    char initial_owner_name[51];
    int initial_bc_value;
    int bc_id;
public:
    root();
    ~root();
    void set_ioname(char * nm);
    void set_init_val(int v);
    int get_init_val();
    char * get_ioname();
    int get_id();
};

class tree_node
{
private:
    char name[51]; //node name (rcvr or sender, doesnt matter here)
    int value; //node value, e.g. $50
    //pointer to HT
    //flag an eimai send or rcv (or check if i am left or right?)
public:
    tree_node();
    ~tree_node();
    void set_name(char * nm);
    void set_val(int v);
    int get_val();
    char * get_name();
};


//tree
class tree
{
private:
    root*  myRoot;
    tree_node * left_child; //dynamic add new nodes whenever a new transaction occurs
    tree_node * right_child; //left = rcvr (what I gave), right = father (ta resta mou)
public:
    tree();
    ~tree();
    void add_node();//based on transaction - ELEGXOS
    //elegxos tou tree: prepei ola ta fulla na exoun sum = initial value;
};

#endif