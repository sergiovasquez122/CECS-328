//
// Created by sergio on 12/15/20.
//

#ifndef EC_6_DIRECTEDWEIGHTEDEDGE_H
#define EC_6_DIRECTEDWEIGHTEDEDGE_H


class DirectedWeightedEdge {
public:
    explicit DirectedWeightedEdge(int from, int to, double weight);
    int source() const;
    int destination() const;
    double edge_weight() const;
    void display() const;
private:
    int from, to;
    double weight;
};


#endif //EC_6_DIRECTEDWEIGHTEDEDGE_H
