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
    public:
        Vertex()=default;
    };

    vector<Vertex> graph;

public:
    Graph(const int, const int*);
    void topsort();
};

#endif // GRAPH_H
