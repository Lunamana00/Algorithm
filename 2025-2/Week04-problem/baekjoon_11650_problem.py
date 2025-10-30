# CSE304-2025-2-Algorithms
# Week04-baekjoon_11650_problem.py
# https://www.acmicpc.net/problem/11650

def quick_sort(points):
    if len(points) <= 1:
        return points
    
    pivot = points[0]
    j = 0
    for i in range(1, len(points)):
        if(pivot > points[i]):
            j += 1
            points[j], points[i] = points[i], points[j]
        if(pivot == points[i]):
            if(pivot[1] > points[i][1]):
                j += 1
                points[j], points[i] = points[i], points[j]

    points[0], points[j] = points[j], points[0]
    
    left = quick_sort(points[0:j])
    right = quick_sort(points[j+1:len(points)])
    return left + [points[j]] + right

########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test(input_data, expected):
    result = quick_sort(input_data)
    if result == expected:
        print("✅Test Passed!")
    else:
        print(f"❌Test Failed!")
    print(f"Expected result: {expected}")
    print(f"Your Result: {result}")
    print("-" * 40)


if __name__ == "__main__":
    print("######Example 1######")
    test([ (3, 4), (1, 1), (1, -1), (2, 2), (3, 3) ], [(1, -1), (1, 1), (2, 2), (3, 3), (3, 4)])
    
    print("######Example 2######")
    test([ (0, 0), (-1, 1), (1, -1), (-1, -1), (1, 1) ], [(-1, -1), (-1, 1), (0, 0), (1, -1), (1, 1)])
    
    print("######Example 3######")
    test([ (5, 5), (3, 3), (4, 4), (2, 2), (1, 1) ], [(1, 1), (2, 2), (3, 3), (4, 4), (5, 5)])

    print("######Example 4######")
    test([ (7, 8), (6, 7), (5, 6), (4, 5), (3, 4) ], [(3, 4), (4, 5), (5, 6), (6, 7), (7, 8)])

    print("######Example 5######")
    test([(0, 0)], [(0, 0)])

    print("######Example 6######")
    test([(15, 15), (13, 6), (18, 13), (9, 5), (19, 9), (16, 12), (6, 1), (10, 10), (0, 2), (5, 7), (4, 14), (1, 17), (14, 0), (2, 4), (3, 18), (7, 3), (8, 11), (17, 8), (12, 19), (11, 16)], 
        [(0, 2), (1, 17), (2, 4), (3, 18), (4, 14), (5, 7), (6, 1), (7, 3), (8, 11), (9, 5), (10, 10), (11, 16), (12, 19), (13, 6), (14, 0), (15, 15), (16, 12), (17, 8), (18, 13), (19, 9)])
########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 7 (Custom)
# test(input_data, expected)