#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <chrono>

using namespace std;

bool get_line(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return !userinput.empty();
}

void display_arr(const vector<int>& arr){
    for(int e : arr) cout << e << " ";
    cout << endl;
}

// O(n**3)
int freshman_version(const vector<int>& arr){
    int max_sum = 0;
    for(int i = 0;i < arr.size();i++){
        for(int j = i;j < arr.size(); j++){
            int sum = 0;
            for(int k = i; k <= j;k++){
                sum += arr[k];
            }
            max_sum = max(sum, max_sum);
        }
    }
    return max_sum;
}

// O(n**2)
int sophomore_version(const vector<int>& arr){
    int max_sum = 0;
    for(int i = 0;i < arr.size();i++){
        int sum = 0;
        for(int j = i;j < arr.size();++j){
            sum += arr[j];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

struct triplet{
    int max_left;
    int max_right;
    int left_sum_plus_right_sum;
};

triplet find_max_crossing_subarray(const vector<int>& arr, int low, int mid, int high){
    int left_sum = std::numeric_limits<int>::min();
    int sum = 0;
    int max_left = mid;
    for(int i = mid;i >= low;i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = std::numeric_limits<int>::min();
    sum = 0;
    int max_right = mid + 1;
    for(int j = mid + 1;j <= high;j++){
        sum += arr[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return {max_left, max_right, left_sum + right_sum};
}

triplet find_maximum_subarray(const vector<int>& arr, int low, int high){
    if(low == high)
        return {low, high, arr[low]};
    else {
        int mid = (low + high) / 2;
        auto triplet1 = find_maximum_subarray(arr, low, mid);
        int left_low = triplet1.max_left, left_high = triplet1.max_right, left_sum = triplet1.left_sum_plus_right_sum;
        auto triplet2 = find_maximum_subarray(arr, mid + 1, high);
        int right_low = triplet2.max_left, right_high = triplet2.max_right, right_sum = triplet2.left_sum_plus_right_sum;
        auto triplet3 = find_max_crossing_subarray(arr, low, mid, high);
        int cross_low = triplet3.max_left, cross_high = triplet3.max_right, cross_sum = triplet3.left_sum_plus_right_sum;
        if(left_sum >= right_sum && left_sum >= cross_sum)
            return {left_low, left_high, left_sum};
        else if(right_sum >= left_sum && right_sum >= cross_sum)
            return {right_low, right_high, right_sum};
        else return {cross_low, cross_high, cross_sum};
    }
}

// O(n * log(n))
int junior_version(const vector<int>& arr){
    return find_maximum_subarray(arr, 0, arr.size() - 1).left_sum_plus_right_sum;
}

// O(n)
int senior_version(const vector<int>& arr){
    int max_sum = 0;
    int sum = 0;
    for(int i = 0;i < arr.size(); i++){
        sum += arr[i];
        if(sum > max_sum)
            max_sum = sum;
        else if(sum < 0)
            sum = 0;
    }
    return max_sum;
}

int main() {
    string userinput;
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    const int LOWER_BOUND = -100;
    const int UPPER_BOUND = 100;
    uniform_int_distribution<int> uniform_int_distribution(LOWER_BOUND, UPPER_BOUND);
    while(get_line("Enter a positive integer: ", userinput)){
        int n = stoi(userinput);
        vector<int> arr;
        for(int i = 0;i < n;i++)
            arr.push_back(uniform_int_distribution(gen));

        display_arr(arr);
        cout << "junior version: " << junior_version(arr) << endl;
        cout << "senior version: " << senior_version(arr) << endl;
    }
}