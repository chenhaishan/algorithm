#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
using namespace std;
class Graph
{
private:
    class Vertex{
        friend class Graph;
    private:
        int v;
        vector<int> u;

        int indegree;
        int topnum;
        struct Table{
            bool known;
            unsigned int dv;
            vector<int> pv;
            Table():known(false),dv(-1){}
        };

        Table table;

    public:
        Vertex()=default;
    };

    vector<Vertex> graph;

public:
    Graph(const int, const int*);
    void topsort();
    void weightless_shortest_path(int);
};

#endif // GRAPH_H
