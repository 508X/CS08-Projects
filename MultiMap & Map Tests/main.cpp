#include <iostream>
#include "map.h"
#include "../_includes/BTree/array_functions.h"
#include <vector>
#include <chrono>
#include <time.h>
#include <algorithm>
using namespace std;

vector<int> init_vector(int capacity);
void rand_vector(vector<int>& vect);
int Random(int lo, int hi);
void test_bplustree_auto(int tree_size, int how_many, bool report);
bool test_bplustree_auto(int how_many, bool report);
/*


*/

int main()
{
    srand(time(0));
    vector<string> strvect;
    static const int strsize = 50;
    int randint;
    string a[strsize] = {"Casca",
                    "Lina",
                    "Alex",
                    "Angel",
                    "Rei",
                    "Chen",
                    "Jovan",
                    "Katrina",
                    "Tamatha",
                    "Shin",
                    "Celia",
                    "Jenelle",
                    "Nelida",
                    "Kayleigh",
                    "Ava",
                    "Stepan",
                    "Grace",
                    "Debroah",
                    "Holley",
                    "Autumn",
                    "Tina",
                    "Yvone",
                    "Rebeca",
                    "Michiko",
                    "Misti",
                    "Nikia",
                    "Melanie",
                    "Lucilla",
                    "Lucina",
                    "Maya",
                    "Anna",
                    "Beatrice",
                    "Francisca",
                    "Eve",
                    "Kira",
                    "Soraya",
                    "Venita",
                    "Lacey",
                    "Marie",
                    "Marriam",
                    "Delilah",
                    "Moon",
                    "Mui",
                    "Lynn",
                    "Chyona",
                    "Ramona",
                    "Ula",
                    "Marquitta",
                    "Chia",
                    "Elvira"};
    vector<int> intvect;
    for(int i=0; i<strsize; i++){
//        cout<<"Push Back: "<<a[i]<<endl;
//        strvect.push_back(a[i]);
        intvect.push_back(i+1);
    }
//    for(int i=0; i<strsize; i++){
//        swap_arr(strvect[rand()%strsize], strvect[rand()%strsize]);
//        swap_arr(intvect[rand()%strsize], intvect[rand()%strsize]);
//    }
//    cout<<endl;
//    cout<<"Vector = { ";
//    for(size_t i=0; i<strsize; i++){
//        cout<<strvect[i];
//        if(i<strsize-1){
//            cout<<" ,";
//        }
//    }
//    cout<<"}"<<endl;
//    srand(time(0));
//    test_bplustree_auto(10, 1, 0);
//    cout<<endl;
//    BTree<Pair<int, string> > tree;
    BTree<int> tree;
    bool run_interactive = 1;
// sorts btrees, removes, inserts
//
//    cout<<"------------------------- Tree -------------------------"<<endl;
//    cout<<tree<<endl;

//    for(int i=0; !strvect.empty(); i++){
//        string temp = strvect[strvect.size()-1];
//        strvect.pop_back();
//        int tmp = intvect[strvect.size()-1];
//        intvect.pop_back();
////        cout<<"Pushing Into BTree: "<<temp<<endl;
//        tree.insert(Pair<int, string>(tmp, temp));
////        cout<<"------------------------- Tree -------------------------"<<endl;
////        cout<<tree<<endl;
//    }

    if(run_interactive){

        bool done = false;
        char choice;
        int* temp;
//        Pair<int, string>* temp;
//        int val;
        Pair<int, string> val;
        string strtemp;
        int inttmp;
        while(!done){

//            system("CLS");
//            cout<<flush;

        cout<<endl<<"------------------------- Tree -------------------------"<<endl<<endl;
        cout<<tree<<endl;
        cout<<"==========================="<<endl;
        cout<<"[I]nsert [R]emove [C]lear [F]ind e[X]it :>>";
        cin>>choice;
        switch(tolower(choice)){

        case 'k':
//        if(!strvect.empty() && !intvect.empty()){
//            strtemp = strvect[strvect.size()-1];
//            strvect.pop_back();

//            inttmp = intvect[intvect.size()-1];
//            intvect.pop_back();
//            tree.insert(Pair<int, string>(inttmp, strtemp));
            tree.insert(rand()%100+1);
//        }
            break;
        case 'i':
            cout<<">>:";
            cin>>randint;
//            cin>>val;
//            cout<<"Inserting: "<<val<<endl;
//            tree.insert(val);
            tree.insert(randint);
            break;
        case 's':
            cout<<"Size = "<<tree.size()<<endl;
            break;
        case 'r':
            cout<<">>:";
            cin>>randint;
//            cin>>inttmp;
//            tree.remove(Pair<int,string>(inttmp));
            tree.remove(randint);
            break;
        case 'c':
            tree.clear_tree();
            break;
        case 'f':
            cout<<":>>";
            cin>>randint;
            temp = tree.find(randint);
//            cin>>val;
//            temp = tree.find(val);
            if(temp!=nullptr){
                cout<<"Found! I = "<<*temp<<endl;
            }
            else{
                cout<<"Not found"<<endl;
            }
            break;
        case 'x':
            done = true;
            break;





        }





        }
        //while(!done);
    }
    else{
        test_bplustree_auto(1000, 100, 0);
    }




//    cout<<test_tree<<endl;

//    for(int i=0; i<100; i++){
//        test_tree.insert(i);
//    }

//    cout<<test_tree<<endl;

//    for(int i=0; i<50; i++){
//        test_tree.remove(i);
//    }

//    cout<<test_tree<<endl;

//    if(test_tree.is_valid()){
//        cout<<"VALID TREE"<<endl;

//    }
//    else{
//        cout<<"INVALID TREE"<<endl;
//    }

/*
//    cout<<"Inserting: 15"<<endl;
//    test_tree.insert(15);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 55"<<endl;
//    test_tree.insert(55);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 90"<<endl;
//    test_tree.insert(90);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 43"<<endl;
//    test_tree.insert(43);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 98"<<endl;
//    test_tree.insert(98);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 2"<<endl;
//    test_tree.insert(2);
//    cout<<test_tree<<endl;


//    cout<<"Inserting: 42"<<endl;
//    test_tree.insert(42);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 59"<<endl;
//    test_tree.insert(59);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 1"<<endl;
//    test_tree.insert(1);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 3"<<endl;
//    test_tree.insert(3);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 100"<<endl;
//    test_tree.insert(100);
//    cout<<test_tree<<endl;

//    cout<<"Inserting: 84"<<endl;
//    test_tree.insert(84);
//    cout<<test_tree<<endl;

//    cout<<endl<<"-----------------------------------------------"<<endl;

//    cout<<"Deleting: 90"<<endl;
//    test_tree.remove(90);
//    cout<<test_tree<<endl;

//    cout<<"deleting: 98"<<endl;
//    test_tree.remove(98);
//    cout<<test_tree<<endl;

//    cout<<"deleting: 3"<<endl;
//    test_tree.remove(3);
//    cout<<test_tree<<endl;

//    cout<<"deleting: 55"<<endl;
//    test_tree.remove(55);
//    cout<<test_tree<<endl;

//    cout<<"deleting: 43"<<endl;
//    test_tree.remove(43);
//    cout<<test_tree<<endl;

//    cout<<"deleting: 42"<<endl;
//    test_tree.remove(42);
//    cout<<test_tree<<endl;




//    Map<int, string> map;
//    cout<<"Inserting Lain"<<endl;
//    map.insert(42, "Lain");
//    cout<<"Inserting Venus"<<endl;
//    map.insert(66, "Venus");
//    cout<<"Inserting Hayden"<<endl;
//    map.insert(29, "Hayden");


//    cout<<map<<endl;

//    cout<<"Map -> get id:42"<<endl;
//    cout<<"ID:42 -> "<<map[42]<<endl;

//    cout<<"Map -> get id:66"<<endl;
//    cout<<"ID:66 -> "<<map[66]<<endl;

//    cout<<"Map -> get id:29"<<endl;
//    cout<<"ID:29 -> "<<map[29]<<endl;


//    int size = 1;
//    int a[10] = {90};
//    cout<<"Place: "<<first_ge(a, size, 43)<<endl;

//    ordered_insert(a, size, 43);

//    print_array(a, size);

//    cout<<endl<<endl;
//    int bsize = 8;
//    int b[20] = {1,4,7,19,22,54,78,99};

//    cout<<" ";
//    for(int i=0; i<bsize; i++){
//        cout<<"["<<b[i]<<"] ";
//    }
//    cout<<endl;
//    for(int i=0; i<bsize+1; i++){
//        cout<<"["<<i<<"] ";
//    }
//    cout<<endl;

//    cout<<"want to remove 29, place = "<<first_ge(b, bsize, 29)<<endl
//    <<"want to remove 12, place = "<<first_ge(b, bsize, 12)<<endl
//    <<"want to remove 17, place = "<<first_ge(b, bsize, 17)<<endl
//    <<"want to remove 98, place = "<<first_ge(b, bsize, 98)<<endl
//    <<"want to remove 2, place = "<<first_ge(b, bsize, 2)<<endl
//    <<"want to remove 0, place = "<<first_ge(b, bsize, 0)<<endl
//    <<"want to remove -4, place = "<<first_ge(b, bsize, -4)<<endl

//    <<"want to remove 7, place = "<<first_ge(b, bsize, 7)<<endl
//    <<"want to remove 78, place = "<<first_ge(b, bsize, 78)<<endl
//    <<"want to remove 19, place = "<<first_ge(b, bsize, 19)<<endl
//    <<"want to remove 1, place = "<<first_ge(b, bsize, 1)<<endl;

*/

    return 0;
}

vector<int> init_vector(int capacity){
    vector<int> vect;
    for(int i=0; i<capacity; i++){
        vect.push_back(i);
    }
}
void rand_vector(vector<int>& vect){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(vect.begin(), vect.end(), default_random_engine(seed));
}




void test_bplustree_auto(int tree_size, int how_many, bool report){
    bool verified = true;
    for (int i = 0; i< how_many; i++){
        if (report){
            cout<<"*********************************************************"<<endl;
            cout<<" T E S T:    "<<i<<endl;
            cout<<"*********************************************************"<<endl;
        }
        if (!test_bplustree_auto(tree_size, report)){
            cout<<"T E S T :   ["<<i<<"]    F A I L E D ! ! !"<<endl;
            verified = false;
            return;
        }

    }
    cout<<"**************************************************************************"<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"             E N D     T E S T: "<<how_many<<" tests of "<<tree_size<<" items: ";
    cout<<(verified?"VERIFIED": "VERIFICATION FAILED")<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"**************************************************************************"<<endl;

}

bool test_bplustree_auto(int how_many, bool report){
    const int MAX = 10000;
    assert(how_many < MAX);
    BTree<int> bpt;
    int a[MAX];
    int original[MAX];
    int deleted_list[MAX];

    int original_size;
    int size;
    int deleted_size = 0;

    //fill a[ ]
    for (int i= 0; i< how_many; i++){
        a[i] = i;
    }
    //shuffle a[ ]: Put this in a function!
    for (int i = 0; i< how_many; i++){
        int from = Random(0, how_many-1);
        int to = Random(0, how_many -1);
        int temp = a[to];
        a[to] = a[from];
        a [from] = temp;
    }
    //copy  a[ ] -> original[ ]:
    copy_array(original, a, how_many, size);
    size = how_many;
    original_size = how_many;
    for (int i=0; i<size; i++){
        bpt.insert(a[i]);
    }
    if (report){
        cout<<"========================================================"<<endl;
        cout<<"  "<<endl;
        cout<<"========================================================"<<endl;
        cout<<bpt<<endl<<endl;
    }
    for (int i= 0; i<how_many; i++){
        int r = Random(0, how_many - i - 1);
        if (report){
            cout<<"========================================================"<<endl;
            cout<<bpt<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . "<<endl;
            cout<<"deleted: "; print_array(deleted_list, deleted_size);
            cout<<"   from: "; print_array(original, original_size);
            cout<<endl;
            cout<<"  REMOVING ["<<a[r]<<"]"<<endl;
            cout<<"========================================================"<<endl;
        }
        bpt.remove(a[r]);


        delete_item(a, r, size, deleted_list[deleted_size++]);
        if (!bpt.is_valid()){
            cout<<setw(6)<<i<<" I N V A L I D   T R E E"<<endl;
            cout<<"Original Array: "; print_array(original, original_size);
            cout<<"Deleted Items : "; print_array(deleted_list, deleted_size);
            cout<<endl<<endl<<bpt<<endl<<endl;
            return false;
        }

    }
    if (report) cout<<" V A L I D    T R E E"<<endl;

    return true;
}
int Random(int lo, int hi)
{
    int r = rand()%(hi-lo+1)+lo;

    return r;
}






