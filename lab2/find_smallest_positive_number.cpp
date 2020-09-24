#include <iostream>
#include <vector>

using namespace std;

int find_smallest_missing_number(const vector<int>& A, int left, int right){
    if(left > right) return left; // T(
    if(A[left] != left) return left;
    int mid = (left + right) / 2;
    if(A[mid] != mid) return find_smallest_missing_number(A, left, mid - 1);
    return find_smallest_missing_number(A, mid + 1, right);
}

int find_smallest_missing_number(const vector<int>& A){
    return find_smallest_missing_number(A, 0, A.size() - 1);
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