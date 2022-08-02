#ifndef AVL_H
#define AVL_H
#include "avl_tree.h"
#include <iostream>
using namespace std;

void test();

template <typename T>
class AVL{

public:
    AVL();
    AVL(const T* sorted_list, int size=-1);

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    AVL(const AVL<T>& copy_me);
    AVL<T>& operator =(const AVL<T>& rhs);
    ~AVL();

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me);
    void erase(const T& target);
    bool search(const T& target, avl_tree<T>* & found_ptr);

    friend ostream& operator <<(ostream& outs, const AVL<T>& tree){
        tree_print_debug(tree.root);
        return outs;
    }
    AVL<T>& operator +=(const AVL<T>& rhs);

private:
    avl_tree<T>* root;
};

template<class T>
AVL<T>::AVL(){
    root = new avl_tree<T>();
}
template<class T>
AVL<T>::AVL(const T* sorted_list, int size){
    root = tree_from_sorted_list(sorted_list, 0, size);
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template<class T>
AVL<T>::AVL(const AVL<T>& copy_me){
    tree_clear(root);
    tree_copy(copy_me.root);
}
template<class T>
AVL<T>& AVL<T>::operator =(const AVL<T>& rhs){
    if(this==&rhs){return *this;}

    avl_tree<T>* nroot = new avl_tree<T>();
    nroot = tree_copy(rhs);

    return *this;
}
template<class T>
AVL<T>::~AVL(){
    tree_clear(root);
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template<class T>
void AVL<T>::insert(const T& insert_me){
    tree_insert(root, insert_me);
}
template<class T>
void AVL<T>::erase(const T& target){
    tree_erase(root, target);
}
template<class T>
bool AVL<T>::search(const T& target, avl_tree<T>* & found_ptr){
    return tree_search(root, target, found_ptr);
}
template<class T>
AVL<T>& AVL<T>::operator +=(const AVL<T>& rhs){

    avl_tree<T>* nroot = new avl_tree<T>();
    nroot = rhs;
    tree_add(nroot, rhs.root);
    return *this;

}

void test(){

    bool done = false;
    bool found = false;
    char choice = char();
    AVL<int> a;
    avl_tree<int>* fptr = new avl_tree<int>();
    int k = 0;
    int num = 0;
    do{

        cout<<endl<<endl;
        cout<<a;
        cout<<"==============================================="<<endl;
        cout<<"[R]andom  [I]nsert  [C]lear  [S]earch  [X]it: ";
        cin>>choice;
        switch(tolower(choice)){


        case 'r':

            k = rand()%99 - 50;
            cout<<">>: "<<k<<endl;
            a.insert(k);

            break;
        case 'i':

            cout<<">>: ";cin>>num;
            a.insert(num);

            break;
        case 'c':

            a.~AVL();

            break;
        case 's':

            cout<<">>: ";cin>>num;
            found = a.search(num, fptr);
            if(found == true){
                cout<<">>: found-> "<<fptr->_item;
            }
            else{
                cout<<">>: not found  "<<endl;
            }

            break;
//        case 'n':
//            cout<<">>: ";cin>>num;
//            setval(fptr, num);
//            break;
//        case 'm':
//            cout<<">>: ";cin>>num;
//            sethgt(fptr, num);
//            break;
        case 'x':
            cout<<"See ya later!"<<endl;
            done = true;
            break;
        default:
            cout<<"I can't wait for humanity to go to mars\n I'm extremely excited by Elon musk's promise that he will get people to Mars.\n Our specie will finally become an interplanetary one !\n My brain stopped developing after my 8th birthday and I am an absolute moron !\n So pumped up for this"<<endl;
        }

    }while(!done);


}
#endif // AVL_H
