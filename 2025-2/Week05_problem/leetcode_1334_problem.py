# CSE304-2025-2-Algorithms
# Week05-leetcode_1334_problem.py
# https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

from typing import List

def findTheCity(n: int, edges: List[List[int]], distanceThreshold: int) -> int:
    D = [[float('inf')] * n for _ in range(n)]
    # Complete the code here
    P = [[-1] * n for _ in range(n)]

    for i in range(n):
        D[i][i] = 0
    
    for u, v, w in edges:
        D[u][v] = w
        D[v][u] = w
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if D[i][j] > D[i][k] + D[k][j]:
                    D[i][j] = D[i][k] + D[k][j]
                    P[i][j] = P[k][j]
    min_count = n
    city = 0
    for i in range(n):
        count = 0
        for j in range(n):
            if D[i][j] <= distanceThreshold:
                count += 1
        if count <= min_count:
            min_count = count
            city = i
    return city
    

########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_findTheCity(n: int, edges: List[List[int]], distanceThreshold: int, expected: int):
    print("Before computation")
    print(f"n = {n}, distanceThreshold = {distanceThreshold}")
    print(f"edges = {edges}")

    result = findTheCity(n, edges, distanceThreshold)

    print(f"After computation: result = {result}")

    if result == expected:
        print("✅Test Passed!")
    else:
        print("❌Test Failed!")
        print(f"Expected result: {expected}")
        print(f"Your Result: {result}")
    print("-" * 40)


print("**************Testing findTheCity()**************")

print("######Example 1######")
test_findTheCity(4, [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], 4, 3)

print("######Example 2######")
test_findTheCity(5, [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], 2, 0)

print("######Example 3######")
test_findTheCity(6, [[0,1,10],[1,2,10],[2,3,10],[3,4,10],[4,5,10]], 20, 5)

print("######Example 4######")
test_findTheCity(2, [[0,1,5]], 2, 1)

print("######Example 5######")
test_findTheCity(9, [[0,1,1],[1,2,2],[2,3,3],[3,4,4],[4,5,5],[5,6,6],[6,7,7],[7,8,8]], 20, 8)

print("######Example 6######")
test_findTheCity(15, [
    [0,1,1],[1,2,2],[2,3,3],[3,4,4],[4,5,5],
    [5,6,6],[6,7,7],[7,8,8],[8,9,9],[9,10,10],
    [10,11,11],[11,0,12]
], 55, 14)

########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 7 (Custom)
# test_findTheCity(n, edges, distanceThreshold, expected)