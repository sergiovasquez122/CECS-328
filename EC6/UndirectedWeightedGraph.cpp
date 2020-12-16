//
// Created by sergio on 12/15/20.
//

#include "UndirectedWeightedGraph.h"

UndirectedWeightedGraph::UndirectedWeightedGraph(int V): v(V), e(0), adjlist(V) {

}

void UndirectedWeightedGraph::addEdge(int v, int w, double weight) {
    UndirectedWeightedEdge edge(v, w, weight);
    adjlist[v].push_back(edge);
    adjlist[w].push_back(edge);
    e++;
}

const list<UndirectedWeightedEdge> &UndirectedWeightedGraph::adj(int v) const {
    return adjlist[v];
}

vector<UndirectedWeightedEdge> UndirectedWeightedGraph::edges() const {
    vector<UndirectedWeightedEdge> all_edges;
    for(int w = 0;w < v;w++){
        for(auto edge : adj(w)){
            if(w < edge.other(w)){
                all_edges.push_back(edge);
            }
        }
    }
    return all_edges;
}

int UndirectedWeightedGraph::V() const {
    return v;
}

int UndirectedWeightedGraph::E() const {
    return e;
}
