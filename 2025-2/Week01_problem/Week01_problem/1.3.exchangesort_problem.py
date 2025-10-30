# CSE304-2025-2-Algorithms
# Week01-1.3.exchangesort.py

def exchangesort(n, S):
    
    for i in range(n-1):
        if S[i] > S[i+1]:
            S[i], S[i+1] = S[i+1], S[i]

########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_case(S, expected):
    n = len(S)
    data = S.copy()
    exchangesort(n, data)
    if data == expected:
        print("Test Passed!")
    else:
        print("Test Failed!")
    print(f"Input array: {S}")
    print(f"Expected result: {expected}")
    print(f"Your result: {data}")
    print("-" * 40)

# Example 1
print("###### Example 1 ######")
S = [10, 7, 11, 5, 13, 8]
test_case(S, sorted(S))

# Example 2
print("###### Example 2 ######")
S = []
test_case(S, sorted(S))

# Example 3
print("###### Example 3 ######")
S = [1, 2, 3, 4, 5]
test_case(S, sorted(S))

# Example 4
print("###### Example 4 ######")
S = [3, 1, 2, 1]
test_case(S, sorted(S))

# Example 5
print("###### Example 5 ######")
S = [42]
test_case(S, sorted(S))
########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 6 (Custom)
# S = [...]
# test_case(S, sorted(S))