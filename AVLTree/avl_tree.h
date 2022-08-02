#ifndef TREE_NODE
#define TREE_NODE

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

// MAKE IS_VALID

using namespace std;

template <typename T>
struct avl_tree{
    T _item;
    avl_tree<T>* _left;
    avl_tree<T>* _right;
    int _height;
    int balance_factor(){

        int tl =  _left != NULL ?  _left->_height : -1;
        int tr = _right != NULL ? _right->_height : -1;

        return  tr - tl;

        //balance factor = height of the right subtree
        //                        - the height of the left subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
    }
    int height()        {

        int tl =  _left != NULL ?  _left->_height : -1;
        int tr = _right != NULL ? _right->_height : -1;

        return 1+max(tr, tl);
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
    }
/*-*/int update_height(){
        _height = height();
        return _height;
        //set the _height member variable (call height();)
    }

/*-*/avl_tree(T item=T(), avl_tree* left=NULL,
                          avl_tree* right=NULL)
        :_item(item), _left(left), _right(right)
    {
        _height = update_height();
        //don't forget to set the _height.
    }
/*-*/friend ostream& operator <<(ostream& outs,
                                const avl_tree<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
    }
/*-*/avl_tree<T>*& operator +=(const avl_tree<T>* src){

        if(src==NULL){return *this;}

        tree_add(*this, src);

        return *this;


    }
};



template <typename T>
/*-*/void tree_insert(avl_tree<T>* &root, const T& insert_me);


template <typename T>
/*-*/avl_tree<T>* tree_search(avl_tree<T>* root, const T& target);
template <typename T>
/*-*/bool tree_search(avl_tree<T>* root, const T& target,
                 avl_tree<T>* &found_ptr);

template<typename T>
/*-*/void tree_print(avl_tree<T>* root, int level=0,
                                    ostream& outs=cout);
template<typename T>
/*-*/void preorder_print(avl_tree<T>* root, int level=0,
                                    ostream& outs=cout);
template<typename T>       //prints detailes info about each node
/*-*/void tree_print_debug(avl_tree<T>* root, int level=0,
                                          ostream& outs=cout);

template <typename T>       //clear the tree
/*-*/void tree_clear(avl_tree<T>* &root);

template <typename T>       //erase target from the tree
/*-*/bool tree_erase(avl_tree<T>*& root, const T& target);

template <typename T>       //erase rightmost node from the tree
/*-*/void tree_remove_max(avl_tree<T>* &root, T& max_value);

template <typename T>       //return copy of tree pointed to by root
/*-*/avl_tree<T>* tree_copy(avl_tree<T>* root);

template <typename T>       //Add tree src to dest
/*-*/void tree_add(avl_tree<T>* & dest, const avl_tree<T>* src);


template <typename T>
avl_tree<T>* tree_from_sorted_list(int* a, int start, int end);

template <typename T>
void rotate_left(avl_tree<T>* &root);

template <typename T>
void rotate_right(avl_tree<T>* &root);

template <typename T>
void rotate(avl_tree<T>* &root);

template <typename T>
bool is_valid(avl_tree<T>* root);

template <typename T>
int get_height(avl_tree<T>* root);

template <typename T>
void setval(avl_tree<T>*& root, int k);

template <typename T>
void sethgt(avl_tree<T>*& root, int k);

template <typename T>
void setval(avl_tree<T>*& root, int k){
    root->_item = k;
}

template <typename T>
void sethgt(avl_tree<T>*& root, int k){
    root->_height = k;
}

template <typename T>
void tree_insert(avl_tree<T>* &root, const T& insert_me){

    if(root==NULL){
        root = new avl_tree<T>(insert_me);
    }
    else if(insert_me < root->_item){
        tree_insert(root->_left,insert_me);
    }
    else if(insert_me > root->_item){
        tree_insert(root->_right, insert_me);
    }    

    root->update_height();
    rotate(root);
    root->update_height();

}
template <typename T>
avl_tree<T>* tree_search(avl_tree<T>* root, const T& target){

    if(root==nullptr){return root;}
    if(root->_item ==target){return root;}

    else if(root->_item < target){tree_search(root->_right, target);}
    else if(root->_item > target){tree_search(root->_left , target);}

}
template <typename T>
bool tree_search(avl_tree<T>* root, const T& target, avl_tree<T>* &found_ptr){

    found_ptr = tree_search(root, target);
    if(found_ptr!= NULL && found_ptr->_item==target){return true;}

    return false;
}
template<typename T>
void tree_print(avl_tree<T>* root, int level, ostream& outs){
    if(root){
        tree_print(root->_right, level+1);
        outs<<setw(4*level)<<""<<"["<<root->_item<<"]"<<endl;
        tree_print(root->_left, level+1);
    }
}
template<typename T>
/*-*/void preorder_print(avl_tree<T>* root, int level, ostream& outs){
    if(root){

    }
}
template<typename T>
void tree_print_debug(avl_tree<T>* root, int level, ostream& outs){
    if(root){

        tree_print_debug(root->_right, level+1);

        string validity;
        if(is_valid(root)){validity = "O";}
        else{validity = "X";}
        //....Validity O = true..Height...............................Balance Factor...Item
        outs<<"V{"<<validity<<"} H{"<<setw(2)<<root->_height<<"}"<<"  B{"<<setw(2)<<root->balance_factor()<<"} "<<setw(4*level)<<""<<"["<<root->_item<<"]"<<endl;
        tree_print_debug(root->_left, level+1);
    }
}
template <typename T>
void tree_clear(avl_tree<T>* &root){
    if(root){
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root = NULL;
    }
}
template <typename T>
bool tree_erase(avl_tree<T>*& root, const T& target){

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
            avl_tree<T>* temp;
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
void tree_remove_max(avl_tree<T>* &root, T& max_value){

    if(root == NULL){return;}

    if(root->_right != NULL){tree_remove_max(root->_right, max_value);}

    else if(root->_right == NULL){


        if(root->_left != NULL){
            avl_tree<T>* temp = root;
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
avl_tree<T>* tree_copy(avl_tree<T>* root){
    if(root){
        return new avl_tree<T>(root->_item,
                                tree_copy(root->_left),
                                tree_copy(root->_right));
        root->update_height();
    }
    else{
        return NULL;
    }
}
template <typename T>
void tree_add(avl_tree<T>* & dest, const avl_tree<T>* src){

    if(src==NULL){return;}

    tree_insert(dest, src->_item);

    tree_add(dest, src->_left);
    tree_add(dest, src->_right);

}
template <typename T>
avl_tree<T>* tree_from_sorted_list(T* a, int start, int end){

    /*
        define a new middle
        create a root then call recursion on right and
        left nodes
        update height
    */
    if(start > end){return NULL;}
    int mid = (start+end)/2;
    avl_tree<T>* root = new avl_tree<T>(a[mid]);
    root->_right = tree_from_sorted_list<T>(a, mid+1, end);
    root->_left = tree_from_sorted_list<T>(a, mid+1, end);
    root->update_height();

}

template <typename T>
void rotate_left(avl_tree<T>* &root){

//    cout<<"~~rotate left~~"<<endl;

    /* let temp be the root, and
     *
     * redefine root to be the right of itself
     *
        let temp's right be the roots left

        and let the roots left be temp

        and update height of both from bottom up
    */

    avl_tree<T>* temp = root;
    root = temp->_right;

    temp->_right = root->_left;
    root->_left = temp;

    avl_tree<T>* temp2 = root->_left;

    temp2->update_height();
    root->update_height();

}

template <typename T>
void rotate_right(avl_tree<T>* &root){

//    cout<<"~~rotate right~~"<<endl;

    /* let temp be the root, and redefine
        root to be the left of itself
        let temp's left be the roots right
        and let the roots right be temp
        and update height of both from bottom up
    */

    avl_tree<T>* temp = root;
    root = temp->_left;
    temp->_left = root->_right;
    root->_right = temp;

    avl_tree<T>* temp2 = root->_right;

    temp2->update_height();
    root->update_height();
}

template <typename T>
void rotate(avl_tree<T>* &root){

    if(root==NULL){return;}
//    avl_tree<T>* rootright = root->_right;
//    avl_tree<T>* rootleft =  root->_left;

    //right heavy root
    if(root->balance_factor() > 1){
        //right leaning child
        if(root->_right->balance_factor() == 1){
            rotate_left(root);
        }
        //*left leaning child
        else if(root->_right->balance_factor() == -1){
            rotate_right(root->_right);
            rotate_left(root);
        }
    }
    //left heavy root
    else if(root->balance_factor() < -1){
        //left leaning child
        if(root->_left->balance_factor() == -1){
            rotate_right(root);
        }
        //*right leaning child
        else if(root->_left->balance_factor() == 1){
            rotate_left(root->_left);
            rotate_right(root);
        }
    }
}

template <typename T>
bool is_valid(avl_tree<T>* root){

    if(root->_height == get_height(root) && abs(root->balance_factor())<2){return true;}
    return false;

}

template <typename T>
int get_height(avl_tree<T>* root){

    if(!root){return -1;}
    else{

        int right = get_height(root->_right);
        int left  = get_height(root->_left);
        return 1+max(right,left);

    }

}

#endif // TREE_NODE
