#include <iostream>
#include "graph.h"
using namespace std;

int main(int argc, char *argv[])
{
    int A[][7] = {
        /*1  2  3  4  5  6  7*/
    /*1*/{0, 1, 0, 1, 0, 0, 0},
    /*2*/{0, 0, 0, 1, 1, 0, 0},
    /*3*/{1, 0, 0, 0, 0, 1, 0},
    /*4*/{0, 0, 1, 0, 1, 1, 1},
    /*5*/{0, 0, 0, 1, 0, 0, 1},
    /*6*/{0},
    /*7*/{0, 0, 0, 0, 0, 1, 0}
    };
    Graph g(7, (int *)A);
    g.topsort();

    g.weightless_shortest_path(3);
    return 0;
}
