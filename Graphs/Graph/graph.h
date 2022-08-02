#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cstdlib>
#include <set>
#include <cmath>
#include <iomanip>
#include <limits.h>
#include "../../_includes/Queue/queue.h"
#include "twod.h"

const static double infinity = INFINITY;

using namespace std;

template <typename T>
T* resize1(T*  oned, int size, int cap);
void print_int_line(int k);
int shortest_dist(int* dist, bool* visited, int many_verticies);

template <typename T>
class graph {
public:

    graph()
        :many_vertices(0)
    {

        allocated = 5;

        edges = twod<int>(allocated);
        labels = new T[allocated];

        for(int i=0; i<allocated; i++){
            labels[i] = 'A'+i;
        }



    }
    graph(size_t vert)
        :many_vertices(vert)
    {

        allocated = many_vertices;

        edges = twod<int>(allocated);
        labels = new T[allocated];

        for(int i=0; i<allocated; i++){
            labels[i] = i;
        }

    }

    void    add_vertex(const T& label){
        std::size_t new_vertex_number;
        std::size_t other_number;

        if(many_vertices+1>allocated){

//            edges = resize(edges, many_vertices, allocated);
//            edges.reallocate_2d(many_vertices, allocated);
            edges.resize(many_vertices, allocated);
            labels = resize1(labels, many_vertices, allocated);

        }

        new_vertex_number = many_vertices;
        ++many_vertices;
        for(other_number=0; other_number<many_vertices; ++other_number){
            edges[other_number][new_vertex_number] = 0;
            edges[new_vertex_number][other_number] = 0;
        }
        labels[new_vertex_number] = label;

    }
    void    add_edge(size_t source, size_t target, size_t weight = 1){
        assert(source<size());
        assert(target<size());

        edges[source][target] = weight;
    }
    void    remove_edge(size_t source, size_t target){
        assert(source<size());
        assert(target<size());
        edges[source][target] = 0;
    }
    T&      operator [](size_t vertex){
        assert(vertex<size());
        return labels[vertex];
    }

    size_t size() const{
        return many_vertices;
    }
    bool is_edge(size_t source, size_t target) const{
        assert(source<size());
        assert(target<size());
        return edges[source][target];
    }
    set<size_t> neighbors(size_t vertex) const{
        set<size_t> answer;
        size_t i;
        assert(vertex<size());
        for(i=0; i<size(); ++i){
            if(edges[vertex][i])
                answer.insert(i);
        }
        return answer;
    }
    T operator [](size_t vertex) const{
        assert(vertex<size());
        return labels[vertex];
    }
    bool find_link(int start, int end){
        depth_first_search(print_int_line, *this, start, end);
//        breadth_first(print_int_line, *this, start);
    }
    int shortest_dist2(bool* visited, int* distances, int many_vertices){
        int min_weight = INFINITY;
        int min_index;
        for(int i = 0; i<many_vertices; i++){

            set<size_t> tempset = neighbors(i);
            set<size_t>::iterator set_iter = tempset.begin();
            int j=0;
            while(j<tempset.size()){
                cout<<"Reading: "<<*set_iter<<endl;
                /*if it has not been visited and is currently
                smaller than min, set it as minimum value
                and keep track of node index*/
                if(visited[*set_iter]==false && distances[*set_iter]<=min_weight){
                    min_weight = distances[*set_iter];
                    min_index = *set_iter;
                }
                set_iter++;
                j++;
            }
        }
        return min_index;

    }
    int shortest_dist(int* distances, bool* visited, int many_vertices){
        assert(many_vertices>0);
        // Initialize min value
        int min_weight = INFINITY;
        int min_index;

        for (int i = 0; i < many_vertices; i++){
            /*if it has not been visited and is currently
            smaller than min, set it as minimum value
            and keep track of node index*/
            if(visited[i]==false && distances[i]<=min_weight){
                min_weight = distances[i];
                min_index = i;
            }
        }
        return min_index;
    }
    void dijkstra(int source_vertex){

        int distances[many_vertices];
        bool visited[many_vertices];
        int sequence[many_vertices];


        /* (1) */
        /* Initialize all arrays */
        for (int i=0; i<many_vertices; i++) {
                distances[i] = INFINITY,
                visited[i] = 0;
        }

        distances[source_vertex] = 0;
        sequence[source_vertex] = 0;

        /* Now pick the vertex with minimum distance value
         *  that hasnt been visited, this will be list.pop() */



        for(int i=0; i<many_vertices-1; i++){
            /* Get the smallest non-visited vertex */
//            size_t smallest_vertex = shortest_dist2(visited, distances, many_vertices);
            size_t smallest_vertex = shortest_dist(distances, visited, many_vertices);
            /* set it to visited */
            visited[smallest_vertex] = true;


            /* run through the list of non-visited verticies
            and ->  */
            for(int j=0; j<many_vertices; j++){
                /* if the node is not visited,
                 * the node is an edge,
                 * and its current distance is less
                 *      than the current recorded one,
                 *      then replace it */
                if(!visited[j]  &&
                   is_edge(i,j)    &&
                   edges[i][j] + distances[i] < distances[j])
                   {
                    /* replace the current vertex with the new smaller vertex */
                    distances[j] = edges[i][j] + distances[i];
                    /* replace the node in sequence with the shortest path node */
                    sequence[j] = smallest_vertex;
                }
            }
        }
        cout<<endl;
        cout<<"     Node     Distance    From"<<endl;
        for (int i = 0; i < many_vertices; i++){
            cout<<setw(5)<<""<<i;

            if(distances[i]<INT_MAX && distances[i]>=0){
                cout<<setw(10)<<distances[i]<<""<<setw(5)<<"";
            }
            else{
                cout<<setw(10)<<"X"<<setw(5)<<"";
            }


            if((sequence[i]>=0 && sequence[i]<many_vertices)){
                cout<<setw(7)<<sequence[i];
            }
            else{
                cout<<setw(7)<<"X";
            }
            cout<<endl;
        }
    }
    void print(){
        cout<<"---Graph---"<<endl;
        cout<<"  ";
        for(int i=0; i<many_vertices; i++){
            cout<<" "<<i;
        }
        cout<<endl;
        for(int i=0; i<many_vertices; i++){
            cout<<i<<" ";
            for(int j=0; j<many_vertices; j++){
                cout<<"|"<<edges[i][j];
            }
            cout<<endl;
        }

        cout<<endl;

    }

private:

    twod<int> edges;
    T* labels;

    size_t allocated;

    size_t many_vertices;

};

void print_int_line(int k){
    cout<<"->("<<k<<")";
}

template <class Process, class Item, class SizeType>
void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[]);
template <class Process, class Item, class SizeType>
void depth_first(Process f, graph<Item>& g, SizeType start);
template <class Process, class Item, class SizeType>
void breadth_first(Process f, graph<Item>& g, SizeType start);

template <class Process, class Item, class SizeType>
void rec_dfs_search(Process f, graph<Item>& g, SizeType start, SizeType find_me, bool marked[]);
template <class Process, class Item, class SizeType>
void depth_first_search(Process f, graph<Item>& g, SizeType start, SizeType end);
template <class Process, class Item, class SizeType>
void breadth_first_search(Process f, graph<Item>& g, SizeType start, SizeType end);

template <class Process, class Item, class SizeType>
void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[]){
    set<size_t> connections = g.neighbors(v);
    set<size_t>::iterator it;
    marked[v] = true;
    f(g[v]);
    for(it = connections.begin(); it != connections.end(); ++it){
        if(!marked[*it])
            rec_dfs(f, g, *it, marked);
    }
}
template <class Process, class Item, class SizeType>
void depth_first(Process f, graph<Item>& g, SizeType start){
    bool marked[g.size()];
    assert(start<g.size());
    std::fill_n(marked, g.size(), false);
    rec_dfs(f, g, start, marked);
}
template <class Process, class Item, class SizeType>
void breadth_first(Process f, graph<Item>& g, SizeType start){


    bool marked[g.MAXIMUM]; std::set<std::size_t> connections;
    set<size_t>::iterator it;
    Queue<size_t> vertex_queue;
    assert(start < g.size( ));
    std::fill_n(marked, g.size( ), false);
    marked[start] = true; f(g[start]);
    vertex_queue.push(start);
    do{
        connections = g.neighbors(vertex_queue.pop());
        // Mark and process the unmarked neighbors, and place them in the queue.
        for (it = connections.begin( ); it != connections.end( ); ++it){
            if (!marked[*it]){
                marked[*it] = true;
                f(g[*it]);
                vertex_queue.push(*it);
            }
        }
    }while(!vertex_queue.empty());


}




template <class Process, class Item, class SizeType>
void rec_dfs_search(Process f, graph<Item>& g, SizeType start, SizeType find_me, bool marked[]){
//    set<size_t> connections = g.neighbors(v);
//    set<size_t>::iterator it;
//    marked[v] = true;
//    f(g[v]);
//    for(it = connections.begin(); it != connections.end(); ++it){
//        if(!marked[*it])
//            rec_dfs(f, g, *it, marked);
//    }
    set<size_t> neigh = g.neighbors(start);
    set<size_t>::iterator set_iter;

    marked[start] = 1;
    f(g[start]);
    for(set_iter = neigh.begin(); set_iter != neigh.end(); ++ set_iter){

        if(!marked[*set_iter]){
            rec_dfs_search(f, g, start, find_me, marked);
//            rec_dfs_search(f, g, *set_iter, find_me, marked);
        }
    }

}
template <class Process, class Item, class SizeType>
void depth_first_search(Process f, graph<Item>& g, SizeType start, SizeType end){
    bool marked[end];
    assert(start<g.size());
    assert(end<g.size());

    std::fill_n(marked, end, false);
    rec_dfs_search(f, g, start, end, marked);
}
template <class Process, class Item, class SizeType>
void breadth_first_search(Process f, graph<Item>& g, SizeType start, SizeType end){

}





template <typename T>
T** resize2(T** twod, int size, int& cap){

    cap+=1;

    T** temp = new T*[cap];

    for(int i(0); i<cap; i++){
        for(int j(0); i<cap; j++){
            if(j<size && i<size){
                temp[i][j] = twod[i][j];
            }
            else{
                temp[i][j] = 0;
            }
        }
    }

    for(int i=0; i<cap/2; i++){
        delete [] temp[i];
    }

    return temp;

}
template <typename T>
T* resize1(T* oned, int size, int cap){

    T* temp = new T[cap];
    for(int i(0); i<cap; i++){
        if(i<size)
            temp[i] = oned[i];
        else
            temp[i] = T();
    }
    delete [] oned;
    return temp;
}









//    }
#endif // GRAPH_H
