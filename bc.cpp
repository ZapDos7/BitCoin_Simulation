#include "bc.h"

//bitcoin::bitcoin(int v) {
bitcoin::bitcoin() {
    this->value = 0;
    return;
}

bitcoin::~bitcoin(){}

void bitcoin::set_value(int v) {
    this->value = v;
    return;
}

int bitcoin::get_value() {
    return this->value;
}

void bitcoin::set_bid(int id) {
    this->bitcoin_ID = id;
    return;
}

int bitcoin::get_bid() {
    return this->bitcoin_ID;
}