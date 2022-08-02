#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>

#include "../../Heap/heap_re.h"
#include "../../Heap/cmp.h"

const static int MAX = 10;

using namespace chrono;
using namespace std;

template <class T>
void f_count(T a[],  int size);

template <class T>
void f_radix(T a[],  int size);

template <class T>
void f_quick(T a[],  int size);

template <class T>
void f_quick(T a[],  int left,  int right);

template <class T>
void f_merge(T a[],  int size);

template <class T>
void f_merge(T a[],  int left,  int right);

template <class T>
void f_heap(T a[],  int size);

template <class T>
void heapify(T arr[], int n, int i);

template <class T>
void f_insertion(T a[],  int size);

template <class T>
void f_bubble(T a[],  int size);

template<class T>
void merge(T a[], int low, int high, int mid);

//shuffle elements of a[]
template <class T>
void shuffle(T a[],  int  size);

template <class T>
void copy_array(T dest[], const T src[],  int size);

//return true if a[] is in ascending order
template <class T>
bool verify(const T a[],  int  size);

//return a string "SORTED" or "NOT SORTED" depending if a[] is sorted
template <class T>
string verifystr(const T a[],  int  size);

//print the array if status_only is true along with info on sortedness of a[]
template <class T>
void print_array(const T a[], int size, bool status_only = false);

//print a[] from start to end
template <class T>
void print_array_segment(T a[],  int start,  int end);

template <class T>
void swap_v(T& a, T&b);

template <class T>
int partition(T a[], int left, int right);




template <class T>
void f_count(T a[],  int size){

}

template <class T>
void f_radix(T a[],  int size){

}

template <class T>
void f_quick(T a[],  int size){
    f_quick(a, 0, size);
}
template <class T>
void f_quick(T a[],  int low,  int high){
    if (low < high)
        {
            /* pi is partitioning index, arr[pi] is now
               at right place */
            int pi = partition(a, low, high);

            f_quick(a, low, pi - 1);  // Before pi
            f_quick(a, pi + 1, high); // After pi
        }

}
template<class T>
int partition(T a[], int low, int high){

    int pivot = a[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (a[j] < pivot)
        {
            i++; // increment index of smaller element
            swap_v(a[i], a[j]);

        }
    }

    swap_v(a[i+1], a[high]);

    return (i+1);
}

template <class T>
void f_merge(T a[],  int size){
    f_merge(a, 0, size-1);
}
template <class T>
void f_merge(T a[],  int low,  int high){
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        f_merge(a,low,mid);
        f_merge(a,mid+1,high);
        //merge or conquer sorted arrays
        merge(a,low,high,mid);
    }
}
template<class T>
void merge(T arr[], int low, int high, int mid)
{
    int i, j, k, c[MAX];
    i = low;
    k = low;
    j = mid + 1;
    while(i <= mid && j <= high){
        if (arr[i] < arr[j]){
            c[k] = arr[i];
            k++;
            i++;
        }
        else{
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}


template <class T>
void heapify(T arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap_v(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

template <class T>
void f_heap(T a[],  int size){

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(a, size, i);

    for (int i=size-1; i>=0; i--)
    {
        swap_v(a[0], a[i]);
        heapify(a, i, 0);
    }
//    heap<T> _heap;
//    for(int i=0; i<size; i++){
//        _heap.insert(a[i]);
//        cout<<"inserted: "<<a[i]<<endl;
//    }

////    cout<<"made heap"<<endl;

//    for(int i=0; i<size; i++){
////        cout<<"inserting : "<<a[i]<<endl;
////        cout<<_heap<<endl;

////        T temp = _heap.pop();

////        cout<<">>inserted "<<temp<<endl;
////        _heap.insert(temp);

//    }


}

template <class T>
void f_insertion(T a[],  int size){

    int i, key, j;
    for (i=1; i<size; i++)
    {
        key = a[i];
        j = i-1;
        /* Move elements of a[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }


}

template <class T>
void f_bubble(T a[], int size)
{
   int i, j;
   bool swapped;
   for (i = 0; i < size-1; i++)
   {
     swapped = false;
     for (j = 0; j < size-i-1; j++)
     {
        if (a[j] > a[j+1])
        {
           swap_v(a[j], a[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}







//shuffle elements of a[]
template <class T>
void shuffle(T a[],  int  size){
    for (int i = size-1; i > 0; --i) {
        using std::swap;
        swap(a[i], a[rand() % (i+1)]);
    }
}

template <class T>
void copy_array(T dest[], const T src[],  int size){
    for(int i(0); i<size; i++){
        dest[i] = src[i];
    }
}

//return true if a[] is in ascending order
template <class T>
bool verify(const T a[],  int  size){
    if(size<=1){return true;}
    for(int i(0); i<size-1; i++){
        if(a[i]>a[i+1]){return false;}
    }
    return true;
}

//return a string "SORTED" or "NOT SORTED" depending if a[] is sorted
template <class T>
string verifystr(const T a[],  int  size){
    return verify(a,size) ? "SORTED" : "NOT SORTED";
}

//print the array if status_only is true along with info on sortedness of a[]
template <class T>
void print_array(const T a[], int size, bool status_only){
    if(status_only)
    cout<<verifystr(a,size)<<endl;
    else{
    cout<<verifystr(a,size)<<endl;
    print_array_segment(a, 0, size);
    }
}

//print a[] from start to end
template <class T>
void print_array_segment(T a[],  int start,  int end){
    cout<<"{ ";
    for(int i(start); i<end; i++){
        cout<<a[i];

        if(i+1<end)
        cout<<", ";
    }
    cout<<"}"<<endl;
}

template <class T>
void swap_v(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

#endif // SORTS_H
