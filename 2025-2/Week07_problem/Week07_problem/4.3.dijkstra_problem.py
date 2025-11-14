# CSE304-2025-2-Algorithms
# Week07-4.3.dijkstra_problem.py

def dijkstra(n, W):
    F = []
    touch = [-1] * (n + 1)
    length = [-1] * (n + 1)
    
    for i in range(2, n + 1):
        touch[i] = 1
        length[i] = W[1][i]
        
    for _ in range(n - 1):
        min = float("inf")

        for i in range(2, n + 1):
            if 0 <= length[i] < min:
                min = length[i]
                vnear = i
                
        F.append((touch[vnear], vnear, W[touch[vnear]][vnear]))
        
        for i in range(2, n + 1):
            if length[vnear] + W[vnear][i] < length[i]:
                length[i] = length[vnear] + W[vnear][i]
                touch[i] = vnear

        length[vnear] = -1
        
    return F


########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################

INF = float("inf")

def test_dijkstra_shortest_paths(n, W, source=1, expected=None):
    print(f"그래프 정점 수: {n}, 출발점: {source}")
    print("인접 행렬:")
    for i in range(1, n + 1):
        row = []
        for j in range(1, n + 1):
            if W[i][j] == float("inf"):
                row.append("INF")
            else:
                row.append(W[i][j])
        print(row)
    
    result = dijkstra(n, W)
    print(f"최단 경로 간선 (시작, 끝, 가중치): {result}")
    
    paths = {}
    weights = {}
    for v in range(2, n + 1):
        path = [v]
        current = v
        while current != source:
            found = False
            for edge in result:
                if edge[1] == current:
                    path.insert(0, edge[0])
                    current = edge[0]
                    found = True
                    break
            if not found:
                break
        
        if path[0] == source:
            paths[v] = path
            total_weight = 0
            for i in range(len(path) - 1):
                total_weight += W[path[i]][path[i + 1]]
            weights[v] = total_weight
    
    print("최단 경로:")
    for v in range(2, n + 1):
        if v in paths:
            print(f"  {source} -> {v}: {paths[v]} (가중치: {weights[v]})")
        else:
            print(f"  {source} -> {v}: 경로 없음")
    
    if expected is not None:
        all_match = True
        for dest, expected_weight in expected.items():
            if dest not in weights or weights[dest] != expected_weight:
                all_match = False
                break
        
        if all_match:
            print("✅Test Passed! 모든 최단 경로 가중치가 일치합니다.")
        else:
            print("❌Test Failed!")
            for dest, expected_weight in expected.items():
                if dest not in weights:
                    print(f"  목적지 {dest}: 경로를 찾을 수 없음, 기대 가중치: {expected_weight}")
                elif weights[dest] != expected_weight:
                    print(f"  목적지 {dest}: 출력 가중치: {weights[dest]}, 기대 가중치: {expected_weight}")
    print("-" * 40)


print("**************Testing dijkstra()**************")
print("######Example 1######")
W1 = [
    [INF, INF, INF, INF, INF, INF],
    [INF, 0, 1, 3, 6, INF],
    [INF, 1, 0, 3, 6, INF],
    [INF, 3, 3, 0, 2, 2],
    [INF, 6, 6, 2, 0, 5],
    [INF, INF, INF, 2, 5, 0]
]
expected1 = {2: 1, 3: 3, 4: 5, 5: 5}
test_dijkstra_shortest_paths(5, W1, expected=expected1)

print("######Example 2######")
W2 = [
    [INF, INF, INF, INF, INF],
    [INF, 0, 3, 12, 7],
    [INF, 3, 0, 5, 4],
    [INF, 12, 5, 0, 6],
    [INF, 7, 4, 6, 0]
]
expected2 = {2: 3, 3: 8, 4: 7}
test_dijkstra_shortest_paths(4, W2, expected=expected2)

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
expected3 = {2: 3, 3: 2, 4: 8, 5: 5, 6: 11}
test_dijkstra_shortest_paths(6, W3, expected=expected3)

print("######Example 4######")
W4 = [
    [INF, INF, INF, INF, INF, INF, INF, INF],
    [INF, 0, 2, 5, 1, INF, INF, INF],
    [INF, INF, 0, 3, 2, INF, INF, INF],
    [INF, INF, INF, 0, INF, 3, 10, INF],
    [INF, INF, INF, 5, 0, 2, INF, 7],
    [INF, INF, INF, INF, INF, 0, 1, 4],
    [INF, INF, INF, INF, INF, INF, 0, 6],
    [INF, INF, INF, INF, INF, INF, INF, 0]
]
expected4 = {2: 2, 3: 5, 4: 1, 5: 3, 6: 4, 7: 7}
test_dijkstra_shortest_paths(7, W4, expected=expected4)

########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 5 (Custom)
# test_dijkstra_shortest_paths(n, W, expected)
