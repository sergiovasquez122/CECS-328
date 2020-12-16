#ifndef EC_6_DIJKSTRA_H
#define EC_6_DIJKSTRA_H
#include "DirectedWeightedEdge.h"
#include "DirectedWeightedGraph.h"
#include <deque>

class Dijkstra {
public:
    explicit Dijkstra(const DirectedWeightedGraph& G, int s);
    double distanceTo(int v);
    bool hasPathTo(int v);
    vector<DirectedWeightedEdge> pathTo(int v);
private:
    int source;
    vector<double> distTo;
    deque<bool> on_spanning_tree;
    vector<DirectedWeightedEdge> edgeTo;
};


#endif //EC_6_DIJKSTRA_H
