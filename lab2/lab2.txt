#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>

using namespace std;

bool get_line(string& line, const string& prompt){
	cout << prompt;
	getline(cin, line);
	return !line.empty();
}

vector<int> generate_array(int m){
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<int> uniformIntDistribution(1, m - 1);
	int result_size = uniformIntDistribution(gen);
	vector<int> candidates(m);
	iota(candidates.begin(), candidates.end(), 0); // generate candidates from [0, m - 1]
	shuffle(candidates.begin(), candidates.end(), gen); // shuffle the candidates into random order
	vector<int> result(result_size);
	for(int i = 0;i < result.size();i++)
		result[i] = candidates[i];
	sort(result.begin(), result.end());
	return result;
}

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

void display_array(const vector<int>& a){
	cout << "[";
	for(int e : a) cout << e << " ";
	cout << "]";
}

int main(){
	string userinput;
	// part1 
	while(get_line(userinput, "(part a) enter a non-negative integer: ")){
		int x = stoi(userinput);
		cout << "ceiling of the square root of x is: " << square_root(x) << endl;
	}
	// part2
	while(get_line(userinput, "(part b) enter a positive integer: ")){
		int m = stoi(userinput);
		auto a = generate_array(m);
		cout << "input: ";
		display_array(a);
		cout << " " << m << endl;
		cout << "output: " << find_smallest_missing_number(a) << endl;
	}
}
