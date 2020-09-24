#include <iostream>
#include <vector>

using namespace std;

int square_root(int x){
    int lo = 0, hi = x;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int sqr = mid * mid;
        if(sqr < x) lo = mid + 1;
        else if(sqr > x) hi = mid - 1;
        else return mid;
    }
    return lo;
}

int main() {
    cout << square_root(37) << endl;
    cout << square_root(29) << endl;
    cout << square_root(28) << endl;
    cout << square_root(16) << endl;
}