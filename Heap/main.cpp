#include <iostream>
#include "pqueue.h"
using namespace std;

int main()
{




    PQueue<int> pq;
    for (int i = 0; i<100; i++){
//        if(i%4==0){
//            cout<<pq<<endl;
//        }
        pq.insert(rand()%1000+1, rand()%1000+1);
    }
    cout<<pq<<endl;
    return 0;
}
