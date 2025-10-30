# CSE304-2025-2-Algorithms
# Week01-leetcode_1480.py
# https://leetcode.com/problems/running-sum-of-1d-array

class Solution(object):
    def runningSum(self, nums):
        results = [nums[0]]

        # Complete the code here
        for i in range(1,len(nums)):
            results.append(results[i-1]+nums[i])

        return results

########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_case(nums, expected):
    sol = Solution()
    result = sol.runningSum(nums[:])  # copy to avoid mutation
    if result == expected:
        print("Test Passed!")
    else:
        print("Test Failed!")
    print(f"Input nums: {nums}")
    print(f"Expected result: {expected}")
    print(f"Your result: {result}")
    print("-" * 40)

# Example 1
print("###### Example 1 ######")
nums = [1, 2, 3, 4]
expected = [1, 3, 6, 10]
test_case(nums, expected)

# Example 2
print("###### Example 2 ######")
nums = [1, 1, 1, 1, 1]
expected = [1, 2, 3, 4, 5]
test_case(nums, expected)

# Example 3
print("###### Example 3 ######")
nums = [3, 1, 2, 10, 1]
expected = [3, 4, 6, 16, 17]
test_case(nums, expected)

# Example 4
print("###### Example 4 ######")
nums = [5]
expected = [5]
test_case(nums, expected)

# Example 5 
print("###### Example 5 ######")
nums = [2, 2, 2, 2, 2]
expected = [2, 4, 6, 8, 10]
test_case(nums, expected)

# Example 6 
print("###### Example 6 ######")
nums = [-1, 2, -3, 4]
expected = [-1, 1, -2, 2]
test_case(nums, expected)

# Example 7 
print("###### Example 7 ######")
nums = [1000000, -1000000, 1000000]
expected = [1000000, 0, 1000000]
test_case(nums, expected)

# Example 8 
print("###### Example 8 ######")
nums = [1] * 1000
expected = [i for i in range(1, 1001)]
test_case(nums, expected)
########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 9 (Custom)
# nums = [...]
# expected = [...]
# test_case(nums, expected)