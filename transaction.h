#ifndef _TRANS_H_
#define _TRANS_H_

#include <cstring>
#include "datetime.h"

class transaction
{
private:
    char * transID; //atoi this
    char sndr[51];
    char rcvr[51];
    //datetime *myDT;
public:
    transaction();
    ~transaction();
    void set_id(char * idd);
    char * get_id(); //unique!!!
    void set_sndr(char * sid);
    char * get_sndr();
    void set_rcvr(char * rid);
    char * get_rcvr();
};
//store the largest existing transID (atoi'd) and add +1 for each new transaction
#endif