#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct ST{
    bool known;
    unsigned int dv;
    vector<int> pv;
    ST():known(false),dv(-1){}
};

void
init_graph(map<int, vector<pair<int,int>>> &graph, int A[][7]){
    for(int i = 1; i < 8; ++i){
        for(int j = 1; j < 8; ++j){
            if(A[i-1][j-1] != 0){
                graph[i].push_back(make_pair(j, A[i-1][j-1]));
            }
        }
    }
}

int findmin_vertex(const ST *st, const int len){
    int ret = -1,i;
    for(i= 1; i <=len; ++i){
        if(!st[i].known){
            ret = i;
            break;
        }
    }
    for(;i <= len; ++i){
        if(!st[i].known && st[i].dv < st[ret].dv)
            ret = i;
    }
    return ret;
}

void Dijkstra(map<int, vector<pair<int, int>>> &graph, ST *st, int start){
    const auto len = graph.size();
    queue<int> q;
    int vertex = start;
    while(1){
        st[vertex].known = true;
        for(auto item : graph[vertex]){
            if(!st[item.first].known &&
               st[item.first].dv > st[vertex].dv+item.second){
                st[item.first].dv = st[vertex].dv + item.second;
                st[item.first].pv.clear();
                st[item.first].pv = st[vertex].pv;
                st[item.first].pv.push_back(vertex);
            }
        }
        if((vertex=findmin_vertex(st, len)) == -1)
            break;
    }
}

void
print_path(const ST *st, int len){
    for(int i = 1; i < len; ++i){
        cout << i << ":";
        for(auto item : st[i].pv){
            cout << item << " ";
        }
        cout << " cost:"<<st[i].dv<<endl;
    }
}

int main()
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

    //vertex vi to vj has 'edge' and 'cost' (vi,(vj,cij)).
    map<int, vector<pair<int, int>>> graph;
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

    Dijkstra(graph, state_table, start);

    print_path(state_table, 8);

    return 0;
}
