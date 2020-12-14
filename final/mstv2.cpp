#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <limits>

using namespace std;

class min_heap{
public:
    min_heap(const vector<int>& vertices, const vector<double>& costs) : pq(vertices), costs(costs)
    {
        for(int i = 0;i < pq.size();i++){
            vertex_to_index[pq[i]] = i;
        }

        for(int i = (pq.size() - 1) / 2;i >= 0;i--){
            min_heapify(i);
        }
    }

    bool contains_vertex(int v){
        return vertex_to_index.count(v);
    }

    int top(){
        return pq[0];
    }

    bool empty(){
        return pq.empty();
    }

    void min_heapify(int i){
        while(2 * i + 1 < pq.size()){
            int exch_idx = 2 * i + 1;
            if(exch_idx + 1 < pq.size() && element_priority(exch_idx) > element_priority(exch_idx + 1))
                exch_idx++;
            if(element_priority(i) < element_priority(exch_idx)) break;
            vertex_to_index[pq[i]] = exch_idx;
            vertex_to_index[pq[exch_idx]] = i;
            swap(pq[i], pq[exch_idx]);
            i = exch_idx;
        }
    }

    void pop(){
        swap(pq[0], pq[pq.size() - 1]);
        costs[pq[pq.size() - 1]] = std::numeric_limits<double>::max();
        vertex_to_index.erase(pq[pq.size() - 1]);
        vertex_to_index[pq[0]] = 0;
        pq.pop_back();
        min_heapify(0);
    }

    void swim(int i){
        while(i > 0 && element_priority((i - 1) / 2) > element_priority(i)){
            int parent = (i - 1) / 2;
            vertex_to_index[pq[parent]] = i;
            vertex_to_index[pq[i]] = parent;
            swap(pq[parent], pq[i]);
            i = parent;
        }
    }

    void decrease_key(int vertex, double cost){
        costs[vertex] = cost;
        swim(vertex_to_index[vertex]);
    }

    void push(int e){
        pq.push_back(e);
        vertex_to_index[e] = pq.size() - 1;
        swim(pq.size() - 1);
    }

    double element_priority(int i){
        return costs[pq[i]];
    }

    double vertex_cost(int v){
        return costs[v];
    }

private:
    vector<int> pq;
    vector<double> costs;
    unordered_map<int, int> vertex_to_index;
};

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

double primsv2(const vector<vector<int>>& buildings){
    auto adjmat = generate_graph(buildings);
    int V = adjmat.size();
    vector<int> vertices(V, 0);
    for(int i = 0;i < V;i++)
        vertices[i] = i;
    vector<double> costs(V, std::numeric_limits<double>::max());
    costs[0] = 0;
    min_heap pq(vertices, costs);
    double result = 0;
    while(!pq.empty()){
        int v = pq.top();
        result += pq.vertex_cost(v);
        pq.pop();
        for(int w = 0;w < V;w++){
            if(adjmat[v][w] > 0 && pq.contains_vertex(w) && adjmat[v][w] < pq.vertex_cost(w)){
                pq.decrease_key(w, adjmat[v][w]);
            }
        }
    }
    return result;
}
