#ifndef LAB8_CYCLEDETECTOR_H
#define LAB8_CYCLEDETECTOR_H
#include "Graph.h"
#include <iostream>
#include <limits>

class CycleDetector {
public:
    explicit CycleDetector(const Graph& G);
    bool has_cycle();
private:
    void dfs(const Graph& G, int v);
private:
    vector<int> start_times;
    vector<int> end_times;
    vector<int> parent;
    bool cycle_found;
    int timer;
};


#endif //LAB8_CYCLEDETECTOR_H
