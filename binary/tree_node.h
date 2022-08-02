#ifndef TREE_NODE
#define TREE_NODE

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;
    int balance_factor(){

        int tr =  _left != NULL ?  _left->_height : -1;
        int tl = _right != NULL ? _right->_height : -1;
        return  tr - tl;

        //balance factor = height of the right subtree
        //                        - the height of the left subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
    }
    int height()        {
        int tr =  _left != NULL ?  _left->_height : -1;
        int tl = _right != NULL ? _right->_height : -1;
        return 1+max(tr, tl);
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
    }
/*-*/int update_height(){
        _height = height();
        return _height;
        //set the _height member variable (call height();)
    }

/*-*/tree_node(T item=T(), tree_node* left=NULL,
                          tree_node* right=NULL)
        :_item(item), _left(left), _right(right)
    {
        _height = update_height();
        //don't forget to set the _height.
    }
/*-*/friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
    }
/*-*/tree_node<T>*& operator +=(const tree_node<T>* src){





    }
};



template <typename T>
/*-*/void tree_insert(tree_node<T>* &root, const T& insert_me);

template <typename T>
/*-*/tree_node<T>* tree_search(tree_node<T>* root, const T& target);
template <typename T>
/*-*/bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr);

template<typename T>
/*-*/void tree_print(tree_node<T>* root, int level=0,
                                    ostream& outs=cout);

template<typename T>       //prints detailes info about each node
/*-*/void tree_print_debug(tree_node<T>* root, int level=0,
                                          ostream& outs=cout);

template <typename T>       //clear the tree
/*-*/void tree_clear(tree_node<T>* &root);

template <typename T>       //erase target from the tree
/*-*/bool tree_erase(tree_node<T>*& root, const T& target);

template <typename T>       //erase rightmost node from the tree
/*-*/void tree_remove_max(tree_node<T>* &root, T& max_value);

template <typename T>       //return copy of tree pointed to by root
/*-*/tree_node<T>* tree_copy(tree_node<T>* root);

template <typename T>       //Add tree src to dest
/*-*/void tree_add(tree_node<T>* & dest, const tree_node<T>* src);


template <typename T>
tree_node<T>* tree_from_sorted_list(int* a, int start, int end);


template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){
    if(root==NULL){
        root = new tree_node<T>(insert_me);
    }
    else if(insert_me < root->_item){
        tree_insert(root->_left,insert_me);
    }
    else if(insert_me > root->_item){
        tree_insert(root->_right, insert_me);
    }
    root->update_height();
}
template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){

    if(root==nullptr){return root;}
    if(root->_item ==target){return root;}
    else if(root->_item < target){tree_search(root->_right, target);}
    else if(root->_item > target){tree_search(root->_left , target);}

}
template <typename T>
bool tree_search(tree_node<T>* root, const T& target, tree_node<T>* &found_ptr){

    found_ptr = tree_search(root, target);
    if(found_ptr!= NULL && found_ptr->_item==target){return true;}

    return false;
}
template<typename T>
void tree_print(tree_node<T>* root, int level, ostream& outs){
    if(root){
        tree_print(root->_right, level+1);
        outs<<setw(4*level)<<""<<"["<<root->_item<<"]"<<endl;
        tree_print(root->_left, level+1);
    }
}
template<typename T>
void tree_print_debug(tree_node<T>* root, int level, ostream& outs){
    if(root){
        tree_print_debug(root->_right, level+1);
        outs<<"--["<<root->_height<<"]"<<"["<<root->balance_factor()<<"] "<<setw(4*level)<<""<<"["<<root->_item<<"]"<<endl;
        tree_print_debug(root->_left, level);
    }
}
template <typename T>
void tree_clear(tree_node<T>* &root){
    if(root){
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root = NULL;
    }
}
template <typename T>
bool tree_erase(tree_node<T>*& root, const T& target){

            /*
        Case 1:
            root is null
            return false
        Case 2:
            target > root->item
        Case 3:
            target < root->item
        Case 4:
            target == root->item

            A: Target has no left subtree:
                >bypass target and connect to right subtree

            B: Target has a  left subtree:

                (assume there is a subtree)

                find the rightmost node in the left
                side of the subtree
                remove it and replace the target with it

                point the right node of the previous to the
                rightmost node, and point it to the
                left subtree of the rightmost node

    */
            /* Case 1 ->root is null */
    if(root == NULL){return false;}
            /* Case 2 target >  item */
    if(target > root->_item){tree_erase(root->_right, target);}
            /* Case 3 target <  item */
    else if(target < root->_item){tree_erase(root->_left, target);}
            /* Case 4 target == item */
    else if(target == root->_item){
            /* Case 4A: !Exists left subtree */
        if(root->_left == NULL){
            tree_node<T>* temp;
            temp = root;
            root = root->_right;
            delete temp;
            root->update_height();
            return true;
        }
            /* Case 4B: Exists left subtree */
        else if(root->_left != NULL){
            T temp;
            tree_remove_max(root->_left, temp);
            root->_item = temp;
            return true;
        }
    }
}
template <typename T>
void tree_remove_max(tree_node<T>* &root, T& max_value){

    if(root == NULL){return;}

    if(root->_right != NULL){tree_remove_max(root->_right, max_value);}
    else if(root->_right == NULL){


        if(root->_left != NULL){
            tree_node<T>* temp = root;
            max_value = root->_item;
            root = root->_left;
            delete temp;
            temp = nullptr;
            root->update_height();
            return;


        }
        else{
            max_value = root->_item;
            delete root;
            root = nullptr;
            return;
        }
    }

}
template <typename T>
tree_node<T>* tree_copy(tree_node<T>* root){
    if(root){
        return new tree_node<T>(root->_item,
                                tree_copy(root->_left),
                                tree_copy(root->_right));
        root->update_height();
    }
    else{
        return NULL;
    }
}
template <typename T>
void tree_add(tree_node<T>* & dest, const tree_node<T>* src){

    /*

      relly stupid function right now
      because i need to do prefix notation
      and add that way but whatever
      this adds backwards from max to lowest

    */
    tree_node<T>* nroot = new tree_node<T>();
    nroot = tree_copy<T>(src);

    int tmp;


    while(nroot!=NULL){
        tree_remove_max(nroot, tmp);
        tree_insert<T>(dest, tmp);
    }

}
template <typename T>
tree_node<T>* tree_from_sorted_list(T* a, int start, int end){

    /*
        define a new middle
        create a root then call recursion on right and
        left nodes
        update height
    */
    if(start > end){return NULL;}
    int mid = (start+end)/2;
    tree_node<T>* root = new tree_node<T>(a[mid]);
    root->_right = tree_from_sorted_list<T>(a, mid+1, end);
    root->_left = tree_from_sorted_list<T>(a, mid+1, end);
    root->update_height();
}


#endif // TREE_NODE
