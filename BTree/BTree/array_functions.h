#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
void clear_array(T a[], int& size);
template<typename T>
void shift_right(T a[], int& size, int mark);
template<typename T>
void  shift_left(T a[], int& num_used, int mark);
template<typename T>
void remove(T a[], int& num_used, int mark);
template<typename T>
void append_array(T dest[], int& dest_num_used, T src[], int src_num_used);

template <typename T>
T maximal(const T& a, const T& b);  //return the larger of the two items
template <typename T>
void swap(T& a, T& b);  //swap the two items
template <typename T>
int index_of_maximal(T data[ ], int n);     //return index of the largest item in data
template <typename T>
void ordered_insert(T data[ ], int& n, T entry);    //insert entry into the sorted array data with length n
template <typename T>
int first_ge(const T data[], int n, const T& entry);   //return the first element in data that is not less than entry
template <typename T>
void attach_item(T data[ ], int& n, const T& entry);    //append entry to the right of data
template <typename T>
void insert_item(T data[ ], int i, int& n, T entry);    //insert entry at index i in data
template <typename T>
void detach_item(T data[ ], int& n, T& entry);  //remove the last element in data and place it in entry
template <typename T>
void delete_item(T data[ ], int i, int& n, T& entry);   //delete item at index i and place it in entry
template <typename T>
void merge(T data1[ ], int& n1, T data2[], int& n2);   //append data2 to the right of data1
template <typename T>
void split(T data1[ ], int& n1, T data2[], int& n2);   //move n/2 elements from the right of data1 and move to data2
template <typename T>
void copy_array(T dest[], const T src[], int& dest_size, int src_size); //copy src[] into dest[]
template <typename T>
void print_array(const T data[], int n, int pos = -1);  //print array data
template <typename T>
bool is_gt(const T data[], int n, const T& item);       //item > all data[i]
template <typename T>
bool is_le(const T data[], int n, const T& item);       //item <= all data[i]

template <typename T>
ostream& operator <<(ostream& outs, const vector<T>& list); //print vector list
template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme); //list.push_back addme


template<typename T>
void clear_array(T a[], int& size){
    size=0;
}
template<typename T>
void shift_right(T a[], int& size, int mark){
    size++;
    for(int i = size -1; i>mark; i--){
        a[i]=a[i-1];}
}
template<typename T>
void  shift_left(T a[], int& num_used, int mark){
        for(int i = mark; i<num_used; i++){
            a[i] = a[i+1];
        }
        num_used--;
}
template<typename T>
void remove(T a[], int& num_used, int mark){
        shift_left(a, num_used, mark);
}
template<typename T>
void append_array(T dest[], int& dest_num_used, T src[], int src_num_used){
    int temp = dest_num_used;
    dest_num_used+=src_num_used;
    for(int i = temp; i<dest_num_used; i++){
        dest[temp+i] = src[i];
    }
}

template <typename T>
T maximal(const T& a, const T& b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
template <typename T>
void swap(T& a, T& b){

    T temp = a;
    a = b;
    b = temp;

}
template <typename T>
int index_of_maximal(T data[], int n){
    T max = 0;
    for(int i=0; i<n; i++){
        if(data[i]>max){
            max = i;
        }
    }
    return max;
}
template <typename T>
void ordered_insert(T data[], int& n, T entry){
    int place = first_ge(data, n, entry);
    shift_right(data, n, place);
    data[place] = entry;
}
template <typename T>
int first_ge(const T data[], int n, const T& entry){
   /* array is a sorted list
   return the index of the first item
   that is not less than item
   if item is larger than the last element,
   return size */
   int i=0;
   while(i<n && entry >= data[i]){
       i++;
   }
   if(data[i]>data[n]){
       return n;
   }
   else{
       return i;
   }
}
template <typename T>
void attach_item(T data[], int& n, const T& entry){
    data[n] = entry;
    n++;
}
template <typename T>
void insert_item(T data[], int i, int& n, T entry){
    shift_right(data, n, i);
    data[i] = entry;
}
template <typename T>
void detach_item(T data[], int& n, T& entry){
    if(n==0){
        entry = NULL;
        return;
    }
    entry = data[n-1];
    shift_left(data, n, n);
}
template <typename T>
void delete_item(T data[], int i, int& n, T& entry){

    assert(i<n);
    assert(i>=0);
    assert(n>0);

    entry = data[i];
    remove(data, n, i);
}
template <typename T>
void merge(T data1[], int& n1, T data2[], int& n2){
    append_array(data1, n1, data2, n2);
}
template <typename T>
void split(T data1[], int& n1, T data2[], int& n2){
        T* midpoint = data1[n1/2];
        append_array(midpoint, n1/2, data2, n2);
}
template <typename T>
void copy_array(T dest[], const T src[], int& dest_size, int src_size){
    dest_size = src_size;
    for(int i=0; i<dest_size; i++){
        dest[i] = src[i];
    }
}
template <typename T>
void print_array(const T data[], int n, int pos){
    assert(pos<n);
    for(int i=pos; i<n; i++){
        cout<<data[i];
    }
}
template <typename T>
bool is_gt(const T data[], int n, const T& item){
    for(int i=0; i<n; i++){
        if(item<=data[i]){
            return false;
        }
    }
    return true;
}
template <typename T>
bool is_le(const T data[], int n, const T& item){
    for(int i=0; i<n; i++){
        if(item>data[i]){
            return false;
        }
    }
    return true;
}

template <typename T>
ostream& operator <<(ostream& outs, const vector<T>& list){
    outs<<"{";
    int s = list.size();
    for(int i=0; i<s; i++){
        outs<<" "<<list[i];
        if(i+1!=s){
            outs<<",";
        }
    }
    outs<<"}";
    return outs;
}
template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme){
    list.push_back(addme);
}






#endif // ARRAY_FUNCTIONS_H
