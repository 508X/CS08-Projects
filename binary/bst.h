#ifndef BST_H
#define BST_H
#include <tree_node.h>
#include <iostream>
using namespace std;

void test();

template <typename T>
class BST{

public:
    BST();
    BST(const T* sorted_list, int size=-1);

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST(const BST<T>& copy_me);
    BST<T>& operator =(const BST<T>& rhs);
    ~BST();

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me);
    void erase(const T& target);
    bool search(const T& target, tree_node<T>* & found_ptr);

    friend ostream& operator <<(ostream& outs, const BST<T>& tree){
        tree_print(tree.root);
        return outs;
    }
    BST<T>& operator +=(const BST<T>& rhs);

private:
    tree_node<T>* root;
};

template<class T>
BST<T>::BST(){
    root = new tree_node<T>();
}
template<class T>
BST<T>::BST(const T* sorted_list, int size){
    root = tree_from_sorted_list(sorted_list, 0, size);
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template<class T>
BST<T>::BST(const BST<T>& copy_me){
    tree_clear(root);
    tree_copy(copy_me.root);
}
template<class T>
BST<T>& BST<T>::operator =(const BST<T>& rhs){
    if(this==&rhs){return *this;}

    tree_node<T>* nroot = new tree_node<T>();
    nroot = tree_copy(rhs);

    return *this;
}
template<class T>
BST<T>::~BST(){
    tree_clear(root);
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template<class T>
void BST<T>::insert(const T& insert_me){
    tree_insert(root, insert_me);
}
template<class T>
void BST<T>::erase(const T& target){
    tree_erase(root, target);
}
template<class T>
bool BST<T>::search(const T& target, tree_node<T>* & found_ptr){
    return tree_search(root, target, found_ptr);
}
template<class T>
BST<T>& BST<T>::operator +=(const BST<T>& rhs){

    tree_node<T>* nroot = new tree_node<T>();
    nroot = rhs;
    tree_add(nroot, rhs.root);

    return *this;

}

void test(){

    bool done = false;
    bool found = false;
    char choice = char();
    BST<int> a;
    tree_node<int>* fptr = new tree_node<int>();
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

            a.~BST();

            break;
        case 's':

            cout<<">>: ";cin>>num;
            found = a.search(num, fptr);
            if(found == true){
                cout<<">>: found-> "<<fptr->_item;
            }
            else{
                cout<<">>: !found  "<<endl;
            }

            break;
        case 'x':
            cout<<"See ya later!"<<endl;
            done = true;
            break;
        default:
            cout<<"I can't wait for humanity to go to mars\n I'm extremely excited by Elon musk's promise that he will get people to Mars.\n Our specie will finally become an interplanetary one !\n My brain stopped developing after my 8th birthday and I am an absolute moron !\n So pumped up for this"<<endl;
        }



    }while(!done);


}
#endif // BST_H
