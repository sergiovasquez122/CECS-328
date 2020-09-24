#include <iostream>
#include <vector>

using namespace std;

/**
 * T(n) = T(n / 2) + O(1)
 * T(n) = O(log_2(n))
 */
int min_element_in_rotated_array(const vector<int>& A){
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

