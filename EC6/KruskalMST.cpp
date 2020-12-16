//
// Created by sergio on 12/15/20.
//

#include "KruskalMST.h"

KruskalMST::KruskalMST(const UndirectedWeightedGraph &G) {
    int V = G.V();
    UnionFind UF(V);
    auto all_edges = G.edges();
    sort(all_edges.begin(), all_edges.end());
    mst_cost = 0;
    while(edges.size() < V - 1){
        for(auto e : all_edges){
            int v = e.either();
            int w = e.other(v);
            if(!UF.connected(v, w)){
                UF.connect(v, w);
                edges.push_back(e);
                mst_cost += e.edgeWeight();
            }
        }
    }
}

double KruskalMST::weight() const {
    return mst_cost;
}

const list<UndirectedWeightedEdge> KruskalMST::MST() const {
    return edges;
}
