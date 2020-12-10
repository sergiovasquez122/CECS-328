#include <iostream>
#include <limits>
#include <sstream>
#include <deque>
#include <chrono>
#include <queue>
#include <random>
#include "Graph.h"

using namespace std;

bool get_line(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return !userinput.empty();
}

void bfs(const Graph& G, int source){
    vector<int> distTo(G.V(), std::numeric_limits<int>::max());
    deque<int> edgeTo(G.V(), -1);
    distTo[source] = 0;
    edgeTo[source] = -1;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int w : G.adj(v)){
            if(edgeTo[w] == -1){
                edgeTo[w] = v;
                distTo[w] = distTo[v] + 1;
                q.push(w);
            }
        }
    }
    for(int v = 0;v < G.V();v++){
        if(distTo[v] != std::numeric_limits<int>::max()){
            cout << "Shortest Path cost from: "<< source << " to " <<  v << " is " << distTo[v] << endl;
            vector<int> path;
            for(int e = v;e != source;e = edgeTo[e]){
                path.push_back(e);
            }
            path.push_back(source);
            for(int i = path.size() - 1;i >= 1;i--){
                cout << path[i] << "->";
            }
            cout << path[0] << endl;
        } else {
            cout << source << " to " << v << " unreachable" << endl;
        }
    }
}

enum COLORS{GRAY = 0, RED = 1, BLUE = 2};

bool is_bipartite(const Graph& G, int source, vector<COLORS>& colors){
    colors[source] = BLUE;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int w : G.adj(v)){
            if(colors[w] == GRAY){
                colors[w] = (colors[v] == RED) ? BLUE : RED;
                q.push(w);
            } else if(colors[w] == colors[v]){
                cout << "not bipartite" << endl;
                return false;
            }
        }
    }
    return true;
}

void explore(const Graph& G){
    vector<COLORS > vertex_color(G.V(), GRAY);
    for(int v = 0;v < G.V();v++){
        if(vertex_color[v] == GRAY && !is_bipartite(G, v, vertex_color)){
            break;
        }
    }
    vector<string> color_decoded = {"gray", "red", "blue"};
    for(int v = 0;v < G.V();v++){
        cout << v << " color: " << color_decoded[vertex_color[v]] << endl;
    }
}

Graph generate_graph(int V, int E){
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
    uniform_int_distribution<int> uniform_int_distribution(0, E);
    for(int i = E;i < all_subsets.size();i++){
        int random_idx = uniform_int_distribution(gen);
        if(random_idx < E) {
            subset[random_idx] = all_subsets[i];
        }
    }
    Graph G(V);
    for(const auto& p : subset){
        G.addEdge(p.first, p.second);
    }
    return G;
}

int main() {
    string userinput;
    while(get_line("(part a) enter number of vertices followed by number of edges separated by a space: ", userinput)){
        stringstream ss(userinput);
        int V, E;
        ss >> V >> E;
        Graph G = generate_graph(V, E);
        cout << G << endl;
        get_line("enter starting vertex of bfs: ", userinput);
        ss = stringstream(userinput);
        int source;
        ss >> source;
        bfs(G, source);
    } while(get_line("(part b) enter number of vertices followed by number of edges separated by a space: ", userinput)){
        stringstream ss(userinput);
        int V, E;
        ss >> V >> E;
        Graph G = generate_graph(V, E);
        cout << G << endl;
        explore(G);
    }
}