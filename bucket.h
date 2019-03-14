#ifndef _BUCKET_H_
#define _BUCKET_H_

#include <stdlib.h>

class myBucket
{
private:
    void * bytes;
    int size;
    myBucket * next;
public:
    myBucket(int size);
    ~myBucket();
};

#endif