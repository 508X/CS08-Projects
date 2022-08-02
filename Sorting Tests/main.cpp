#include <iostream>
#include "../Sorting Functions/sorts/sorts.h"

using namespace std;


const static int size = 10;

void test_merge();
void test_heap();
void test_quick();
void test_bubble();
void test_ins();


int main()
{


    test_merge();
    test_heap();
    test_quick();
    test_bubble();
    test_ins();





    return 0;
}


void test_merge(){
    cout<<"MERGE START---------------------------------------------------"<<endl<<endl;
    int a[size];
    for(int i = 0; i< size; i++){
        a[i] = i+1;
    }

    shuffle(a, size);
    print_array(a, size);
    f_merge(a, size);
    print_array(a, size);
    cout<<endl;
    cout<<"MERGE END---------------------------------------------------"<<endl<<endl;
}

void test_heap(){
    cout<<"HEAP START---------------------------------------------------"<<endl<<endl;

    int c[size];
    for(int i = 0; i< size; i++){
        c[i] = i+1;
    }
    shuffle(c, size);
    print_array(c, size);
    f_heap(c, size);
    print_array(c, size);
    cout<<endl;
    cout<<"HEAP END---------------------------------------------------"<<endl<<endl;

}

void test_ins(){
    cout<<"INS START---------------------------------------------------"<<endl<<endl;

    int d[size];
    for(int i = 0; i< size; i++){
        d[i] = i+1;
    }

    shuffle(d, size);
    print_array(d, size);
    f_insertion(d, size);
    print_array(d, size);
    cout<<endl;

    cout<<"INS END---------------------------------------------------"<<endl<<endl;

}

void test_quick(){
    cout<<"QUICK START---------------------------------------------------"<<endl<<endl;

    int b[size];
    for(int i = 0; i< size; i++){
        b[i] = i+1;
    }

    shuffle(b, size);
    print_array(b, size);
    f_quick(b, size);
    print_array(b,size);
    cout<<endl;
    cout<<"QUICK END---------------------------------------------------"<<endl<<endl;

}

void test_bubble(){
    cout<<"BUBBLE START---------------------------------------------------"<<endl<<endl;

    int e[size];
    for(int i = 0; i< size; i++){
        e[i] = i+1;
    }

    shuffle(e, size);
    print_array(e, size);
    f_bubble(e, size);
    print_array(e, size);
    cout<<endl;
    cout<<"BUBBLE END---------------------------------------------------"<<endl<<endl;


}


