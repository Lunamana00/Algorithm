# CSE304-2025-2-Algorithms
# Week01-leetcode_1365.py
# https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        s_nums = sorted(nums)
        count = 0
        result = []
        # Complete the code here
        for i in range(len(nums)):
            count = 0
            for j in range(len(nums)):
                if(nums[i] > nums[j]):
                    count = count +1
            result.append(count)
        return result

########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_case(nums, expected):
    sol = Solution()
    result = sol.smallerNumbersThanCurrent(nums[:])  # copy to avoid mutation
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
nums = [8, 1, 2, 2, 3]
expected = [4, 0, 1, 1, 3]
test_case(nums, expected)

# Example 2
print("###### Example 2 ######")
nums = [6, 5, 4, 8]
expected = [2, 1, 0, 3]
test_case(nums, expected)

# Example 3
print("###### Example 3 ######")
nums = [7, 7, 7, 7]
expected = [0, 0, 0, 0]
test_case(nums, expected)

# Example 4 
print("###### Example 4 ######")
nums = [1, 2, 3, 4]
expected = [0, 1, 2, 3]
test_case(nums, expected)

# Example 5 
print("###### Example 5 ######")
nums = [4, 3, 2, 1]
expected = [3, 2, 1, 0]
test_case(nums, expected)

# Example 6
print("###### Example 6 ######")
nums = [5, 5, 5, 3, 1]
expected = [2, 2, 2, 1, 0]
test_case(nums, expected)

# Example 7 
print("###### Example 7 ######")
nums = [0, 100, 50]
expected = [0, 2, 1]
test_case(nums, expected)

# Example 8
print("###### Example 8 ######")
nums = [0, 0, 0]
expected = [0, 0, 0]
test_case(nums, expected)

# Example 9
print("###### Example 9 ######")
nums = [100, 100, 100]
expected = [0, 0, 0]
test_case(nums, expected)

# Example 10 
print("###### Example 10 ######")
nums = [1, 3, 5, 3, 1]
expected = [0, 2, 4, 2, 0]
test_case(nums, expected)

# Example 11
print("###### Example 11 ######")
nums = [10, 10, 5, 8, 5]
expected = [3, 3, 0, 2, 0]
test_case(nums, expected)

# Example 12
print("###### Example 12 ######")
nums = [11, 3, 7, 9, 3]
expected = [4, 0, 2, 3, 0]
test_case(nums, expected)
########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 13 (Custom)
# nums = [...]
# expected = [...]
# test_case(nums, expected)