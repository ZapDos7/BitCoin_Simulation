#include "bucket.h"

bucket::bucket(int sz) {
    this->bytes = malloc(sz);
    this->first_bucket = NULL;
    this->register_count = 0;
    this->size = sz;
}
bucket::~bucket() {}
void bucket::add_registry() { 
    this->register_count++;
}
int bucket::remove_registry() { 
    this->register_count--;
}
void bucket::print_bucket() {
    fprintf(stdout, "There are %d registries in this bucket.\n", this->register_count);
    //print the actual insides
}