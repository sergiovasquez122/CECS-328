#include <iostream>
#include <queue>
#include "Graph.h"

using namespace std;

void dfs(const Graph& G, deque<bool>& visited, int current, int parent, bool& has_cycle){
    visited[current] = true;
    for(int x : G.adj(current)){
        if(!visited[x]){
            dfs(G, visited, x, current, has_cycle);
        } else if(x != parent){
            has_cycle = true;
        }
    }
}

bool contains_cycle(const Graph& G){
    deque<bool> visited(G.V());
    deque<bool> on_stack(G.V());
    bool has_cycle = false;
    for(int i = 0;i < G.V();i++)
        if(!visited[i]) dfs(G, visited, i, i, has_cycle);
    return has_cycle;
}

int main() {
    Graph G(3);
    G.addEdge(0, 1);
    cout << contains_cycle(G) << endl;
    G.addEdge(0, 2);
    cout << contains_cycle(G) << endl;
    G.addEdge(1, 2);
    cout << contains_cycle(G) << endl;
}
