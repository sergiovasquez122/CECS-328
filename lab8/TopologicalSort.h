#ifndef LAB8_TOPOLOGICALSORT_H
#define LAB8_TOPOLOGICALSORT_H
#include "Graph.h"
#include "CycleDetector.h"

class TopologicalSort {
public:
    explicit TopologicalSort(const Graph& G);
    int start_time(int v);
    int end_time(int v);
    const vector<int>& topological_order() const;
private:
    void dfs(const Graph& G, int v);
    vector<int> start_times;
    vector<int> end_times;
    vector<int> parent;
    vector<int> top_order;
    int timer;
};


#endif //LAB8_TOPOLOGICALSORT_H
