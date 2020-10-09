#include <iostream>
#include <vector>

using namespace std;

int brute_force_solution(const vector<int>& A, int key){
    int count = 0;
    for(int i = 0;i < A.size();i++){
        if(A[i] == key){
            count++;
        }
    }
    return count;
}

// T(n) = O(log_2(n))
int elegant_solution(const vector<int>& A, int key){
    int lower_bound = -1; // O(1)
    int lo = 0, hi = A.size() - 1;//O(1)
    // O(log_2(n)) in total for the while loop
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(A[mid] < key) lo = mid + 1;
        else if(A[mid] > key) hi = mid - 1;
        else{
            lower_bound = mid;
            hi = mid - 1;
        }
    }
    // O(1) for the comparison
    if(lower_bound == -1) return 0;

    int upper_bound = -1; // O(1)
    lo = 0, hi = A.size() - 1; // O(1)
    // O(log_2(n)) in total for the while loop
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(A[mid] < key) lo = mid + 1;
        else if(A[mid] > key) hi = mid - 1;
        else {
            upper_bound = mid;
            lo = mid + 1;
        }
    }
    return upper_bound - lower_bound + 1; // O(1)
}

int main(int argc, char* argv[]){
    vector<int> a1 = {0, 1, 1,2, 2, 2, 3, 3, 6};
    cout << elegant_solution(a1, 2) << endl;
    vector<int> a2 = {0, 0, 2, 2, 3, 9, 10, 12, 15};
    cout << elegant_solution(a2, 10) << endl;
    vector<int> a3 = {0, 1, 3, 8, 12};
    cout << elegant_solution(a3, 5) << endl;
}