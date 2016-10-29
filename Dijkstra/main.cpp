#include <iostream>
#include "BinaryHeap.h"
#include "graph.h"
using namespace std;

int main(int argc, char *argv[])
{
    int A[][7] = {
        /*1  2  3  4  5  6  7*/
    /*1*/{0, 2, 0, 1, 0, 0, 0},
    /*2*/{0, 0, 0, 3, 10, 0, 0},
    /*3*/{4, 0, 0, 0, 0, 5, 0},
    /*4*/{0, 0, 2, 0, 2, 8, 4},
    /*5*/{0, 0, 0, 0, 0, 0, 6},
    /*6*/{0},
    /*7*/{0, 0, 0, 0, 0, 1, 0}
    };
    Graph g(7, (int *)A);
    g.Dijkstra(1);
    return 0;
}
