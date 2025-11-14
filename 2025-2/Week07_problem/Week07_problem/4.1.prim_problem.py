# CSE304-2025-2-Algorithms
# Week07-4.1.prim_problem.py

def prim(n, W):
    F = []
    nearest = [-1] * (n + 1)
    distance = [-1] * (n + 1)
    
    for i in range(2, n + 1):
        nearest[i] = 1
        distance[i] = W[1][i]
        
    for _ in range(n - 1):
        min = float("inf")
        vnear = -1
        
        for i in range(2, n + 1):
            if 0 <= distance[i] < min:
                min = distance[i]
                vnear = i
                
        F.append((nearest[vnear], vnear, W[nearest[vnear]][vnear]))
        distance[vnear] = -1
        
        for i in range(2, n + 1):
            if W[vnear][i] < distance[i]:
                distance[i] = W[vnear][i]
                nearest[i] = vnear
    return F


########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################

def test_prim_mst(n, W, expected=None):
    print(f"그래프 정점 수: {n}")
    print("인접 행렬:")
    for i in range(1, n + 1):
        row = []
        for j in range(1, n + 1):
            if W[i][j] == float("inf"):
                row.append("INF")
            else:
                row.append(W[i][j])
        print(row)
    
    result = prim(n, W)
    print(f"최소 신장 트리 간선 (시작, 끝, 가중치): {result}")
    print(f"총 가중치: {sum(edge[2] for edge in result)}")
    
    if expected is not None:
        expected_weight = sum(edge[2] for edge in expected)
        actual_weight = sum(edge[2] for edge in result)
        
        if sorted([(e[0], e[1]) for e in result]) == sorted([(e[0], e[1]) for e in expected]) and \
           actual_weight == expected_weight:
            print("✅Test Passed! 최소 신장 트리가 일치합니다.")
        else:
            print("❌Test Failed!")
            print(f"Expected edges: {expected}")
            print(f"Your Result: {result}")
            print(f"Expected weight: {expected_weight}, Your weight: {actual_weight}")
    print("-" * 40)


INF = float("inf")

print("**************Testing prim()**************")
print("######Example 1######")
W1 = [
    [INF, INF, INF, INF, INF, INF],
    [INF, 0, 1, 3, INF, INF],
    [INF, 1, 0, 3, 6, INF],
    [INF, 3, 3, 0, 4, 2],
    [INF, INF, 6, 4, 0, 5],
    [INF, INF, INF, 2, 5, 0]
]
expected1 = [(1, 2, 1), (1, 3, 3), (3, 5, 2), (3, 4, 4)]
test_prim_mst(5, W1, expected1)

print("######Example 2######")
W2 = [
    [INF, INF, INF, INF, INF],
    [INF, 0, 10, 15, 20],
    [INF, 10, 0, 35, 25],
    [INF, 15, 35, 0, 30],
    [INF, 20, 25, 30, 0]
]
expected2 = [(1, 2, 10), (1, 3, 15), (1, 4, 20)]
test_prim_mst(4, W2, expected2)

print("######Example 3######")
W3 = [
    [INF, INF, INF, INF, INF, INF, INF],
    [INF, 0, 4, 2, INF, INF, INF],
    [INF, 4, 0, 1, 5, 2, INF],
    [INF, 2, 1, 0, 8, 3, INF],
    [INF, INF, 5, 8, 0, 7, 9],
    [INF, INF, 2, 3, 7, 0, 6],
    [INF, INF, INF, INF, 9, 6, 0]
]
expected3 = [(1, 3, 2), (3, 2, 1), (2, 5, 2), (5, 6, 6), (2, 4, 5)]
test_prim_mst(6, W3, expected3)

########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 4 (Custom)
# test_prim_mst(n, W, expected)
