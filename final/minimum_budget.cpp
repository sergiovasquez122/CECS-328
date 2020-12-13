#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>

using namespace std;

void display_matrix(const vector<vector<double>>& matrix){
    for(int i = 0;i < matrix.size();i++){
        for(int j = 0;j < matrix[0].size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> generate_graph(const vector<vector<int>>& buildings){
    int m = buildings.size();
    vector<vector<double>> graph(m, vector<double>(m, 0.0)); // initialize mxm graph
    for(int i = 0;i < graph.size();i++){
        for(int j = i + 1;j < graph[0].size();j++){
            int xi = buildings[i][0];
            int yi = buildings[i][1];

            int xj = buildings[j][0];
            int yj = buildings[j][1];

            double dist = sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
            // matrix is symmetric since undirected
            graph[i][j] = dist;
            graph[j][i] = dist;
        }
    }
    return graph;
}

int select_min(const deque<bool>& in_mst, const vector<double>& cost){
    int chosen_vertex = -1;
    double vertex_cost = std::numeric_limits<int>::max();
    for(int i = 0;i < cost.size();i++){
        if(!in_mst[i] && cost[i] < vertex_cost){
            chosen_vertex = i;
            vertex_cost = cost[i];
        }
    }
    return chosen_vertex;
}

double prims(const vector<vector<double>>& adjmat){
    int V = adjmat.size();
    deque<bool> in_tree(V, false);
    vector<double> cost(V, std::numeric_limits<double>::max());
    cost[0] = 0.0;
    int iterations = 0;
    while(iterations < V - 1){
        int curr = select_min(in_tree, cost); // select next valid candidate
        in_tree[curr] = true;
        iterations++;
        for(int i = 0;i < V;i++){
            if(adjmat[curr][i] > 0 && !in_tree[i] && adjmat[curr][i] < cost[i]){
                cost[i] = adjmat[curr][i];
            }
        }
    }
    // adding up the edge weights of the mst
    double result = 0;
    for(double d : cost){
        result += d;
    }
    return result;
}

int main(){
    vector<vector<int>> buildings = {{0, 0}, {1, 2}, {3, 1}, {4, 4}};
    auto graph = generate_graph(buildings);
    display_matrix(graph);
    cout << prims(graph) << endl;
    vector<vector<int>> buildings2 = {{0, 0}, {0, 1}, {2, 0}, {3, 0}, {4, 3}};
    auto graph2 = generate_graph(buildings2);
    display_matrix(graph2);
    cout << prims(graph2) << endl;
}
