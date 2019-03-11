#include "wallet.h"

wallet::wallet(char * nm) {
    strcpy(this->name, nm);
    this->myBitCoins = (bitcoin*) malloc(sizeof(bitcoin));
}

wallet::~wallet() {
    free(this->myBitCoins);
    free(this->name);
    free(this);
}

void wallet::set_id(char* id) {
    strcpy(this->name, id);
    return;
}

void wallet::print_id() {
    printf("My id is %s\n", this->name);
    return;
}

char * wallet::get_name() {
    return this->name;
}

////////////
walletHT::walletHT(int sz) {
    this->size = sz;
    this->table = (wallet**) malloc(sz*sizeof(wallet));
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

wallet ** walletHT::get_table() {
    return this->table;
}

int hash_fun(wallet w, walletHT wht) { //only returns where the wallet goes
    int w1 = atoi(w.get_name());
    return (w1 % wht.get_size());
}