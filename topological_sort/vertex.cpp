#include "vertex.h"
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void init_graph(const int *A, vector<Vertex> &graph){
    int i =0, j=0;
    const int sz = (int)graph.size();
    for(;i<sz;++i){
        graph[i].v = i+1;
        for(j=0; j<sz; ++j){
            if(*(A + i*sz +j)){
                graph[i].u.push_back(j+1);
                ++graph[j].indegree;

            }
        }
    }
}

void print_graph(const vector<Vertex> &graph){
    const int sz = (int)graph.size();
    for(int i = 0; i<sz; ++i){
        cout<<"graph["<<i+1<<"]:"<<endl;
        cout<<"indegree:"<<graph[i].indegree<<endl;
        cout<<"adjecent vertex:";
        for(int j = 0; j< graph[i].u.size(); ++j){
            cout<<graph[i].u[j]<<" ";
        }
        cout<<endl;
    }
}
/*
int find_zero_indegree(const vector<Vertex> &graph){
    const int sz = graph.size();
    for(int i = 0; i< sz; ++i){
        if(!graph[i].indegree)
            return i;
    }
}
*/
void topologic_sort(vector<Vertex> graph){
    int count = graph.size();
    while(count){
        for(auto i = graph.begin(); i != graph.end(); ++i){
            if(! i->indegree){
                for(int j = 0; j < i->u.size(); ++j){
                    --graph[i->u[j]-1].indegree;
                }
                cout<<i->v<<" "<<endl;
                //graph.erase(i);
                i->indegree = -1;
                --count;
                break;
            }
        }
    }
    print_graph(graph);
}
