#include <iostream>
#include <vector>

using namespace std;

bool get_line(string& line){
    cout << "enter non-negative integer: ";
    getline(cin, line);
    return !line.empty();
}

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
    string user_input;
    while(get_line(user_input)){
        int x = stoi(user_input);
        cout << "ceiling of the square root of x is: " << square_root(x) << endl;
    }
}