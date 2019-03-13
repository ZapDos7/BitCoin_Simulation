#include "ht.h"


ht_node::ht_node() {}

ht_node::~ht_node() {}


int ht_node::hash_fun(wallet w, int size) { //hash the key
    int w1 = atoi(w.get_name());
    return (w1 % size);
}