//
// Created by sergio on 12/15/20.
//

#ifndef EC_6_MIN_HEAP_H
#define EC_6_MIN_HEAP_H

#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

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


#endif //EC_6_MIN_HEAP_H
