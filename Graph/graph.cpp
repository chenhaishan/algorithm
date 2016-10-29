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
