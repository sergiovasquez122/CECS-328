#include <iostream>
#include "KruskalMST.h"
#include "PrimMST.h"

using namespace std;

int main() {
    UndirectedWeightedGraph G(8);
    G.addEdge(0, 1, 7);
    G.addEdge(0, 2, 2);
    G.addEdge(0, 3, 5);
    G.addEdge(1, 3, 4);
    G.addEdge(2, 3, 1);
    G.addEdge(3, 4, 3);
    G.addEdge(3, 5, 3);
    G.addEdge(4, 6, 1);
    G.addEdge(5, 6, 1);
    G.addEdge(5, 7, 4);
    G.addEdge(6, 7, 56);
    KruskalMST kruskalMST(G);
    cout << kruskalMST.weight() << endl;
    PrimMST primMST(G);
    cout << primMST.weight() << endl;
}