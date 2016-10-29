#include <iostream>
#include <vector>
#include "vertex.h"
using namespace std;


int main(int argc, char *argv[])
{
    int A[7][7] = {
           /*1  2  3  4  5  6  7*/
       /*1*/{0, 1, 1, 1, 0, 0, 0},
       /*2*/{0, 0, 0, 1, 1, 0, 0},
       /*3*/{0, 0, 0, 0, 0, 1, 0},
       /*4*/{0, 0, 1, 0, 0, 1, 1},
       /*5*/{0, 0, 0, 1, 0, 0, 1},
       /*6*/{0},
       /*7*/{0, 0, 0, 0, 0, 1, 0}
    };
    vector<Vertex> graph(sizeof(A[0])/sizeof(A[0][0]));
    init_graph((int*)A, graph);

    print_graph(graph);

    topologic_sort(graph);
    return 0;
}
