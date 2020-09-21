#include <iostream>
#include <vector>

using namespace std;

// T(n) = T(n / 2) + O(1)
// T(n) = O(log_2(n))
int binary_search(const vector<int>& A){
    int lo = 0, hi = A.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(A[mid] < mid){
            lo = mid+ 1;
        } else if(A[mid] > mid){
            hi = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> A = {0, 1, 2, 5, 10, 21};
    cout << binary_search(A) << endl;
}