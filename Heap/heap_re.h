#ifndef HEAP_RE_H
#define HEAP_RE_H
#include <iostream>
#include <iomanip>
#include "../../_includes/Vector3/my_vector.h"
#include "cmp.h"
#include "item.h"

using namespace std;

template <typename T, typename C = Bigger<item<T> > >
class heap
{
public:

    heap();

    void insert(const T& insert_me);
    T pop();

    bool    is_empty() const;
    unsigned int         size() const;
    unsigned int     capacity() const;

    friend ostream& operator << (ostream& outs, const heap<T,C>& print_me){
        print_me.print_tree(outs);
        return outs;
    }
    bool is_valid   (int i) const;


private:

    void print_tree(ostream& outs = cout) const;
    void print_tree(unsigned int root, int level = 0, ostream& outs = cout) const;

    bool is_leaf    (int i) const;
    bool ibl        (int i) const;
    bool ibr        (int i) const;

    int parent_index(int i)     const;
    int left_child_index(int i) const;
    int right_child_index(int i)const;
    int N_child_index(int i)    const;

    void swap_with_parent(int i);

    int _count;
    C _compare;

    my_vector<item<T> > _v;

};

template<typename T, typename C>
heap<T,C>::heap()
    :_v(), _count(0)
{

}

template<typename T, typename C>
void heap<T,C>::insert(const T& insert_me){

    /* inserts an item<info<T>> into
     * a vector of <item> */
    _v.push(item<T>(insert_me, _count));
    _count++;

    /* child gets swapped with parent,
     * index-> set to parent */
    for(int i = size() -1;

        i > 0 &&
        _compare(_v[i], _v[parent_index(i)]);

        swap_with_parent(i), i = parent_index(i))
    {}

}

template<typename T, typename C>
T heap<T,C>::pop(){

    assert(size()>0);

    item<T> _item = _v[0];
    T temp = _item._item;
    item<T> _item2 = _v.pop();

    if(size()>0){
        _v[0] = _item2;
    }

    for(int i = 0; i < size() && !is_leaf(i); i = N_child_index(i), swap_with_parent(i)){}

    return temp;
}

template<typename T, typename C>
bool    heap<T,C>::is_empty() const{
    return _v.is_empty();
}

template<typename T, typename C>
unsigned int     heap<T,C>::size() const{
    return _v.vector_size();
}

template<typename T, typename C>
unsigned int     heap<T,C>::capacity() const{
    return _v.vector_cap();
}









template<typename T, typename C>
void heap<T,C>::print_tree(ostream& outs) const{

    print_tree(0,0,outs);

}

template<typename T, typename C>
void heap<T,C>::print_tree(unsigned int root, int level, ostream& outs) const{

    if(root<_v.vector_size()){

        if(ibr(root)){
            print_tree(right_child_index(root), level+1, outs);
        }

        outs<<"L("<<level<<") "<<setw(4*level)<<""<<"["<<_v[root]<<"]"<<endl<<endl;

        if(ibl(root))
        {
            print_tree(left_child_index(root), level+1, outs);

        }
    }



}



template<typename T, typename C>
bool heap<T,C>::is_valid   (int i) const{

    if(!is_leaf(i)){

        if(_compare(_v[N_child_index(i)], _v[i])){
            return false;
        }
        /* if left index is valid, and !is_valid() */
        if(ibl(i) && !is_valid(left_child_index(i))){
            return false;
        }
        /* if right index is valid, and !is_valid() */
        if(ibr(i) && !is_valid(right_child_index(i))){
            return false;
        }


    }
    return true;

}

template<typename T, typename C>
bool heap<T,C>::is_leaf    (int i) const{
    if(2*i+1 >= _v.vector_size()){
        return true;
    }
    else{
        return false;
    }
}

template<typename T, typename C>
bool heap<T,C>::ibl        (int i) const{
    return (2*i+1<_v.vector_size() && i>=0) ? true : false;
}

template<typename T, typename C>
bool heap<T,C>::ibr        (int i) const{
    return (2*i+2<_v.vector_size() && i>=0) ? true : false;
}



template<typename T, typename C>
int heap<T,C>::parent_index(int i) const{

    assert( (int)(i-1)/2 >= 0 ||
            i>= _v.vector_size());

    if(i==0){
        return 0;
    }

    if(i>0){
        return (i-1)/2;
    }

}

template<typename T, typename C>
int         heap<T,C>::left_child_index(int i) const{
    assert(ibl(i));
    return 2*i+1;
}

template<typename T, typename C>
int         heap<T,C>::right_child_index(int i) const{
    assert(ibr(i));
    return 2*i+2;
}

template<typename T, typename C>
int heap<T,C>::N_child_index(int i) const{

    if(is_leaf(i) || i>= size()){
        assert("its a leaf! or its out of scope"=="");
    }
    //only a left
    if (!ibr(i)){
        return left_child_index(i);
    }

    //has both children
    if (_compare(_v[left_child_index(i)], _v[right_child_index(i)])){
        return left_child_index(i);
    }
    else{
        return  right_child_index(i);
    }

    assert("SHOULDNT BE HERE"=="");


}


template<typename T, typename C>
/*-*/void heap<T,C>::swap_with_parent(int i){
    assert(i>0);

    if (_compare(_v[i], _v[parent_index(i)])){
        item<T> temp = _v[parent_index(i)];
        /* parent becomes child */
        _v[parent_index(i)] = _v[i];
        /* child takes parent value */
        _v[i] = temp;
    }
}














#endif // HEAP_RE_H
