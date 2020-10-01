#include <iostream>
#include <vector>

using namespace std;

int find_smallest_missing_number(const vector<int>& A){
    int lo = 0, hi = A.size() - 1;
    while(lo <= hi){
        if(A[lo] != lo) return lo;
        int mid = (lo + hi) / 2;
        if(A[mid] != mid) hi = mid - 1;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    vector<int> a1 = {0, 1, 3, 6, 8, 9};
    vector<int> a2 = {2, 5, 7, 11};
    vector<int> a3 = {0, 1, 2, 3, 4};
    vector<int> a4 = {12};
    cout << find_smallest_missing_number(a1)<< endl;
    cout << find_smallest_missing_number(a2) << endl;
    cout << find_smallest_missing_number(a3) << endl;
    cout << find_smallest_missing_number(a4) << endl;
}
