#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool get_line(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return !userinput.empty();
}

int split_point(const vector<int> &A){
    int lo = 0, hi = A.size() - 1;
    int result = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(A[mid] == 0){
            result = mid;
            lo = mid + 1;
        } else{
            hi = mid - 1;
        }
    }
    return result + 1;
}

/**
 * example usage
 * enter a binary where the first k elements are '0' and the rest of the n - k elements are '1': 0 0 0 1 1
 * output:  K = 3
 */

int main(){
    string userinput;
    while(get_line("enter a binary where the first k elements are '0' and the rest of the n - k elements are '1': ", userinput)){
        vector<int> binary_array;
        stringstream ss(userinput);
        int value;
        while(ss >> value){
            binary_array.push_back(value);
        }
        int k = split_point(binary_array);
        cout << "K = " << k << endl;
    }
}


