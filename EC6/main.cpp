#include <iostream>
#include <sstream>
#include <unordered_map>
#include <chrono>
#include <random>
#include "Dijkstra.h"
#include "KruskalMST.h"
#include "PrimMST.h"

using namespace std;

bool get_line(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return !userinput.empty();
}

UndirectedWeightedGraph generate_undirected_graph(int V, int E){
    vector<pair<int, int>> all_subsets;
    for(int i = 0;i < V;i++){
        for(int j = i + 1;j < V;++j){
            all_subsets.push_back({i, j});
        }
    }
    vector<pair<int, int>> subset;
    for(int i = 0;i < E;i++){
        subset.push_back(all_subsets[i]);
    }
    long seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> uniformIntDistribution(0, E);
    for(int i = E;i < all_subsets.size();i++){
        int random_idx = uniformIntDistribution(gen);
        if(random_idx < E) {
            subset[random_idx] = all_subsets[i];
        }
    }
    UndirectedWeightedGraph G(V);
    uniform_int_distribution<int> edge_weights(0, E);
    for(const auto& p : subset){
        G.addEdge(p.first, p.second,edge_weights(gen));
    }
    return G;
}

DirectedWeightedGraph generate_digraph(int V, int E){
    vector<pair<int, int>> all_subsets;
    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++){
            if(i != j){
                all_subsets.push_back({i, j});
            }
        }
    }
    long seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> uniformIntDistribution(0, E);
    vector<pair<int, int>> random_subset;
    for(int i = 0;i < E;i++){
        random_subset.push_back(all_subsets[i]);
    }
    for(int i = E;i < all_subsets.size();i++){
        int random_idx = uniformIntDistribution(gen);
        if(random_idx < E){
            random_subset[random_idx] = all_subsets[i];
        }
    }
    DirectedWeightedGraph G(V);
    uniform_int_distribution<int> edge_weights(0, 10);
    for(const auto& p : random_subset){
        G.addEdge(p.first, p.second,edge_weights(gen));
    }
    return G;
}


int main() {
    string userinput;
    while(get_line("(part a) enter the number of vertices and edges and starting vertex: ", userinput)){
        stringstream ss(userinput);
        int V, E, s;
        ss >> V >> E >> s;
        auto G = generate_digraph(V, E);
        Dijkstra dijkstra(G, s);
        for(int i = 0;i < V;i++){
            if(dijkstra.hasPathTo(i)){
                for(auto e : dijkstra.pathTo(i)){
                    e.display();
                }
                cout << endl;
            }
        }
    }
    while(get_line("(part b) enter the number of vertices and edges: ", userinput)){
        stringstream ss(userinput);
        int V, E;
        ss >> V >> E;
        auto G = generate_undirected_graph(V, E);
        PrimMST primMST(G);
        KruskalMST kruskalMST(G);
        cout << "Prims MST cost: " << primMST.weight() << endl;
        cout << "Kruskal MST cost: " << kruskalMST.weight() << endl;
    }
}