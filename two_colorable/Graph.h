//
// Created by sergio on 11/19/20.
//

#ifndef TWO_COLORABLE_GRAPH_H
#define TWO_COLORABLE_GRAPH_H
#include <vector>
#include <list>
using std::vector;
using std::list;

class Graph {
public:
    explicit Graph(int V) : v(V), e(0), adjlist(V){ }
    int V() const;

    int E() const;

    void addEdge(int v, int w);

    const list<int>& adj(int v) const;
private:
    vector<list<int>> adjlist;
    int v;
    int e;
};


#endif //TWO_COLORABLE_GRAPH_H
