#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <iostream>
#include "sorts.h"
#include "averager.h"

using namespace std;

const static int size = MAX;

void simulate();

void test_merge();
void test_bubble();
void test_quick();
void test_ins();
void test_heap();

class timer{

private:

    clock_t _start;
    clock_t _stop;

public:

    timer():_start(clock()), _stop(clock()){}
    void start(){
        _start = clock();
    }
    void stop(){
        _stop = clock();
    }
    float duration(){
        return (float(_stop) - float(_start))/CLOCKS_PER_SEC;
    }


};


float time_sort_routine(int a[], int  size,
                        void (*f)(int* , int)){
    timer t;
    t.start();
    f(a, size);
    t.stop();
    return t.duration();

}


void simulate(){

    averager avgM;

    int a[size];
    for(int i(0); i<size; i++){
        a[i] = i+1;
    }

    for(int i(0); i<500; i++){

        shuffle(a, size);
        avgM.next_number(time_sort_routine(a, size, f_merge));

    }

    cout<<"average duration - mergesort("<<size<<"): "<<avgM.average()<<endl;

    averager avgQ;

    for(int i(0); i<500; i++){

        shuffle(a, size);
        avgQ.next_number(time_sort_routine(a, size, f_quick));

    }

    cout<<"average duration - quicksort("<<size<<"): "<<avgQ.average()<<endl;



    averager avgH;

    for(int i(0); i<500; i++){

        shuffle(a, size);
        avgH.next_number(time_sort_routine(a, size, f_heap));

    }

    cout<<"average duration - heapsort("<<size<<"): "<<avgH.average()<<endl;




}


void test_all(){


    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(10);

    test_merge();
    test_heap();
//    test_ins();
    test_quick();
//    test_bubble();


}






void test_merge(){
    cout<<"---------------------------------------------------"<<endl<<endl;
    int a[size];
    for(int i = 0; i< size; i++){
        a[i] = i+1;
    }

    shuffle(a, size);
    float dur = time_sort_routine(a, size, f_merge);
    cout<<"Merge: "<<dur<<endl;
    print_array(a, size);
    cout<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl;
}

void test_heap(){
    cout<<"---------------------------------------------------"<<endl<<endl;

    int c[size];
    for(int i = 0; i< size; i++){
        c[i] = i+1;
    }
    shuffle(c, size);
    float dur3 = time_sort_routine(c, size, f_heap);
    cout<<"Heap: "<<dur3<<endl;
    print_array(c, size);
    cout<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl;

}

void test_ins(){
    cout<<"---------------------------------------------------"<<endl<<endl;

    int d[size];
    for(int i = 0; i< size; i++){
        d[i] = i+1;
    }

    shuffle(d, size);
    float dur4 = time_sort_routine(d, size, f_insertion);
    cout<<"Insertion: "<<dur4<<endl;
    print_array(d, size);
    cout<<endl;

    cout<<"---------------------------------------------------"<<endl<<endl;

}

void test_quick(){
    cout<<"---------------------------------------------------"<<endl<<endl;

    int b[size];
    for(int i = 0; i< size; i++){
        b[i] = i+1;
    }

    shuffle(b, size);
    float dur2 = time_sort_routine(b, size, f_quick);
    cout<<"Quick: "<<dur2<<endl;
    print_array(b, size);
    cout<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl;

}

void test_bubble(){
    cout<<"---------------------------------------------------"<<endl<<endl;

    int e[size];
    for(int i = 0; i< size; i++){
        e[i] = i+1;
    }

    shuffle(e, size);
    float dur5 = time_sort_routine(e, size, f_bubble);
    cout<<"Bubble: "<<dur5<<endl;
    print_array(e, size);
    cout<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl;


}



#endif // TIMER_H
