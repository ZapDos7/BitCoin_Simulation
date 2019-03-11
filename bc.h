#ifndef _BC_H_
#define _BC_H_

class bitcoin
{
private:
    int bitcoin_ID; //anagnwristiko
    int value;      //timi arxiki olwn twn bitcoin
    //deiktis sto tree tou?
public:
    bitcoin(int v);
    ~bitcoin();
    void set_value(int v);
    int get_value();
    void set_bid(int id);
    int get_bid();
};


#endif