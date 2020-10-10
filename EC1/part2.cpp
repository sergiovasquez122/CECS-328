#include <iostream>
#include <vector>
#include <limits>
#include <complex>

using namespace std;

bool equal(double x, double y)
{
    return std::fabs(x - y) <= std::numeric_limits<double>::epsilon() ;
}

double median_of_two_sorted_arrays(const vector<int>& a, int a_lo, int a_hi,const vector<int>& b, int b_lo, int b_hi){
    if(a_hi - a_lo <= 1){
        return (max(a[a_lo], b[b_lo]) + min(a[a_hi], b[b_hi])) / 2.0;
    }

    int a_mid = (a_hi + a_lo) / 2;
    int b_mid = (b_hi + b_lo) / 2;
    bool even_sized = (a_hi - a_lo + 1) % 2 == 0;

    double a_median;
    double b_median;
    if(even_sized){
        a_median = (a[a_mid] + a[a_mid + 1]) / 2.0;
        b_median = (b[b_mid] + b[b_mid + 1]) / 2.0;
    } else {
        a_median = a[a_mid];
        b_median = b[b_mid];
    }

    if(equal(a_median, b_median)){
        return a_median;
    } else if(even_sized && a_median < b_median){
        return median_of_two_sorted_arrays(a, a_mid + 1, a_hi, b, b_lo, b_mid);
    } else if(even_sized && a_median > b_median) {
        return median_of_two_sorted_arrays(a, a_lo, a_mid, b, b_mid + 1, b_hi);
    } else if(a_median < b_median){
        return median_of_two_sorted_arrays(a, a_mid, a_hi, b, b_lo, b_mid);
    } else {
        return median_of_two_sorted_arrays(a, a_lo, a_mid, b, b_mid, b_hi);
    }
}

double median_of_two_sorted_arrays(const vector<int>& a, const vector<int>& b){
    return median_of_two_sorted_arrays(a, 0, a.size() - 1,b, 0, b.size() - 1);
}


int main(){
    vector<int> a = {0, 2, 10, 26, 68};
    vector<int> b = {1, 11, 18, 20, 41};
    cout << median_of_two_sorted_arrays(a, b) << endl;
    vector<int> c = {5, 6, 14, 26};
    vector<int> d = {3, 41, 88, 100};
    cout << median_of_two_sorted_arrays(c, d) << endl;
    vector<int> e = {5, 10};
    vector<int> f = {2, 41};
    cout << median_of_two_sorted_arrays(e, f) << endl;
    vector<int> g = {10, 26, 68};
    vector<int> h = {1, 11, 18};
    cout << median_of_two_sorted_arrays(g, h) << endl;
    vector<int> j = {1, 12, 15, 26, 38};
    vector<int> k = {2, 13, 17, 30, 45};
    cout << median_of_two_sorted_arrays(j, k) << endl;
}
