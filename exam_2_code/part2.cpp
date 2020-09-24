#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    int element;
    int array_idx;
    int curr_idx;

    bool operator>(const Node& rhs) const{
        return element > rhs.element;
    }

    bool operator<(const Node& rhs) const{
        return element < rhs.element;
    }
};

vector<int> merge_k_array(const vector<vector<int>>& A){
    vector<int> result;
    priority_queue<Node> maxPQ;
    for(int i = 0;i < A.size();i++){
        maxPQ.push(Node{A[i][0], i, 0});
    }
    while(!maxPQ.empty()){
        Node temp = maxPQ.top();
        maxPQ.pop();
        result.emplace_back(temp.element);
        int new_idx = temp.curr_idx + 1;
        int array_idx = temp.array_idx;
        if(new_idx < A[array_idx].size()){
            maxPQ.push(Node{A[array_idx][new_idx], array_idx, new_idx});
        }
    }
    return result;
}
