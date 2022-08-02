#ifndef MAP_H
#define MAP_H
#include "../_includes/BTree/btree.h"
#include <iostream>
using namespace std;

template <typename K, typename V>
struct Pair{
    K key;
    V value;
    Pair(const K& k=K(), const V& v=V()):key(k),value(v){}
    Pair(const Pair<K,V>& other){
        key = other.key;
        value = other.value;
    }
    Pair<K,V>& operator =(const Pair<K,V>& rhs){
        if(this == &rhs){return *this;}
        key = rhs.key;
        value = rhs.value;
        return *this;
    }
    friend ostream& operator <<(       ostream& outs, const Pair<K,V>&  me){
//        cout<<"Calling Ostream"<<endl;
        outs<<me.key<<":"<<me.value;
        return outs;
    }
    friend bool     operator ==(const Pair<K,V>& lhs, const Pair<K,V>& rhs){
//        cout<<"Calling "<<lhs<<" == "<<rhs<<endl;
        return lhs.key==rhs.key ? true:false;
    }
    friend bool     operator < (const Pair<K,V>& lhs, const Pair<K,V>& rhs){
//        cout<<"Calling <"<<endl;
        return lhs.key<rhs.key ?  true:false;
    }
    friend bool     operator > (const Pair<K,V>& lhs, const Pair<K,V>& rhs){
//        cout<<"Calling >"<<endl;
        return lhs.key>rhs.key ?  true:false;
    }
    friend bool     operator <=(const Pair<K,V>& lhs, const Pair<K,V>& rhs){
//        cout<<"Calling <="<<endl;
        return lhs.key<=rhs.key ? true:false;
    }
    friend bool     operator >=(const Pair<K,V>& lhs, const Pair<K,V>& rhs){
//        cout<<"Calling >="<<endl;
        return lhs.key>=rhs.key ? true:false;
    }
    friend Pair<K,V>operator + (const Pair<K,V>& lhs, const Pair<K,V>& rhs){
//        cout<<"Calling +"<<endl;
        if(lhs.key==rhs.key){
            return Pair(lhs.key, lhs.value+rhs.value);
        }
        return lhs;
    }
    friend Pair<K,V>operator +=(const Pair<K,V>& lhs, const Pair<K,V>& rhs){
//        cout<<"Calling +="<<endl;
        return lhs+rhs;
    }
    friend istream& operator >>(        istream& ins,       Pair<K,V>& rhs){
//        cout<<"Calling >>"<<endl;
        char temp;
        K key;
        V val;
//        cout<<"Key: ";
        ins>>key;

        ins>>temp;
//        cout<<"Val: ";
        ins>>val;
        rhs.key=key;
        rhs.value=val;
        return ins;
    }
};

template <typename K, typename V>
class Map
{
public:
    typedef BTree<Pair<K, V> > map_base;    
    typedef Pair<K,V> P;
    Map():map(), key_count(){}

//  Capacity DONE
    int size() const{return key_count;}
    bool empty() const{return key_count==0;}

//  Element Access
    V& operator[](const K& key){
        /*
         * returns a reference to the vector
         * associated witht the key
         *
         * in the const version of the operator
         * the underlying const get function will assert
         * that the key is in the tree
         *
         * in the nonconst version
         * the underlying get function will add a new
         * node with the key and an empty vector
         *
         * NOTE: accessing the non-existent element of an empty
         * array crashes the program, so if you need to print or
         * access values of a key, make sure the key exists first
         *
        */
        return map.get(key).value;
    }
    V& at(const K& key){

    }
    const V& at(const K& key) const{

    }

//  Modifiers
    void insert(const K& k, const V& v){
        map.insert(P(k,v));
        key_count++;
    }
    void erase(const K& key){map.remove(P(key));}
    void clear(){map.clear_tree();}
    V get(const K& key){
        return map.get(P(key));
    }

//  Operations:
    bool contains(const Pair<K, V>& target) const{return map.contains(target);}
    bool is_valid(){return map.is_valid();}
    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        outs<<print_me.map<<endl;
        return outs;
    }

private:
    int key_count;
    BTree<Pair<K, V> > map;
};






















#endif // MAP_H
