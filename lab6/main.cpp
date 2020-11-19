#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

bool get_line(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return !userinput.empty();
}

bool AreSame(double a, double b)
{
    return fabs(a - b) < numeric_limits<double>::epsilon();
}

void display_arr(const vector<double>& arr){
    for(double e : arr) cout << e << " ";
    cout << endl;
}

template<typename T>
double find_max_crossing_subarray(const vector<T>& arr, int low, int mid, int high){
    vector<T> left_sum(mid - low + 1);
    double sum = 0;
    int counter = left_sum.size() - 1;
    for(int i = mid;i >= low;i--){
        sum += arr[i];
        left_sum[counter--] += sum;
    }

    vector<T> right_sum(high - mid);
    sum = 0;
    counter = 0;
    for(int i = mid + 1;i <= high;i++){
        sum += arr[i];
        right_sum[counter++] += sum;
    }
    sort(left_sum.begin(), left_sum.end());
    sort(right_sum.rbegin(), right_sum.rend());

    int i = 0;
    int j = 0;
    double s_min = numeric_limits<double>::max();
    while(i < left_sum.size() && j < right_sum.size()){
        double s = left_sum[i] + right_sum[j];
        if(s <= 0) i++;
        else if(s < s_min) s_min = s, j++;
        else j++;
    }
    if(AreSame(s_min, numeric_limits<double>::max()))
        return numeric_limits<double>::lowest();
    return s_min;
}

template<typename T>
double find_MPSS(const vector<T> &arr, int lo, int hi){
    if(lo == hi)
        return arr[lo];
    int mid = (lo + hi) / 2;
    double mss_l = find_MPSS(arr, lo, mid);
    double mss_r = find_MPSS(arr, mid + 1, hi);
    double mss_m = find_max_crossing_subarray(arr, lo, mid, hi);
    if(mss_l > 0 && mss_r > 0 && mss_m > 0)
        return min(min(mss_l, mss_r), mss_m);
    return max(mss_l, max(mss_r, mss_m));
}

template<typename T>
double divide_and_conquer_approach(const vector<T> &arr){
    return find_MPSS(arr, 0, arr.size() - 1);
}

int main() {
    string userinput;
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    const int LOWER_BOUND = -20;
    const int UPPER_BOUND = 20;
    uniform_real_distribution<double> uniform_real_distribution(LOWER_BOUND, UPPER_BOUND);
    while(get_line("Enter a positive integer: ", userinput)){
        int n = stoi(userinput);
        vector<double > arr;
        for(int i = 0;i < n;i++)
            arr.push_back(uniform_real_distribution(gen));
        display_arr(arr);
        cout <<"MPSS: "<< divide_and_conquer_approach(arr) << endl;
   }
}