#include "graph.h"
#include "BinaryHeap.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

Graph::Graph(const int sz, const int* A)
    :graph(sz)
{
    for(int i = 0; i < sz; ++i){
        graph[i].v = i+1;
        for(int j = 0; j < sz; ++j){
            if(*(A+i*sz+j)){
                graph[i].u[j+1] = *(A+i*sz+j);
                ++graph[j].indegree;
            }
        }
    }
}

void Graph::topsort(){
    queue<int> q;//queue<int> should work too

    int count = 0;
    for(int i = 0; i != graph.size(); ++i){
        if(! graph[i].indegree)
            q.push(i);
    }

    while(! q.empty()){
        auto vertex = q.front();
        cout<<graph[vertex].v<<endl;
        q.pop();
        graph[vertex].topnum = ++count;

        for(int i = 0; i < graph[vertex].u.size(); ++i){
            if(--graph[graph[vertex].u[i] - 1].indegree == 0)
                q.push(graph[vertex].u[i] - 1);
        }
    }

    if(count != graph.size())
    {
        /*should be throw exception*/
        cout<<"not a DAG"<<endl;

    }
    else{
        for(auto itr = graph.begin(); itr != graph.end(); ++itr){
            cout<<itr->v<<":"<<itr->topnum<<endl;
        }
    }
}

void Graph::Dijkstra(int vertex){
    graph[vertex-1].table.dv = 0;
    BinaryHeap<Vertex> bhv;
    bhv.insert(graph[vertex-1]);
    int count = graph.size();

    while(count --){
        //auto min  = const_cast<Vertex *>(bhv.findMin());
        auto min = bhv.findMin();
        //min.table.known = true;
        graph[min.v-1].table.known = true;
        for(auto p = min.u.begin(); p != min.u.end(); ++p){
            if(!graph[p->first - 1].table.known){
                if(graph[p->first-1].table.dv > (p->second + min.table.dv)){
                    graph[p->first-1].table.dv = p->second + min.table.dv;

                    graph[p->first-1].table.pv = min.table.pv;
                    graph[p->first-1].table.pv.push_back(min.v);

                    bhv.insert(graph[p->first-1]);
                }

            }
        }
        /*
        cout<<min.v<<":"<<min.table.dv<<" path:";
        for(auto p : min.table.pv)
            cout<<p<<" ";
        cout<<endl;
        */
        cout<<min;
        bhv.deleteMin();
    }

}
