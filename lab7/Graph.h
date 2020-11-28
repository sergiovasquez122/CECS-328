#ifndef LAB_7_GRAPH_H
#define LAB_7_GRAPH_H

#include <iostream>
#include <vector>
#include <list>
using std::ostream;
using std::vector;
using std::list;

class Graph {
public:
    explicit Graph(int V) : v(V), e(0), adjlist(V){ }
    int V() const;

    int E() const;

    void addEdge(int v, int w);

    const list<int>& adj(int v) const;

    friend ostream &operator<<(ostream &os, const Graph &graph);


private:
    vector<list<int>> adjlist;
    int v;
    int e;
};


#endif //LAB_7_GRAPH_H
