#ifndef _TREE_H_
#define _TREE_H_

#include "bc.h"

class root
{
private:
    char initial_owner_name[51];
    int initial_bc_value;
public:
    root();
    ~root();
    void set_ioname(char * nm);
    void set_init_val(int v);
    int get_init_val();
    char * get_ioname();
};

class tree_node
{
private:
    char name[51];
    int value;
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
    root myRoot;
    tree_node * body; //dynamic add new nodes whenever a new transaction occurs
public:
    tree(/* args */);
    ~tree();
    void add_node();//based on transaction - ELEGXOS
};

#endif