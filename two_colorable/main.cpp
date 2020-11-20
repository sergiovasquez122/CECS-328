#include <iostream>
#include <queue>
#include "Graph.h"

using namespace std;

bool two_colorable(const Graph& G){
    deque<bool> visited(G.V());
    deque<bool> color(G.V());
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int x : G.adj(curr)){
            if(!visited[x]){
                visited[x] = true;
                color[x] = !color[curr];
                q.push(x);
            } else if(color[x] == color[curr]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    Graph G(7);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(0, 4);
    G.addEdge(0, 5);
    cout << two_colorable(G) << endl;
}