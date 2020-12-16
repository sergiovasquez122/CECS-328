//
// Created by sergio on 12/15/20.
//

#include "PrimMST.h"
#include "min_heap.h"
#include <limits>
#include <deque>
#include <algorithm>

using namespace std;

PrimMST::PrimMST(const UndirectedWeightedGraph &G) {
    int V = G.V();
    vector<double> costs(V, std::numeric_limits<int>::max());
    deque<bool> on_tree(V, false);
    mst_cost = 0;
    costs[0] = 0;
    int iterations = 0;
    while(iterations < V){
        auto iter = min_element(costs.begin(), costs.end());
        int v = iter - costs.begin();
        on_tree[v] = true;
        mst_cost += costs[v];
        iterations++;
        costs[v] = std::numeric_limits<double>::max();
        for(auto edge : G.adj(v)){
            int w = edge.other(v);
            if(on_tree[w]) continue;
            if(costs[w] > edge.edgeWeight()){
                costs[w] = edge.edgeWeight();
            }
        }
    }
}

double PrimMST::weight() const {
    return mst_cost;
}

const list<UndirectedWeightedEdge> PrimMST::MST() const {
    return edges;
}
