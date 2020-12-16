#include "Dijkstra.h"
#include <limits>
#include <algorithm>

Dijkstra::Dijkstra(const DirectedWeightedGraph& G, int s): distTo(G.V(), std::numeric_limits<double>::max()), source(s),edgeTo(G.V(), DirectedWeightedEdge(-1, -1, -1)),
on_spanning_tree(G.V(), false){
    vector<double> pq(G.V(), std::numeric_limits<double>::max()); // do it with simple array
    distTo[s] = 0;
    pq[s] = 0;
    int iterations = 0;
    while(iterations < G.V()){
        auto iter = min_element(pq.begin(), pq.end());
        int v = iter - pq.begin();
        on_spanning_tree[v] = true;
        pq[v] = std::numeric_limits<double>::max();
        iterations++;
        for(DirectedWeightedEdge e : G.adj(v)){
            int w = e.destination();
            if(on_spanning_tree[w]) continue;
            if(distTo[w] > distTo[v] + e.edge_weight()){
                distTo[w] = distTo[v] + e.edge_weight();
                edgeTo[w] = e;
                pq[w] = distTo[w];
            }
        }
    }
}

double Dijkstra::distanceTo(int v) {
    return distTo[v];
}

bool Dijkstra::hasPathTo(int v) {
    return on_spanning_tree[v];
}

vector<DirectedWeightedEdge> Dijkstra::pathTo(int v) {
    if(v == source) return {DirectedWeightedEdge(source, source, 0)};
    vector<DirectedWeightedEdge> path;
    for(DirectedWeightedEdge iter = edgeTo[v];iter.source() != -1;iter = edgeTo[iter.source()]){
        path.push_back(iter);
    }
    return {path.rbegin(), path.rend()};
}
