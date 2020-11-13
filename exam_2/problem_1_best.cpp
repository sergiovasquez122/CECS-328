bool is_max_heapv1(const vector<int> &A){
    for(int i = (A.size() - 1) / 2;i >= 0;i--){
        int left_child_idx = 2 * i + 1;
        if(left_child_idx < A.size() && A[i] < A[left_child_idx])
            return false;
        int right_child_idx = 2 * i + 2;
        if(right_child_idx < A.size() && A[i] < A[right_child_idx])
            return false;
    }
    return true;
}
