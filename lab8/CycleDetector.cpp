//
// Created by sergio on 12/2/20.
//

#include "CycleDetector.h"

CycleDetector::CycleDetector(const Graph &G) : parent(G.V(), std::numeric_limits<int>::lowest())
,start_times(G.V(), -1), end_times(G.V(), -1), timer(0), cycle_found(false)
{
    for(int v = 0;v < G.V();v++){
        if(parent[v] == std::numeric_limits<int>::lowest()){
            parent[v] = -1;
            dfs(G, v);
        }
    }
}

bool CycleDetector::has_cycle() {
    return cycle_found;
}

void CycleDetector::dfs(const Graph &G, int v) {
    start_times[v] = ++timer;
    for(int w : G.adj(v)){
        if(parent[w] == std::numeric_limits<int>::lowest()){
            parent[w] = v;
            dfs(G, w);
        } else if(end_times[w] == -1){
            cycle_found = true;
            std::cout << "Cycle detected, topological sort is impossible" << std::endl;
        }
    }
    end_times[v] = ++timer;
}
