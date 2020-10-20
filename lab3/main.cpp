#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

bool get_line(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return !userinput.empty();
}

int partition(vector<int> &arr, int lo, int hi, int pivot_idx){
    int pivot_value = arr[pivot_idx];
    int new_pivot_idx = lo;
    swap(arr[pivot_idx], arr[hi]);
    for(int i = lo;i < hi;i++){
        if(arr[i] < pivot_value){
            swap(arr[i], arr[new_pivot_idx++]);
        }
    }
    swap(arr[new_pivot_idx], arr[hi]);
    return new_pivot_idx;
}

void display_array(const vector<int>& A){
    for(int e : A) cout << e << " ";
    cout << endl;
}

int quick_select(vector<int> &arr, int k){
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    int lo = 0, hi = arr.size() - 1;
    while(lo <= hi){
        int pivot_idx = uniform_int_distribution<int>{lo, hi}(gen);
        int new_pivot_idx = partition(arr, lo, hi, pivot_idx);
        if(new_pivot_idx == k - 1) return arr[new_pivot_idx];
        else if(new_pivot_idx < k - 1) lo = new_pivot_idx + 1;
        else hi = new_pivot_idx - 1;
    }
}

int find_starting_idx(vector<int> &arr, int k){
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    int lo = 0, hi = arr.size() - 1;
    while(lo <= hi){
        int pivot_idx = uniform_int_distribution<int>{lo, hi}(gen);
        int new_pivot_idx = partition(arr, lo, hi, pivot_idx);
        if(new_pivot_idx == k - 1) return new_pivot_idx;
        else if(new_pivot_idx < k - 1) lo = new_pivot_idx + 1;
        else hi = new_pivot_idx - 1;
    }
}

vector<int> max_k_numbers(vector<int>& arr, int k){
    int starting_idx = find_starting_idx(arr, arr.size() - k + 1);
    vector<int> result;
    for(int i = starting_idx;i < arr.size();i++)
        result.push_back(arr[i]);
    return result;
}

int main(){
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    string userinput;
    while(get_line("(part 1) Enter positive integer n: ", userinput)){
        int n = stoi(userinput);
        uniform_int_distribution<int> uniform_int_distribution(-100, 100);

        vector<int> A;
        for(int i = 0;i < n;i++)
            A.push_back(uniform_int_distribution(gen));

        display_array(A);

        string second_input;
        get_line("Enter a number between 1 to n: ", second_input);
        int kth = stoi(second_input);
        cout << quick_select(A, kth) << endl;
    }

    while(get_line("(part 2) Enter positive integer n: ", userinput)){
        int n = stoi(userinput);
        uniform_int_distribution<int> uniform_int_distribution(-100, 100);

        vector<int> A;
        for(int i = 0;i < n;i++)
            A.push_back(uniform_int_distribution(gen));

        display_array(A);

        string second_input;
        get_line("Enter a number between 1 to n: ", second_input);
        int kth = stoi(second_input);
        auto result = max_k_numbers(A, kth);
        display_array(result);
    }
}
