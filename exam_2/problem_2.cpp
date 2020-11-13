#include <iostream>
#include <deque>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool is_subsetv1(const vector<int>& A, const vector<int>& B){
    unordered_set<int> set(B.cbegin(), B.cend());
    int counter = 0;
    for(int e : A){
        if(set.count(e)){
            counter++;
        }
    }
    return counter == B.size();
}

bool is_subsetv2(const vector<int>& A, const vector<int>& B){
    int counter = 0;
    for(int i = 0;i < B.size();i++){
        if(binary_search(A.begin(), A.end(), B[i])){
            counter++;
        }
    }
    return counter == B.size();
}

bool is_subsetv3(const vector<int>& A, const vector<int>& B){
    int counter = 0;
    for(int i = 0;i < B.size();i++){
        for(int j = 0;j < A.size();j++){
            if(B[i] == A[j]){
                counter++;
            }
        }
    }
    return counter == B.size();
}

bool is_subsetv4(const vector<int>& A, const vector<int>& B){
    int max_element = A.back();
    deque<bool> elements(max_element + 1, false);
    for(int e : B)
        elements[e] = true;

    int counter = 0;
    for(int e : A){
        if(elements[e]){
            counter++;
        }
    }
    return counter == B.size();
}

int main(){
    vector<int> a1 = {2, 3, 5, 7, 8, 10, 15};
    vector<int> b1 = {2, 10, 5};
    cout << is_subsetv1(a1, b1) << endl;
    cout << is_subsetv2(a1, b1) << endl;
    cout << is_subsetv3(a1, b1) << endl;
    cout << is_subsetv4(a1, b1) << endl;

    vector<int> a2 = {0, 2, 4, 8, 9, 12, 13, 15, 24};
    vector<int> b2 = {6, 0, 4, 19, 35};
    cout << is_subsetv1(a2, b2) << endl;
    cout << is_subsetv2(a2, b2) << endl;
    cout << is_subsetv3(a2, b2) << endl;
    cout << is_subsetv4(a2, b2) << endl;
}
