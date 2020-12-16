#include <cstdio>
#include "DirectedWeightedEdge.h"

DirectedWeightedEdge::DirectedWeightedEdge(int from, int to, double weight) : from(from), to(to), weight(weight)
{

}

int DirectedWeightedEdge::source() const {
    return from;
}

int DirectedWeightedEdge::destination() const {
    return to;
}

double DirectedWeightedEdge::edge_weight() const {
    return weight;
}

void DirectedWeightedEdge::display() const {
    printf("%d->%d (%.2f) ", from , to, weight);
}
