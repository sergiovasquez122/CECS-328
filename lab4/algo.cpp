// O(n)
void k_closest_to_median(vector<int>& arr, int k){
    double median = median_selection(arr); // O(n)
    vector<my_pair> diff;
    // O(n)
    for(int e : arr){
        diff.push_back({abs(e - median), e});
    }
    // O(n)
    int kth_idx = quick_select_idx(diff, k);
    //O(n)
    for(int i = kth_idx; i >= 0;i--){
        cout << diff[i].y << " ";
    }
    cout << endl;
}

