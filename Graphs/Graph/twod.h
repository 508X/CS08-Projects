#ifndef TWOD_H
#define TWOD_H
#include <iostream>
#include <cassert>
#include "../../_includes/new_vect/vector.h"

using namespace std;


template <typename T>
class twod{

public:

    const static int basecap = 5;

    twod(){

        _cap = basecap;
        _twod = allocate2d(_cap);
        init_twod(_twod, _cap);

    }
    twod(int size){

        _cap = size;

//        _sizes = allocate(_cap);
//        init_size(_sizes, _cap);
        _twod = allocate2d(_cap);
        init_twod(_twod, _cap);

    }

    T*  allocate(int size){return new T[size];}
    T** allocate2d(int _cap);

    void resize(size_t size, size_t& cap){

        cap += 1;
        _cap = cap;

//        T* sizes = allocate(cap);
//        init_size(sizes, cap);

        T** temp = allocate2d(cap);

        for(int i(0); i<cap; i++){
            for(int j(0); j<cap; j++){
                if(i<size && j<size)
                    temp[i][j] = _twod[i][j];
                else
                    temp[i][j] = T();
            }
        }

        for(int i=0; i<size; i++){
            delete [] _twod[i];
        }

        _twod = temp;
    }

    void init_twod(T** twod, int cap){
        for(int i(0); i<cap; i++){
            twod[i] = allocate(cap);
        }
        for(int i=0; i<cap; i++){
            for(int j=0; j<cap; j++){
                twod[i][j] = T();
            }
        }
    }
    void init_oned(T*  oned, int length){
        for(int i=0; i<length; i++){oned[i] = T();}
    }
    T* operator [](int index){

        assert(index<_cap);
        assert(index>=0);

        return _twod[index];
    }
    T* operator [](int index) const{
        assert(index<_cap);
        assert(index>=0);

        return _twod[index];
    }




private:
//    int* _sizes;
    int  _cap;
    T** _twod;

};

template <typename T>
T** twod<T>::allocate2d(int cap){

    int k = _cap;
    T** p = new T*[k];
    T** p_w = p;

    for(int i=0; i<cap; i++){
        *p_w = new T[cap];
        p_w++;
    }
    return p;

}






#endif // TWOD_H
