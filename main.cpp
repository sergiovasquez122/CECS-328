#include <iostream>
#include <unordered_map>
#include "Dijkstra.h"
#include "KruskalMST.h"
#include "PrimMST.h"

using namespace std;

int main() {
    unordered_map<char, int> mapping;
    for(char c = 'a';c <= 'z';c++){
        mapping.insert({c, c - 'a'});
    }
    DirectedWeightedGraph G(9);
    G.addEdge(mapping['a'], mapping['b'], 1);
    G.addEdge(mapping['a'], mapping['c'], 5);
    G.addEdge(mapping['b'], mapping['c'], 3);
    G.addEdge(mapping['b'], mapping['d'], 2);
    G.addEdge(mapping['c'], mapping['d'], 1);
    G.addEdge(mapping['c'], mapping['e'], 2);
    G.addEdge(mapping['d'], mapping['e'], 10);
    G.addEdge(mapping['e'], mapping['f'], 4);
    G.addEdge(mapping['e'], mapping['g'], 1);
    G.addEdge(mapping['f'], mapping['g'], 1);

    G.addEdge(mapping['h'], mapping['i'], 2);

    Dijkstra dijkstra(G, mapping['a']);
    for(char c = 'a';c <= 'z';c++){
        if(dijkstra.hasPathTo(mapping[c])){
            for(auto e : dijkstra.pathTo(mapping[c])){
                e.display();
            }
            cout << endl;
        }
    }
}