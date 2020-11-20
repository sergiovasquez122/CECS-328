//
// Created by sergio on 11/19/20.
//

#include "Graph.h"

int Graph::V() const {
    return v;
}

int Graph::E() const {
    return e;
}

void Graph::addEdge(int v, int w){
    adjlist[v].push_back(w);
    adjlist[w].push_back(v);
    e++;
}

const list<int>& Graph::adj(int v) const {
    return adjlist[v];
}
