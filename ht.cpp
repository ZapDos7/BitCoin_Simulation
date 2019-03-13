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

wallet * walletHT::insert_wallet() {

}

int walletHT::hash_fun(wallet w) { //hash the key
    int w1 = atoi(w.get_name());
    return (w1 % this->get_size());
}