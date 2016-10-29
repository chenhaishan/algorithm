 #include "graph.h"
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
                graph[i].u.push_back(j+1);
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
        //return -1;
    }
    else{
        for(auto itr = graph.begin(); itr != graph.end(); ++itr){
            cout<<itr->v<<":"<<itr->topnum<<endl;
        }
    }
}

void Graph::weightless_shortest_path(int vertex){
    queue<int> q;
    q.push(vertex-1);

    graph[vertex-1].table.known = true;
    graph[vertex-1].table.dv = 0;

    while(! q.empty()){
        auto i = q.front();
        q.pop();

        for(auto j = graph[i].u.begin(); j != graph[i].u.end(); ++j){

            if(graph[*j - 1].table.known)continue;
            q.push(*j -1);
            graph[*j - 1].table.known = true;
            graph[*j - 1].table.dv =graph[i].table.dv +1;
            graph[*j - 1].table.pv = graph[i].table.pv;
            graph[*j - 1].table.pv.push_back(i+1);
        }

    }

    for(int i = 0; i < graph.size(); ++i){
        cout<<"graph["<<i+1<<"] distance from graph["<<vertex<<"]is:"<<graph[i].table.dv<<",and shortest path is:";
        for(int j = 0; j < graph[i].table.pv.size(); ++j){
            cout<<graph[i].table.pv[j]<<" ";
        }
        cout <<i+1<<endl;
    }
}
