//
// Created by sergio on 12/15/20.
//

#include "DirectedWeightedGraph.h"

DirectedWeightedGraph::DirectedWeightedGraph(int V) : v(V), e(0), adjlist(V){

}

const list<DirectedWeightedEdge> &DirectedWeightedGraph::adj(int v) const {
    return adjlist[v];
}

void DirectedWeightedGraph::addEdge(int source, int destination, double weight) {
    DirectedWeightedEdge edge(source, destination, weight);
    adjlist[source].push_back(edge);
}

int DirectedWeightedGraph::V() const {
    return v;
}

int DirectedWeightedGraph::E() const {
    return e;
}

