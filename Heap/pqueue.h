#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
#include "heap_re.h"

template <typename T, typename C = Bigger<item<info<T> > > >
class PQueue
{
public:

    PQueue();

    bool insert(const T& value, int p);
    T pop();

    bool is_empty() const;
    int size() const;
    void print_tree() const;
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        outs<<print_me.heap;
        return outs;
    }

private:

    heap<info<T>, C > heap;

};
template <typename T, typename C>
PQueue<T,C>::PQueue()
    :heap()
{

}

template <typename T, typename C>
bool PQueue<T,C>::insert(const T& value, int p){
    if(p>=0){
//        cout<<"inserting into heap"<<endl;
        heap.insert(info<T>(value, p));

        return true;
    }
    else{
        return false;
    }
}
template <typename T, typename C>
T PQueue<T,C>::pop(){
    if(is_empty()){
        cout<<"empty!"<<endl;
        assert(" " == "");
    }
    info<T> tmp = heap.pop();
    return tmp._item;
}
template <typename T, typename C>
bool PQueue<T,C>::is_empty() const{
    if(heap.is_empty()){return true;}
    return false;
}
template <typename T, typename C>
int PQueue<T,C>::size() const{
    return heap.size();
}
template <typename T, typename C>
void PQueue<T,C>::print_tree() const{
    cout<<heap;
}



#endif // PQUEUE_H
