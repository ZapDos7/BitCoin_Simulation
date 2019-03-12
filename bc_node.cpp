#include "bc_node.h"

bitcoin_node::bitcoin_node(/*int meid, int meval*/) {
    //this->me(meval);
    //this->me.set_bid(meid);
    //this->me.set_value(meval);
    //this->next = NULL;
}

bitcoin_node::~bitcoin_node() {}
/*
bool bitcoin_node::is_empty() {
    if (this->next != NULL) {
        return true;
    }
    else {
        return false;
    }
}*/

bitcoin_node * bitcoin_node::create(bitcoin bme, bitcoin_node* bnext) {
    bitcoin_node * new_node = (bitcoin_node*)malloc(sizeof(bitcoin_node));
    if (new_node == NULL) {
        fprintf(stderr, "Can't create bitcoin node.\n");
        exit(1);
    }
    new_node->me = bme;
    new_node->next = bnext;
    return new_node;
}

bitcoin_node * bitcoin_node::prepend(bitcoin_node * head, bitcoin data) {
    bitcoin_node * new_node = bitcoin_node::create(data, head);
    head = new_node;
    return head;
}

int bitcoin_node::get_bc_id() {
    return this->me.get_bid();
}

/*int bitcoin_node::get_bc_val() {
    return this->me.get_value();
}*/

bitcoin_node * bitcoin_node::get_next() {
    return this->next;
}

/*bitcoin_node& bitcoin_node::operator=(const bitcoin_node& b) {
    me = b.me;
    next = b.next;
}*/

/*bitcoin_node& bitcoin_node::operator*(const bitcoin_node& b) {
    me = b.me;
    next = b.next;
}*/

/*int bitcoin_node::search(bitcoin_node head, int bid) {
    if (head.is_empty() == true) {
        fprintf(stderr, "Empty bitcoin list\n");
        exit(1);
    }
    bitcoin_node temp = head;
    while (temp.is_empty() == false) {
        if (temp.me.get_bid() == bid) {
            printf("Found\n");
            //return this node?
            break;
        }
        temp = temp.next;
    }
    return 0;
}*/