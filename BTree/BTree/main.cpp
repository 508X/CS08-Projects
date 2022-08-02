#include <iostream>

using namespace std;
int test_f(int* a, int item, int size);
int main()
{
    static const int size = 10;
                //0  1  2  3  4  5  6  7  8  9   10//
    int a[size] = {10,20,30,45,55,65,70,80,90,100};
    cout<<"P: "<<test_f(a, 34, size)<<endl;
    cout<<"P: "<<test_f(a, 70, size)<<endl;
    cout<<"P: "<<test_f(a, 62, size)<<endl;
    cout<<"P: "<<test_f(a, 12, size)<<endl;
    cout<<"P: "<<test_f(a,  4, size)<<endl;
    cout<<"P: "<<test_f(a,115, size)<<endl;
    cout<<"P: "<<test_f(a, 89, size)<<endl;


    return 0;
}
int test_f(int* a, int item, int size){
    int i=0;
    while(i<size && item >= a[i]){
        i++;
    }
    if(a[i]>a[size]){
        return size;
    }
    else{
        return i;
    }
}
