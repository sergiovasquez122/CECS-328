#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<int>& A){
    int lo = 0, hi = A.size() - 1;
    int result = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(A[mid] == 0){
            result = mid;
            lo = mid + 1;
        } else{
            hi = mid - 1;
        }
    }
    return result + 1;
}

