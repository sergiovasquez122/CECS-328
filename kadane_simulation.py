def kandane(a):
    max_sum = 0
    curr_sum = 0
    mss_at_iteration_i = []
    curr_sum_at_iteration_i = []
    for x in a:
        curr_sum += x
        if curr_sum > max_sum:
            max_sum = curr_sum
        elif curr_sum < 0:
            curr_sum = 0
        mss_at_iteration_i.append(max_sum)
        curr_sum_at_iteration_i.append(curr_sum)
    return (mss_at_iteration_i, curr_sum_at_iteration_i)
