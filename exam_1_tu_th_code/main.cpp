#include <iostream>
#include <vector>

using namespace std;

// T(n) = T(n / 2) + O(1)
// T(n) = O(log_2(n))
int binary_search(const vector<int>& A, int start, int end){
    if(start > end) return end + 1;

    if(A[start] != start) return start;

    int mid = (start  + end) / 2;

    if(A[mid] == mid) return binary_search(A, mid + 1, end);

    return binary_search(A, start, mid - 1);
}

int main() {
    vector<int> A1 = {0, 1, 3, 6, 8, 9};
    vector<int> A2 = {0, 2, 5, 7, 11};
    cout << binary_search(A1, 0, A1.size() - 1) << endl;
    cout << binary_search(A2, 0, A2.size() - 1) << endl;
}