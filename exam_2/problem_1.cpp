#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool is_max_heapv1(const vector<int> &A){
    for(int i = (A.size() - 1) / 2;i >= 0;i--){
        int left_child_idx = 2 * i + 1;
        if(left_child_idx < A.size() && A[i] < A[left_child_idx])
            return false;
        int right_child_idx = left_child_idx + 1;
        if(right_child_idx < A.size() && A[i] < A[right_child_idx])
            return false;
    }
    return true;
}

void max_heapify(vector<int>& a, int i, int n){
    while((2 * i + 1) < n){
        int exch_idx = 2 * i + 1;
        // check to see if a right child exists and if so check if its bigger than the left child
        if(exch_idx + 1 < n && a[exch_idx] < a[exch_idx + 1])
            exch_idx++;
        if(a[i] > a[exch_idx]) break;
        swap(a[i], a[exch_idx]);
        i = exch_idx;
    }
}

void heap_sort(vector<int>& a){
    int n = a.size();
    while(n > 1){
        swap(a[0], a[--n]);
        max_heapify(a, 0, n);
    }
}

bool is_max_heapv2(const vector<int>& A){
    vector<int> B = A;
    heap_sort(B);
    for(int i = 1;i < B.size();i++)
        if(B[i - 1] > B[i]) return false;
    return true;
}


int main(){
    vector<int> A = {10, 8, 7, 5, 2, 1};
    vector<int> B = {6, 0, 2, 4, 6, 1, 0};
    vector<int> C = {8, 4, 6, 2, 0};
    cout << is_max_heapv2(A) << endl;
    cout << is_max_heapv2(B) << endl;
    cout << is_max_heapv2(C) << endl;
}
