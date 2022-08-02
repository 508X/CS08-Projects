#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    graph<int> g(6);

    cout<<"(0)->(1)"<<endl;
    g.add_edge(0,1, 2);
    g.print();

    cout<<"(1)->(2)"<<endl;
    g.add_edge(1,2, 7);
    g.print();

    cout<<"(2)->(3)"<<endl;
    g.add_edge(2,3, 3);
    g.print();

    cout<<"(2)->(4)"<<endl;
    g.add_edge(2,4, 9);
    g.print();

    cout<<"(4)->(5)"<<endl;
    g.add_edge(4,5, 5);
    g.print();

    cout<<"+(6)"<<endl;
    g.add_vertex(6);
    g.print();

    cout<<"+(7)"<<endl;
    g.add_vertex(7);

    cout<<"added 2 new verticies, graph reallocated twice here"<<endl;
    g.print();

    cout<<"Dijkstra of Node: 0"<<endl;
    g.dijkstra(0);
    cout<<endl<<endl;

    cout<<"Dijkstra of Node: 2"<<endl;
    g.dijkstra(2);

//    cout<<endl;
//    cout<<"Search from 2"<<endl;
//    g.find_link(2,4);
    cout<<endl<<"---------------------------------------------------------"<<endl;
    cout<<endl<<endl;

    return 0;
}
