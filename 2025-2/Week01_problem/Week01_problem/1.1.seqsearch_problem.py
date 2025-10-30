# CSE304-2025-2-Algorithms
# Week01-1.1.seqsearch.py

def seqsearch(n, S, x):
    location = 0
    
    # Complete the code here

    while location < n:
        if S[location] == x:
            return location
        location += 1

    return -1
########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_case(S, x, expected):
    n = len(S)
    result = seqsearch(n, S, x)
    if result == expected:
        print(f"Test Passed!")
    else:
        print(f"Test Failed!")
    print(f"Input array: {S}")
    print(f"Target value: {x}")
    print(f"Expected location: {expected}")
    print(f"Your location: {result}")
    print("-" * 40)

# Example 1
print("###### Example 1 ######")
S = [10, 7, 11, 5, 13, 8]
x = 10
expected = 0
test_case(S, x, expected)

# Example 2
print("###### Example 2 ######")
S = []
x = 5
expected = -1
test_case(S, x, expected)

# Example 3 
print("###### Example 3 ######")
S = [99]
x = 99
expected = 0
test_case(S, x, expected)

# Example 4
print("###### Example 4 ######")
S = [99]
x = 100
expected = -1
test_case(S, x, expected)

# Example 5
print("###### Example 5 ######")
S = [1, 2, 3, 2, 5, 2]
x = 2
expected = 1
test_case(S, x, expected)

# Example 6
print("###### Example 6 ######")
S = [7, 7, 7, 7, 7, 7]
x = 7
expected = 0
test_case(S, x, expected)

########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 7 (Custom)
# S = [...]
# x = 
# expected =
# test_case(S, x, expected)