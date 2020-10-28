#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void display_array(const vector<int>& A){
    for(int e : A) cout << e << " ";
    cout << endl;
}

void k_index_away(vector<int>& A, int k){
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0;i < k;i++)
        pq.push(A[i]);
    int idx = 0;
    for(int i = k + 1;i < A.size();i++){
        pq.push(A[i]);
        A[idx++] = pq.top();
        pq.pop();
    }
    while(!pq.empty()){
        A[idx++] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> A = {2, 8, 0, 17, 5, 12};
    k_index_away(A, 2);
    display_array(A);
}