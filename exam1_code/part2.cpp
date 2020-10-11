#include <iostream>
#include <vector>

using namespace std;

// T(n) = T(n / 2) + O(1)
// T(n) = O(log_2(n))
int count_repetitions(const vector<int>& A, int key){
    int lower_bound = -1; // O(1)
    int lo = 0, hi = A.size() - 1;//O(1)
    // O(log_2(n)) in total for the while loop
    while(lo <= hi){
        int mid = (lo + hi) / 2; // O(1)
        if(A[mid] < key) lo = mid + 1; // O(1) 
        else if(A[mid] > key) hi = mid - 1; // O(1)
        else{
            lower_bound = mid; // O(1)
            hi = mid - 1; // O(1)
        }
    }
    // O(1) for the comparison
    if(lower_bound == -1) return 0;

    int upper_bound = -1; // O(1)
    lo = 0, hi = A.size() - 1; // O(1)
    // O(log_2(n)) in total for the while loop
    while(lo <= hi){
        int mid = (lo + hi) / 2; // O(1)
        if(A[mid] < key) lo = mid + 1; // O(1)
        else if(A[mid] > key) hi = mid - 1; // O(1)
        else {
            upper_bound = mid; // O(1)
            lo = mid + 1; //O(1)
        }
    }
    return upper_bound - lower_bound + 1; // O(1)
}
