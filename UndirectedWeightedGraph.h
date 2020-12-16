#ifndef EC_6_UNDIRECTEDWEIGHTEDGRAPH_H
#define EC_6_UNDIRECTEDWEIGHTEDGRAPH_H

#include "UndirectedWeightedEdge.h"
#include <vector>
#include <list>

using std::vector;
using std::list;


class UndirectedWeightedGraph {
public:
    explicit UndirectedWeightedGraph(int V);
    void addEdge(int v, int w, double weight);
    const list<UndirectedWeightedEdge>& adj(int v) const;
    vector<UndirectedWeightedEdge> edges() const;
    int V() const;
    int E() const;
private:
    vector<list<UndirectedWeightedEdge>> adjlist;
    int v;
    int e;
};


#endif //EC_6_UNDIRECTEDWEIGHTEDGRAPH_H
