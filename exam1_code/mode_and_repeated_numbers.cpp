#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

struct my_pair{
    vector<int> modes;
    vector<int> hist;
    vector<int> repeated;
};

bool get_line(const string& prompt, string& userinput){
    cout << prompt;
    getline(cin, userinput);
    return !userinput.empty();
}

// total runtime is O(n)
vector<int> histogram_generator(const vector<int>& A){
    vector<int> result(A.size() + 1); // O(n)
    // O(n)
    for(int e : A){
        ++result[e];
    }
    return result;
}

// the total runtime is O(n)
my_pair find_mode_and_numbers_repeated_more_than_once(const vector<int>& A){
    auto hist = histogram_generator(A); // O(n)
    vector<int> modes;
    vector<int> numbers_repeated_more_than_once;
    int max_count = 0;
    // O(n)
    for(int i = 0;i < hist.size();i++){
        max_count = max(max_count, hist[i]);
    }
    // O(n)
    for(int i = 0;i < hist.size();i++){
        if(hist[i] == max_count){
            modes.emplace_back(i);
        }

        if(hist[i] > 1){
            numbers_repeated_more_than_once.push_back(i);
        }
    }
    return {modes, hist, numbers_repeated_more_than_once};
}

void display_arr(const vector<int>& arr){
    for(int e : arr) cout << e << " ";
}

int main() {
    string userinput;
    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    while (get_line("enter a positive integer n: ", userinput)) {
        int n = stoi(userinput);
        uniform_int_distribution<int> uniform_int_distribution(0, n - 1);
        vector<int> a;
        for(int i = 0;i < n;i++){
            a.push_back(uniform_int_distribution(gen));
        }
        cout << "a: [";
        display_arr(a);
        cout << "]" << endl;
        auto the_pair = find_mode_and_numbers_repeated_more_than_once(a);
        cout << "modes:";
        for (const auto &mode : the_pair.modes) {
            cout << " " << mode;
        }
        cout << endl;
        for(const auto &repeated_number : the_pair.repeated){
            cout << repeated_number << " was repeated "  << the_pair.hist[repeated_number] << " times" << endl;
        }
    }
}

