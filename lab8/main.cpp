#include <iostream>
#include <sstream>
#include <random>
#include <chrono>
#include <limits>
#include "Graph.h"
#include "CycleDetector.h"
#include "TopologicalSort.h"

using namespace std;

bool getline(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return  !userinput.empty();
}

Graph generate_graph(int V, int E){
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
    Graph G(V);
    for(const auto& p : random_subset){
        G.addEdge(p.first, p.second);
    }
    return G;
}

int main() {
    string userinput;
    while(getline("Enter the number vertices followed by the number of edges: ", userinput)){
        int V, E;
        stringstream ss(userinput);
        ss >> V >> E;
        Graph G = generate_graph(V, E);
        cout << G << endl;
        CycleDetector cycleDetector(G);
        if(!cycleDetector.has_cycle()){
            TopologicalSort topologicalSort(G);
            for(int v : topologicalSort.topological_order()){
                cout << "v" << v << " start time: " << topologicalSort.start_time(v) << " end time: " << topologicalSort.end_time(v) << endl;
            }
        }
    }
}