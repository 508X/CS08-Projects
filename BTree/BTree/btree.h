#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include "array_functions.h"

using namespace std;
/*




*/




template<typename T>
class BTree{
public:
    BTree(bool dups = false);
    //big three:
    BTree(const BTree<T>& other);
    ~BTree();
    BTree<T>& operator =(const BTree<T>& RHS);

    void insert(const T& entry);                //insert entry into the tree
    /* insert(item){
                loose_insert(item);
                //travels doewn to a leaf,
                  and inserts item if is leaf
                //when backtracked to parent node,
                  check the child to see if itfits there
                  -> must take care of it HERE

            //

            shallow copy indecies into new copy.
            set all pointer of shallow copy onto the children of
            the previous node
            reset all the children of the previous
            clear the node
            set the child of the empty node
            to the newly created node

            //


        }
    //in order for this class to be able to keep track of the number of the keys, this function (and the functions
    //  it calls ) must return a success code.
    //If we are to keep track of the number the keys (as opposed to key/values) then the success
    //  code must distinguish between inserting a new key, or adding a new key to the existing key.
    //  (for "dupes_ok")
    //
    //loose_insert this entry into this root.
    //loose_insert(entry) will insert entry into this tree. Once it returns, all the subtrees are valid
    //  btree subtrees EXCEPT this root may have one extra data item:
    //    in this case (we have excess in the root)
    //      create a new node, copy all the contents of this root into it,
    //      clear this root node,
    //      make the new node this root's only child (subset[0])
    //
    //Then, call fix_excess on this only subset (subset[0])
    */
    void remove(const T& entry);                //remove entry from the tree

    void clear_tree();                          //clear this object (delete all nodes etc.)
    void copy_tree(const BTree<T>& other);      //copy other into this object

    bool contains(const T& entry);              //true if entry can be found in the array
    T& get(const T& entry);                     //return a reference to entry in the tree
    T* find(const T& entry);                    //return a pointer to this key. NULL if not there.

    int size() const;                           //count the number of elements in the tree
    bool empty() const;                         //true if the tree is empty

    void print_tree(int level = 0, ostream &outs=cout) const; //print a readable version of the tree
    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }

private:

    static const int MINIMUM = 1;
    static const int MAXIMUM = 2*MINIMUM;

    bool dups_ok;                       //true if duplicate keys may be inserted
    int data_count;                     //number of data elements
    T data[MAXIMUM+1];                  //holds the keys
    int child_count;                    //number of children
    BTree* subset[MAXIMUM+2];           //subtrees

    bool is_leaf() const                //true if this is a leaf node
    {return child_count==0;}

    //insert element functions
    void loose_insert(const T& entry);  //allows MAXIMUM+1 data elements in the root

    void fix_excess(int i);             //fix excess of data elements in child i

    //remove element functions:
    void loose_remove(const T& entry);  //allows MINIMUM-1 data elements in the root
    void fix_shortage(int i);           //fix shortage of data elements in child i

    void remove_biggest(T& entry);      //remove the biggest child of this tree->entry
    void rotate_left(int i);            //transfer one element LEFT from child i
    void rotate_right(int i);           //transfer one element RIGHT from child i
    void merge_with_next_subset(int i); //merge subset i with subset i+1

};



template<typename T>
BTree<T>::BTree(bool dups){

    data_count = 0;
    child_count = 0;
    dups_ok = dups;
    data = new T[MAXIMUM+1];
    subset = new BTree[MAXIMUM+2];

    for(int i: data){data[i] = T();}
    for(int i: subset){subset[i] = nullptr;}

}
//big three:
template<typename T>
BTree<T>::BTree(const BTree<T>& other){




}
template<typename T>
BTree<T>::~BTree(){

    clear_tree();


}
template<typename T>
BTree<T>& BTree<T>::operator =(const BTree<T>& RHS){



}








template<typename T>
void BTree<T>::insert(const T& entry){







}


template<typename T>
void BTree<T>::remove(const T& entry){
    //  Loose_remove the entry from this tree.
    //  once you return from loose_remove, the root (this object) may have no data and only a single subset
    //  now, the tree must shrink:
    //  point a temporary pointer (shrink_ptr) and point it to this root's only subset
    //  copy all the data and subsets of this subset into the root (through shrink_ptr)
    //  now, the root contains all the data and poiners of it's old child.
    //  now, simply delete shrink_ptr (blank out child), and the tree has shrunk by one level.
    //  Note, the root node of the tree will always be the same, it's the child node we delete

}


template<typename T>
void BTree<T>::clear_tree(){

    /*
      in main:

      BTree bt;
      bt.clear_tree(); [][][]
                      [][][][]

      items are static so there isnt anything to do
      _____________________________________________

      Now lets say you have a btree object that has

                         [][][]
                        [][][][]
                     /     |      \
                    /      |       \
                   /       |        \
              [][][]     [][][]     [][][]
             [][][][]   [][][][]   [][][][]
            V V V V V  V V V V V   V V V V V


            1. data_count = 0;

            2. delete all V's first (children of subsets, recursively)
               subset[i]->clear_tree();

            3. set all subset[i] to null of root

            4. child_count = 0;


    */

    clear_array(data, data_count);
    if(!is_leaf()){
        for(int i=0; i<child_count; i++){
            subset[i]->clear_tree();
            delete subset[i];
            subset[i] = nullptr;
        }
    }
    data_count(0);
    child_count(0);

}


template<typename T>
void BTree<T>::copy_tree(const BTree<T>& other){
    /*

    STEP ZER0: Call Clear on *THIS

      1. copy data of counterpart
      2. for every child, create one child
      3. recursively call copy tree on ym child, giving his child as argument

      subset[i]->copy_tree(other child)

    calling on              argument

    [][][]       <----      [btree]
   [][][][]     copy data    V  V  V

   [child]                  [other guys child]

   create a new child then, invoke copy on this child
   with the other guys child as argument
   LAYER BY LAYER

   some ptr  = new object when you build a new one

   make new btree on subset i
   and call copy on other.subset i

    */

    copy_array(data, other.data, data_count, other.data_count);
    for(int i(0); i< other.child_count; i++){
        attach_item(subset, child_count, new BTree(other.dups_ok));
        subset[i]->copy_tree(other.subset[i]);
    }
}

//---------------------------------------------------------------------
//            C O N T A I N S / F I N D / G E T / E T C .
//---------------------------------------------------------------------

template<typename T>
bool BTree<T>::contains(const T& entry){
    if(find(entry)){return true;}
    else{return false;}
}
template<typename T>
T& BTree<T>::get(const T& entry){

    //If entry is not in the tree, CRASH
    //assert(contains(entry));

    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (found)
        return data[i];
    if (is_leaf()){
        cout<<"get called with non-existent entry: "<<entry<<endl;
        insert(entry);
        return get(entry);
        //exit(-1);
    }
    if (!found)  //yet...
        return subset[i]->get(entry);
}
template<typename T>
T* BTree<T>::find(const T& entry){

    int i = first_ge(data, data_count, entry);
    bool found = data[i]==entry;
    if(is_leaf()){return NULL;}
    if(found){return &data[i];}
    else{subset[i]->find(subset[i]->data, subset[i]->data_count, entry);}

}





template<typename T>
int BTree<T>::size() const{
    return data_count;
}
template<typename T>
bool BTree<T>::empty() const{
    if(data_count==0){
        return true;
    }
    else{
        return false;
    }
}


template<typename T>
void BTree<T>::print_tree(int level, ostream &outs) const{


}


template<typename T>
void BTree<T>::loose_insert(const T& entry){


}


template<typename T>
void BTree<T>::fix_excess(int i){
  //this node's child i has one too many items: 3 steps:
  //1. add a new subset at location i+1 of this node
  //2. split subset[i] (both the subset array and the data array) and move half into
  // subset[i+1] (this is the subset we created in step 1.)
  //3. detach the last data item of subset[i] and bring it and insert it into this node's data[]
  // //Note that this last step may cause this node to have too many items. This is OK. This will be
  // dealt with at the higher recursive level. (my parent will fix it!)

    BTree* temp_btree = new BTree(dups_ok);

    insert_item(subset, i+1, child_count, temp_btree);

    split(subset[i]->data, subset[i]->data_count, temp_btree->data, temp_btree->data_count);
    split(subset[i]->subset, subset[i]->child_count, temp_btree->subset, temp_btree->child_count);

    T temp_item;

    detach_item(subset[i]->data, subset[i]->data_count, temp_item);
    insert_item(data, i+1, data_count, temp_item);

}


template<typename T>
void BTree<T>::loose_remove(const T& entry){

        /* four cases:
              a. leaf && not found target: there is nothing to do
              b. leaf && found target: just remove the target
              c. not leaf and not found target: recursive call to loose_remove
              d. not leaf and found: replace target with largest child of subset[i]

                 |   !found    |   found       |
           ------|-------------|---------------|-------
           leaf  |  a: nothing | b: delete     |
                 |     to do   |    target     |
           ------|-------------|---------------|-------
           !leaf | c: loose_   | d: replace    |
                 |    remove   |    w/ biggest |
           ------|-------------|---------------|-------


         */
    int i = find();
    bool found = data[i]==entry;
    int j = first_ge(data, data_count, entry);

    if(is_leaf() && !found){return;}
    else if(is_leaf() && found){
        delete_item(data, i, data_count, entry);
    }
    else if(!is_leaf() && !found){
        subset[i]->loose_remove(entry);
    }
    else if(!is_leaf() && found){
        int max_ind = index_of_maximal(subset[j]->data, subset[j]->data_count);
        T temp = subset[max_ind];
        delete_item(subset[j]->data, max_ind, subset[j]->data_count, entry);
        data[i] = temp;
    }


}


template<typename T>
void BTree<T>::fix_shortage(int i){
        /*
         * fix shortage in subtree i:
         * if child i+1 has more than MINIMUM, rotate left
         * elif child i-1 has more than MINIMUM, rotate right
         * elif there is a right child, merge child i with next child
         * else merge child i with left child
         */

    BTree<T> shallow_copy;
    copy_array(shallow_copy.data, data, shallow_copy.data_count, data_count);
    copy_array(shallow_copy.subset, subset, shallow_copy.child_count, child_count);

    clear_array(data, data_count);
    clear_array(subset, child_count);

    fix_excess(i);

}


template<typename T>
void BTree<T>::remove_biggest(T& entry){
        // Keep looking in the last subtree (recursive)
        //  until you get to a leaf.
        // Then, detach the last (biggest) data item
        //
        // after the recursive call, fix shortage.






}


template<typename T>
void BTree<T>::rotate_left(int i){
        /*
         * (0 < i < child_count) and (subset[i]->data_count > MINIMUM)
         * subset[i-1] has only MINIMUM - 1 entries.
         *
         * item transfers from child[i] to child [i-1]
         *
         * FIRST item of subset[i]->data moves up to data to replace data[i-1],
         * data[i-1] moves down to the RIGHT of subset[i-1]->data
         *
         *  i = 1:
         *              [50 100]
         *  [  ]        [65 75]       ....
         *            [a]  [b]  [c]
         *
         *  65 move up to replace 50 (data[i])
         *  65's child (its child 0) moves over to be the child of 50
         *  50 moves down to the right of subset[i]->data
         *
         *              [65 100]
         *  [50]         [ 75 ]       ....
         *     [a]      [b]  [c]
         *
         *
         *
         *
         */
        // If necessary, shift first subset of subset[i] to end of subset[i-1]
}


template<typename T>
void BTree<T>::rotate_right(int i){
        /* (i < child_count - 1) and (subset[i]->data_count > MINIMUM)
         * subset[i+ 1] has only MINIMUM - 1 entries.
         *
         * item transfers from child[i] to child [i+1]
         *
         * LAST item of subset[i]->data moves up to data to replace data[i],
         * data[i] moves down to the LEFT of subset[i+1]->data
         *
         * i = 1
         *                     [50 100]
         *      [20 30]        [65 75]          [ ]
         *  [..] [..] [..]   [a] [b] [c]        [..]
         *
         *  75 moves up to replace 100 (data[i])
         *  75's child (its last child) moves over to be the (child 0) child of 100
         *  100 moves down to subset[i]->data
         *
         *                     [50 75]
         *      [20 30]          [65]          [100]
         *  [..] [..] [..]     [a] [b]        [c] [..]
         *
         *
         *
         *
         *
         */
        // If necessary, shift last subset of subset[i] to front of subset[i+1]







}


template<typename T>
void BTree<T>::merge_with_next_subset(int i){
        /*
         *  Merge subset[i] with subset [i+1] with data[i] in the middle
         *
         *   1. remove data[i] from this object
         *   2. append it to child[i]->data
         *   3. Move all data items from subset[i+1]->data to subset[i]->data
         *   4. Move all subset pointers from subset[i+1]->subset to subset[i]->subset
         *   5. delete subset[i+1] (store in a temp ptr)
         *   6. delete temp ptr
         */









}



#endif // BTREE_H
