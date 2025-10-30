# CSE304-2025-2-Algorithms
# Week04-2.6.quicksort_problem.py

def partition(low, high, S):
    pivotitem = S[low]
    j = low
    for i in range(low + 1, high + 1):
        if S[i] < pivotitem:
            j += 1
            S[i], S[j] = S[j], S[i]
    S[low], S[j] = S[j], S[low]
    return j

def quicksort(low, high, S):
    if low < high:
        pivotpoint = partition(low,high,S)

        quicksort(low,pivotpoint-1,S)
        quicksort(pivotpoint+1,high,S)


########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_partition(S, expected_S, expected_pivot):
    print("Before partition:", S)
    pivotpoint = partition(0, len(S) - 1, S)
    print("After partition:", S)
    
    if S == expected_S and pivotpoint == expected_pivot:
        print("✅Test Passed!")
    else:
        print(f"❌Test Failed!")
        print(f"Expected result: {expected_S}, {expected_pivot}")
        print(f"Your Result: {S}, {pivotpoint}")
    print("-" * 40)


def test_quicksort(S, expected_S):
    print("Before quicksort:", S)
    quicksort(0, len(S) - 1, S)
    print("After quicksort:", S)
    
    if S == expected_S:
        print("✅Test Passed!")
    else:
        print(f"❌Test Failed!")
        print(f"Expected result: {expected_S}")
        print(f"Your Result: {S}")
    print("-" * 40)



print("**************Testing partition()**************")
print("######Example 1######")
test_partition([17, 19, 39, 41, 73], [17, 19, 39, 41, 73], 0)
print("######Example 2######")
test_partition([73, 41, 39, 19, 17], [17, 41, 39, 19, 73], 4)
print("######Example 3######")
test_partition([39, 41, 19, 74, 17], [17, 19, 39, 74, 41], 2)

print("**************Testing quicksort()**************")
print("######Example 4######")
test_quicksort([22, 98, 17, 16, 19, 73, 94, 41, 39, 66], [16, 17, 19, 22, 39, 41, 66, 73, 94, 98])
print("######Example 5######")
test_quicksort([5, 3, 8, 6, 2, 7, 4, 1], [1, 2, 3, 4, 5, 6, 7, 8])
########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 6 (Custom)
# test_partition(S, expected_S, expected_pivot)

# Example 7 (Custom)
# test_quicksort(S, expected_S)