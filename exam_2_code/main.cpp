#include <iostream>
#include <vector>

using namespace std;

/**
 * T(n) = T(n / 2) + O(1)
 * T(n) = O(log_2(n))
 */
int min_element_in_rotated_array(vector<int> A){
    int left = 0, right = A.size() - 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(A[mid] > A[right]){
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}


int main() {
    cout << min_element_in_rotated_array({1, 2, 3, 4, 5, 6, 7}) << endl;
    cout << min_element_in_rotated_array({2, 3, 4, 5, 6, 7, 1}) << endl;
    cout << min_element_in_rotated_array({3, 4, 5, 6, 7, 1, 2}) << endl;
    cout << min_element_in_rotated_array({4, 5, 6, 7, 1, 2, 3}) << endl;
    cout << min_element_in_rotated_array({5, 6, 7, 1, 2, 3, 4}) << endl;
    cout << min_element_in_rotated_array({6, 7, 1, 2, 3, 4, 5}) << endl;
    cout << min_element_in_rotated_array({7, 1, 2, 3, 4, 5, 6}) << endl;
    cout << min_element_in_rotated_array({1, 2, 3, 4, 5, 6, 7}) << endl;
    cout << min_element_in_rotated_array({2, 5, 8, 10, 12, 0, 1}) << endl;
    cout << min_element_in_rotated_array({1, 6, 9, 10}) << endl;
    cout << min_element_in_rotated_array({20, 30, 40, 1, 5, 10}) << endl;
}
