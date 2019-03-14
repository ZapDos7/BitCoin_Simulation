#ifndef _TRANS_H_
#define _TRANS_H_

#include <cstring>

class transaction
{
private:
    char * transID; //atoi this
    char * sndr;
    char * rcvr;
    
public:
    transaction(/* args */);
    ~transaction();
    void set_id(char * idd);
    char * get_id();
    void set_sndr(char * sid);
    char * get_sndr();
    void set_rcvr(char * rid);
    char * get_rcvr();
};

#endif