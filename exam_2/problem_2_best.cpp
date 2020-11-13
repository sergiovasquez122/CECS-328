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
