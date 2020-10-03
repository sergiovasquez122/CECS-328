def binary_search(A):
    lo, hi = 0, len(A) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        value = mid * mid + 1
        if A[mid] < value:
            lo = mid + 1
        elif A[mid] > value:
            hi = mid - 1
        else: 
            return True
    return False
