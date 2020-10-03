#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>

using namespace std;

bool get_line(string& line){
    cout << "Enter a positive integer: ";
    getline(cin, line);
    return !line.empty();
}

vector<int> generate_array(int m){
    random_device r;
    mt19937 gen(r());
    uniform_int_distribution<int> uniformIntDistribution(1, m - 1);
    int result_size = uniformIntDistribution(gen);
    vector<int> candiates(m);
    iota(begin(candiates), end(candiates), 0); // generate candidates from [0, m - 1]
    shuffle(candiates.begin(), candiates.end(), gen); // shuffle the candidates into random order
    vector<int> result(result_size);
    for(int i = 0;i < result.size();i++)
        result[i] = candiates[i];
    sort(result.begin(), result.end());
    return result;
}

/**
 * T(n) = T(n / 2) + O(1)
 * T(n) = O(log_2(n))
 */
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

void display_array(const vector<int>& a){
    cout << "[";
    for(int e : a)  cout << e << " ";
    cout <<"]";
}

int main() {
    string userinput;
    while(get_line(userinput)){
        int m = stoi(userinput);
        auto a = generate_array(m);
        cout << "input: ";
        display_array(a);
        cout << ", " << m << endl;
        cout << "output: " << find_smallest_missing_number(a) << endl;
    }
}