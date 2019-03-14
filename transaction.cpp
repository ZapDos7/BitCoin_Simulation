#include "transaction.h"


transaction::transaction() {}

transaction::~transaction() {}

void transaction::set_id(char * idd) {
    strcpy(this->transID, idd);
    return;
}

char * transaction::get_id() {
    return this->transID;
}

void transaction::set_sndr(char * sid) {
    strcpy(this->sndr, sid);
    return;
}

char * transaction::get_sndr() {
    return this->sndr;
}

void transaction::set_rcvr(char * rid) {
    strcpy(this->rcvr, rid);
    return;
}

char * transaction::get_rcvr() {
    return this->rcvr;
}