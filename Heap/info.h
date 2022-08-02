#ifndef INFO_H
#define INFO_H
#include <iostream>
#include "cmp.h"


using namespace std;

template <typename T>
struct info{

    T _item;
    int _priority;

    info():_item(),_priority(){}
    info(T i, int p):_item(i),_priority(p){}

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        outs<<" "<<print_me._item<<" | {P_"<<print_me._priority<<"} ";
        return outs;
    }
    friend bool operator < (const info<T>& lhs, const info<T>& rhs){
        return lhs._priority < rhs._priority;
    }
    friend bool operator > (const info<T>& lhs, const info<T>& rhs){
        return lhs._priority > rhs._priority;
    }

};



#endif // INFO_H
