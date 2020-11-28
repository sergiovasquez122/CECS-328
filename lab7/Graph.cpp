#include "Graph.h"

int Graph::V() const {
    return v;
}

ostream &operator<<(ostream &os, const Graph &graph) {
    os << "Vertices: " << graph.V() << " edges: " << graph.E() << std::endl;
    for(int v = 0;v < graph.V();v++){
        os << v << " : {";
        for(int w : graph.adj(v)){
            os << w << " ";
        }
        os << "}" << std::endl;
    }
    os << std::endl;
    return os;
}

int Graph::E() const {
    return e;
}

void Graph::addEdge(int v, int w){
    adjlist[v].push_back(w);
    adjlist[w].push_back(v);
    e++;
}

const list<int>& Graph::adj(int v) const {
    return adjlist[v];
}
