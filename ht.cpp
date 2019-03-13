#include "ht.h"

////////////
HT::HT(int sz) {
    this->size = sz;
    this->table = (wallet**) malloc(sz*sizeof(wallet));
    for(int i = 0; i < sz; i++) {
        this->table[i]->set_id(NULL);
        this->table[i]->set_balance(/*0*/);
        this->table[i]->init_bclist(0,0);//id, value
    }
}

HT::~HT() {
    free(this->table);
    free(this);
}

void HT::set_size(int sz) {
    this->size = sz;
    return;
}

int HT::get_size() {
    return this->size;
}

wallet * HT::get_table() {
    return *(this->table);
}

void HT::set_table(wallet ** table1) {
    this->table = table;
    return;
}


int HT::hash_fun(wallet w) { //hash the key
    int w1 = atoi(w.get_name());
    return (w1 % this->get_size());
}

wallet * HT::insert_wallet(wallet w) { //w has key and value
    int h = this->hash_fun(w);
    int i = 0;
    while((this->table[h]->get_name() != NULL) && (i < this->get_size())) { //check full ht
        if (this->table[h]->get_name() == w.get_name()) {
            this->table[h] = &w;
            return this->table[h];
        }
        h = (h+1) % this->get_size();
        i++; //avdance loop index
    }
    if (this->table[h]->get_name() == NULL) { //direct assignment
        this->table[h] = &w;
    }
    return this->table[h];
}