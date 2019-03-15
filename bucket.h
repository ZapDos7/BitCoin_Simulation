#ifndef _BUCKET_H_
#define _BUCKET_H_

#include <stdlib.h>
#include "transaction.h"

class bucket_node
{
public:
    transaction * myTrans;
    bucket_node * next;
};
//
class bucket
{
private:
    bucket_node * first_bucket; //list of bucket nodes
    int register_count; //poses eggrafes edw mesa
    void * bytes;
    int size;
public:
    bucket(int sz);
    ~bucket();
    //find registry();
    void add_registry();
    int remove_registry();
    void print_bucket();
};


#endif