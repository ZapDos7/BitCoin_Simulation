#include "wallet.h"

////////////wallets
//wallet::wallet(char * nm) {
wallet::wallet(char * nm, int meid, int meval) { //char * nm
    strcpy(this->name, nm);
    //this->myBitCoins
    //this->myBitCoins(meid,meval);
    //this->myBitCoins = (bitcoin) malloc(sizeof(bitcoin));
}

wallet::~wallet() {
    //free(this->myBitCoins);
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

void wallet::init_bclist(int bcid, int val) {
    bitcoin btmp;
    btmp.set_bid(bcid);
    btmp.set_value(val);
    this->bcHead->create(btmp, NULL);
    return;
}

bitcoin_node* wallet::add_bc(int bcid, int val) {
    bitcoin btmp;
    btmp.set_bid(bcid);
    btmp.set_value(val);
    bitcoin_node * a;
    a->prepend(this->bcHead, btmp);
    return a;
}

void wallet::print_bc() {
    bitcoin_node * tmp;
    int count = 0;
    fprintf(stderr, "(HEAD)Bitcoin ID = %d\n", this->bcHead->get_bc_id());
    while(tmp != NULL){
        tmp = this->bcHead->get_next();
        fprintf(stderr, "(BC%d)Bitcoin ID = %d\n",count, tmp->get_bc_id());
        count ++;
        tmp = tmp->get_next();
    }
    return;
}

char * wallet::get_name() {
    return this->name;
}

void wallet::set_balance() {
    //iterate through the bitcoins and sum their shit?
    //or update the balance for each transaction
    return;
}

int wallet::get_balance() {
    return this->myBalance;
}

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

int hash_fun(wallet w, walletHT wht) { //only returns where the wallet goes
    int w1 = atoi(w.get_name());
    return (w1 % wht.get_size());
}