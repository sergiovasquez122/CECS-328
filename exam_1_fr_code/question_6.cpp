#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
vector<int> multiply(const vector<int>& A, const vector<int>& B){
    vector<int> result(A.size() + B.size());
    for(int i = A.size() - 1;i >= 0;i--){
        for(int j = B.size() - 1;j >= 0;j--){
            result[i + j + 1] += A[i] * B[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }
    return result;
}

void display(const vector<int>& A){
    for(int e : A) cout << e << " ";
    cout << endl;
}

int main() {
    vector<int> A = {1, 2};
    vector<int> B = {1, 2};
    vector<int> C = multiply(A, B);
    display(C);
}