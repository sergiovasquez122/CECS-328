//
// Created by sergio on 12/15/20.
//

#ifndef EC_6_UNDIRECTEDWEIGHTEDEDGE_H
#define EC_6_UNDIRECTEDWEIGHTEDEDGE_H
class UndirectedWeightedEdge {
public:
    explicit UndirectedWeightedEdge(int v, int w, double weight);
    int either() const;
    int other(int v) const;
    double edgeWeight() const;
    friend bool operator<(const UndirectedWeightedEdge& lhs, const UndirectedWeightedEdge& rhs);
private:
    int v, w;
    double weight;
};


#endif //EC_6_UNDIRECTEDWEIGHTEDEDGE_H
