#include "TopologicalSort.h"
#include <algorithm>

TopologicalSort::TopologicalSort(const Graph &G)
: parent(G.V(), std::numeric_limits<int>::lowest())
,start_times(G.V(), -1), end_times(G.V(), -1), timer(0)
{
    for(int v = 0;v < G.V();v++){
        if(parent[v] == std::numeric_limits<int>::lowest()){
            parent[v] = -1;
            dfs(G, v);
        }
    }
    std::reverse(top_order.begin(), top_order.end());
}

void TopologicalSort::dfs(const Graph &G, int v) {
    start_times[v] = ++timer;
    for(int w : G.adj(v)){
        if(parent[w] == std::numeric_limits<int>::lowest()){
            parent[w] = v;
            dfs(G, w);
        }
    }
    end_times[v] = ++timer;
    top_order.push_back(v);
}

int TopologicalSort::start_time(int v) {
    return start_times[v];
}

int TopologicalSort::end_time(int v) {
    return end_times[v];
}

const vector<int> &TopologicalSort::topological_order() const {
    return top_order;
}
