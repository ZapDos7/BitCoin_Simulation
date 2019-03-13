#ifndef _TRANS_H_
#define _TRANS_H_

class transaction
{
private:
    int transID;
    char * sndr;
    char * rcvr;
    
public:
    transaction(/* args */);
    ~transaction();
};

transaction::transaction(/* args */)
{
}

transaction::~transaction()
{
}



#endif