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
