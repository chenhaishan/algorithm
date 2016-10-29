#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

/*
 * sustain a state table
 * --------------------
 * |vertex|known|dv|pv
 * --------------------
 * |  v1  |false|-1|
 * --------------------
 * |  v2  |false|-1|
 * --------------------
 * |  v3  |false|-1|
 * --------------------
 * |  v4  |false|-1|
 * --------------------
 * |  v5  |false|-1|
 * --------------------
 * |  v6  |false|-1|
 * --------------------
 * |  v7  |false|-1|
 * --------------------
 *
 * if 'known' is true, means 'vi' 's path is determined.
 * 'dv' is distance to 'start'
 * 'pv' records path from 'start' to 'vi'
*/


struct ST{
    bool known;
    unsigned int dv;
    vector<int> pv;
    ST():known(false),dv(-1){}
};

void
init_graph(map<int, vector<int>> &graph, int A[][7]){
    for(int i = 1; i < 8; ++i){
        for(int j = 1; j < 8; ++j){
            if(A[i-1][j-1] == 1){
                graph[i].push_back(j);
            }
        }
    }
}

/*
 * push 'known' vertex into queue.
 * pop one vertex 'vi' out, update all edges
 * (vi, vj)'s 'dv'.
*/
void
unweighted_sort(map<int, vector<int>> &graph, ST *st, int start){
    //auto sz = graph.size();
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        (st[vertex]).known = true;
        for(auto item : graph[vertex]){
            if(!st[item].known  && st[item].dv > (st[vertex].dv + 1)){
                st[item].dv = st[vertex].dv + 1;
                st[item].pv = st[vertex].pv;
                st[item].pv.push_back(vertex);
                q.push(item);
            }
        }
        //cout << vertex << endl;
    }
}

void
print_path(const ST *st, int len){
    for(int i = 1; i < len; ++i){
        cout << i << ":";
        for(auto item : st[i].pv){
            cout << item << " ";
        }
        cout << endl;
    }
}

int main()
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

    /*
     * 'Graph' contains vertexs and edges.
     * vertex 'vi' has some 'edge' to other vertex 'vj'.
    */
    map<int, vector<int>> graph;
    ST state_table[8];
    int start;

    cout << "input start:" << endl;
    cin >> start;

    if(start<1 || start > 8){
        cout << "outof boundry!" << endl;
        return 0;
    }

    /*
     * 'start' is 'known', and 'dv' is 0.
     * 'pv' is empty.
    */
    state_table[start].known = true;
    state_table[start].dv = 0;

    init_graph(graph, A);

    unweighted_sort(graph, state_table, start);

    print_path(state_table, 8 );
    return 0;
}
