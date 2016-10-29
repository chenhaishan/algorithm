#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

void
init_graph(map<int, vector<int>> &graph, map<int, int> &indegree, int A[][7]){
    for(int i = 1; i < 8; ++i){
        for(int j = 1; j < 8; ++j){
            if(A[i-1][j-1] == 1){
                graph[i].push_back(j);
                indegree[j]++;
            }
        }
    }

    for(int i = 1; i < 8; ++i){
        if(indegree.find(i) == indegree.end())
            indegree[i] = 0;
    }
}

void
topsort(map<int, vector<int>> &graph, map<int, int> &indegree){
    queue<int> q;
    for(auto item:indegree){
        if(item.second == 0){
            q.push(item.first);
        }
    }
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        for(auto item : graph[vertex]){
            if(--indegree[item] == 0)
                q.push(item);
        }
        cout << vertex << endl;
    }
}

int main()
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

    map<int, vector<int>> graph;
    map<int, int> indegree;

    init_graph(graph, indegree, A);

    topsort(graph, indegree);

    return 0;
}
