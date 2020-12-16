//
// Created by sergio on 12/15/20.
//

#include "UndirectedWeightedEdge.h"

UndirectedWeightedEdge::UndirectedWeightedEdge(int v, int w, double weight)
:v(v), w(w), weight(weight)
{
}

bool operator<(const UndirectedWeightedEdge &lhs, const UndirectedWeightedEdge &rhs) {
    return lhs.weight < rhs.weight;
}

int UndirectedWeightedEdge::either() const {
    return v;
}

int UndirectedWeightedEdge::other(int u) const {
    if(u == w) return v;
    return w;
}

double UndirectedWeightedEdge::edgeWeight() const {
    return weight;
}
