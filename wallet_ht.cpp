#include "wallet_ht.h"


////////////
walletHT::walletHT(int sz) {
    this->size = sz;
    this->table = (wallet*) malloc(sz*sizeof(wallet));
}

walletHT::~walletHT() {
    free(this->table);
    free(this);
}

void walletHT::set_size(int sz) {
    this->size = sz;
    return;
}

int walletHT::get_size() {
    return this->size;
}

wallet * walletHT::get_table() {
    return this->table;
}

void walletHT::set_table(wallet * table1) {
    this->table = table;
    return;
}

int hash_fun(wallet w, walletHT wht) { //hash the key
    int w1 = atoi(w.get_name());
    return (w1 % wht.get_size());
}