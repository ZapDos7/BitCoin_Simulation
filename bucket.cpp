#include "bucket.h"

myBucket::myBucket(int size) {
    bytes = malloc(size);
}

myBucket::~myBucket() {}

