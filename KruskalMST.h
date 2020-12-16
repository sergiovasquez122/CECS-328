#ifndef EC_6_KRUSKALMST_H
#define EC_6_KRUSKALMST_H
#include "UndirectedWeightedGraph.h"
#include "UnionFind.h"
#include <algorithm>

using std::sort;
class KruskalMST {
public:
    explicit KruskalMST(const UndirectedWeightedGraph& G);
    double weight() const;
    const list<UndirectedWeightedEdge> MST() const;
private:
    double mst_cost;
    list<UndirectedWeightedEdge> edges;
};

#endif //EC_6_KRUSKALMST_H
