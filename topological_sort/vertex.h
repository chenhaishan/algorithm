#ifndef VERTEX_H
#define VERTEX_H
#include <vector>

using namespace std;



class Vertex
{
    friend void init_graph(const int *A, vector<Vertex> &graph);
    friend void print_graph(const vector<Vertex> &graph);
    friend void topologic_sort(vector<Vertex> g);
private:
    unsigned int v;//vertex v
    vector<unsigned int> u;//edge (v, u)
    int indegree;//number of edge (u1, v)
public:
    //size of u must be small enough because the graph is sparse.
    Vertex():u(5){}

};

void init_graph(const int *A, vector<Vertex> &graph);
void print_graph(const vector<Vertex> &graph);
void topologic_sort(vector<Vertex> g);
#endif // VERTEX_H
