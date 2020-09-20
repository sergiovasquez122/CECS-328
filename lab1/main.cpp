#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
#include <functional>

using namespace std;

bool get_line(string& line, const string& output_to_user){
    cout << output_to_user;
    getline(cin, line);
    return !line.empty();
}

int linear_search(const vector<int>& A, int key){
    for(int i = 0;i < A.size();i++){
        if(A[i] == key){
            return i;
        }
    }
    return -1;
}


int bin_search(const vector<int> &A, int key){
    int lo = 0, hi = A.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(A[mid] < key){
            lo = mid + 1;
        } else if(A[mid] > key){
            hi = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<int> uniform_int_distribution(-1000, 1000);
    string userinput;
    // part a
    while(get_line(userinput, "(part a) enter a positive integer n: ")) {
        int n = stoi(userinput);
        vector<int> A;
        for(int i = 0;i < n;i++)
            A.push_back(uniform_int_distribution(gen));

        sort(A.begin(), A.end());
        const int TRIALS = 500;
        vector<double> lin_search_trials;
        vector<double> bin_search_trials;
        for(int i = 0;i < TRIALS;i++){
            std::uniform_int_distribution<int> index_generator(0, n - 1);
            int random_idx = index_generator(gen);
            int key = A[random_idx];

            auto start = chrono::steady_clock::now();
            linear_search(A, key);
            auto end = chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            lin_search_trials.push_back(elapsed_seconds.count());

            start = chrono::steady_clock::now();
            bin_search(A, key);
            end = chrono::steady_clock::now();
            elapsed_seconds = end - start;
            bin_search_trials.push_back(elapsed_seconds.count());
        }

        double lin_search_avg_runtime = accumulate(lin_search_trials.begin(), lin_search_trials.end(), 0.0) / lin_search_trials.size();
        double bin_search_avg_runtime = accumulate(bin_search_trials.begin(), bin_search_trials.end(), 0.0) / bin_search_trials.size();

        cout << "The average runtime for linear search is: " << lin_search_avg_runtime << endl;
        cout << "The average runtime for binary search is: " << bin_search_avg_runtime << endl;
    }
    // part b
    while(get_line(userinput, "(part b) enter a positive integer n: ")){
        int n = stoi(userinput);
        vector<int> A;
        for(int i = 0;i < n;i++)
            A.push_back(uniform_int_distribution(gen));

        int key = 5000;
        auto start = chrono::steady_clock::now();
        linear_search(A, key);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        double worst_case_linear = elapsed_seconds.count();

        start = chrono::steady_clock::now();
        bin_search(A, key);
        end = chrono::steady_clock::now();
        elapsed_seconds = end - start;
        double worst_case_binary = elapsed_seconds.count();

        cout << "The worst case running time for linear search for an array of size " << n << " is: " << worst_case_linear << endl;
        cout << "The worst case running time for binary search for an array of size " << n << " is: " << worst_case_binary << endl;
    }
}