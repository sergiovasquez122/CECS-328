//
// Created by sergio on 12/15/20.
//

#ifndef EC_6_PRIMMST_H
#define EC_6_PRIMMST_H
#include "UndirectedWeightedGraph.h"

class PrimMST {
public:
    explicit PrimMST(const UndirectedWeightedGraph& G);
    double weight() const;
    const list<UndirectedWeightedEdge> MST() const;
private:
    double mst_cost;
    list<UndirectedWeightedEdge> edges;
};


#endif //EC_6_PRIMMST_H
