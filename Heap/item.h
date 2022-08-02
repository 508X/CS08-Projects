#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "cmp.h"
#include "info.h"

using namespace std;

template <typename T>
struct item
{
    int _serial;
    T _item;

    item(): _serial(0), _item(T()){}
    item(T item, int serial): _item(item), _serial(serial){}

    friend ostream& operator <<(ostream& outs, const item<T>& print_me){
        outs<<""<<print_me._item<<", (S_" << print_me._serial<<") ";
        return outs;
    }

    friend bool operator <(const item<T>& lhs, const item<T>& rhs){
        if(lhs._item < rhs._item){return true;}
        else if(lhs._item > rhs._item){return false;}
        if(lhs._serial < rhs._serial){return true;}

        return false;
    }
    friend bool operator >(const item<T>& lhs, const item<T>& rhs){
        if(lhs._item > rhs._item){return true;}
        else if(lhs._item < rhs._item){return false;}
        if (lhs._serial < rhs._serial){return true;}

        return false;
    }
    friend bool operator <=(const item<T>& lhs, const item<T>& rhs){
        if (lhs._item > rhs._item){return false;}
        if (lhs._item == rhs._item &&
            lhs._serial < rhs._serial){
            return false;
        }

        return true;
    }
    friend bool operator >=(const item<T>& lhs, const item<T>& rhs){
        if (lhs._item < rhs._item){return false;}
        if (lhs._item == rhs._item &&
            lhs._serial > rhs._serial){
            return false;
        }

        return true;
    }
    friend bool operator ==(const item<T>& lhs, const item<T>& rhs){
        if (lhs._item == rhs._item &&
            lhs._serial == rhs._serial){
            return true;
        }

        return false;
    }
    friend bool operator !=(const item<T>& lhs, const item<T>& rhs){
        if (lhs._item == rhs._item &&
            lhs._serial == rhs._serial){
            return false;
        }

        return true;
    }
};


#endif // ITEM_H
