#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Graph
{
private:
    class Vertex{
        friend class Graph;
        friend ostream & operator<< (ostream &os, const Vertex &rhs){
            os<<"vertex["<<rhs.v<<"]: dv="<<rhs.table.dv<<",pv=";
            for(auto p : rhs.table.pv){
                os<<p<<" ";
            }
            os<<endl;
            return os;
        }
    private:
        int v;
        map<int, unsigned int> u;\

        struct Table{
            bool known;
            unsigned int dv;
            vector<int> pv;
            Table():known(false), dv(-1){}
        };
        Table table;
        int indegree;
        int topnum;
    public:
        Vertex()=default;
        bool operator< (const Vertex &rhs) const {
            return table.dv < rhs.table.dv;
        }
        bool operator> (const Vertex &rhs) const {
            return table.dv > rhs.table.dv;
        }

    };

    vector<Vertex> graph;

public:
    Graph(const int, const int*);
    void topsort();
    void Dijkstra(int);
};

#endif // GRAPH_H
