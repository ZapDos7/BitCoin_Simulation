#include "tree.h"

//root
root::root() {}
root::~root() {}
void root::set_ioname(char * nm) {
    strcpy(this->initial_owner_name, nm);
    return;
}
void root::set_init_val(int v) {
    this->initial_bc_value = v;
    return;
}
int root::get_init_val() {
    return this->initial_bc_value;
}
char * root::get_ioname() {
    return this->initial_owner_name;
}
int root::get_id() {
    return this->bc_id;
}

//tree node
tree_node::tree_node() {}
tree_node::~tree_node() {}
void tree_node::set_name(char * nm) {}
void tree_node::set_val(int v) {}
int tree_node::get_val() {}
char * tree_node::get_name() {}


//tree
tree::tree() {}
tree::~tree() {}
void tree::add_node() {
    //check upoloipo (apo walletHT)
    //new node me ID = send or rcvr an einai left i rogith
}
void tree::print_dfs() {
    
}
