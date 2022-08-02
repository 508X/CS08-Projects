#ifndef MMAP_H
#define MMAP_H
#include "../../_includes/BTree/btree.h"
#include "../_includes/new_vect/vector.h"
#include <iostream>
using namespace std;


template <typename K, typename V>
struct MPair{
    K key;
    Vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
    //--------------------------------------------------------------------------------
    MPair(const K& k=K()):key(k){}
    MPair(const K& k, const V& v):key(k), value_list(){
        value_list.push_back(v);
    }
    MPair(const K& k, const vector<V>& vlist):key(k), value_list(vlist){}
    MPair& operator =(const MPair<K, V>& rhs){
        if(this==&rhs){return *this;}
        value_list = rhs.value_list;
        key = rhs.key;
    }
    //--------------------------------------------------------------------------------

    //You'll need to overlod << for your vector:
    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me){
        outs<<print_me.key;
        for(int i=0; i<print_me.value_list.size(); i++){cout<<" "<<print_me.value_list[i]<<" ";}
        return outs;
    }
    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key==rhs.key ? true:false;
    }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key<rhs.key ? true:false;
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key<=rhs.key ? true:false;
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key>rhs.key ? true:false;
    }
    friend MPair<K, V> operator + (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        if(lhs==rhs){
            MPair<K, V> Ret;
            Ret.value_list = lhs.value_list + rhs.value_list;
            Ret.key = lhs.key;
            return Ret;
        }
        else{
            assert("Different Keys"=="");
        }
    }
    friend MPair<K, V> operator +=(const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs+rhs;
    }
    friend bool operator <(const string& lhs, const string&rhs){
        for(int i=0; i<lhs.size(); i++){

        }
    }
    friend bool operator >(const string& lhs, const string&rhs){

    }
};




template <typename K, typename V>
class MMap
{
public:
    typedef BTree<MPair<K, V> > map_base;
    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it);
        Iterator operator ++(int unused);
        Iterator operator ++();
        MPair<K, V> operator *();
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs);
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs);

    private:
        typename map_base::Iterator _it;
    };

    MMap():mmap(){

    }

//  Iterators
    Iterator begin();
    Iterator end();

//  Capacity
    int size() const{return mmap.size();}
    bool empty() const{return mmap.empty();}

//  Element Access
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
    const vector<V>& operator[](const K& key) const{

        return mmap.get(key).value_list;
    }
    vector<V>& operator[](const K& key){

        return mmap.get(key).value_list;
    }

//  Modifiers
    void insert(const K& k, const V& v){mmap.insert(MPair<K,V>(k,v));}
    void erase(const K& key){mmap.remove(MPair<K,V>(key));}
    void clear(){mmap.clear_tree();}

//  Operations:
    bool contains(const K& key) const{return mmap.contains(key);}
    vector<V> &get(const K& key){

    }

    Iterator find(const K& key);
    int count(const K& key);

    // I have not written these yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:
    bool is_valid(){return mmap.is_valid();}
    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        outs<<print_me.mmap<<endl;
        return outs;
    }

private:
    BTree<MPair<K, V> > mmap;
};




#endif // MMAP_H
