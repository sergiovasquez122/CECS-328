#ifndef EC_6_DIRECTEDWEIGHTEDGRAPH_H
#define EC_6_DIRECTEDWEIGHTEDGRAPH_H

#include <vector>
#include <list>
#include "DirectedWeightedEdge.h"

using namespace std;

class DirectedWeightedGraph {
public:
    explicit DirectedWeightedGraph(int V);
    const list<DirectedWeightedEdge>& adj(int v) const;
    void addEdge(int source, int destination, double weight);
    int V() const;
    int E() const;
private:
    int v, e;
    vector<list<DirectedWeightedEdge>> adjlist;
};


#endif //EC_6_DIRECTEDWEIGHTEDGRAPH_H
