# CSE304-2025-2-Algorithms
# Week08-4.7.0-1_knapsack_problem.py

def knapsack(n, W, DP):
    global w, p
    if (n, W) in DP:
        return DP[(n, W)]

    if n == 0 or W <= 0:
        DP[(n, W)] = 0
    else:
        if w[n - 1] <= W:
            DP[(n, W)] = max(p[n - 1] + knapsack(n - 1, W - w[n - 1], DP), knapsack(n - 1, W, DP))
        else:
            DP[(n, W)] = knapsack(n - 1, W, DP)

    return DP[(n, W)]


########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################

def test_knapsack_01_dp(n, W, w_input, p_input, expected=None):
    global w, p
    w = w_input
    p = p_input

    print(f"아이템 수: {n}")
    print(f"배낭 용량: {W}")
    print(f"무게: {w}")
    print(f"이익: {p}")
    DP = {}
    maxprofit = knapsack(n, W, DP)
    print(f"maxprofit: {maxprofit}")
    if expected is not None:
        if maxprofit == expected:
            print("✅ 테스트 통과: maxprofit 일치")
        else:
            print(f"❌ 테스트 실패: 기대값 = {expected}, 출력값 = {maxprofit}")
    print("-" * 40)


if __name__ == "__main__":
    print("**************Testing knapsack()**************")

    print("######Example 1######")
    n1, W1 = 3, 30
    w1 = [5, 10, 20]
    p1 = [50, 60, 140]
    test_knapsack_01_dp(n1, W1, w1, p1, expected=200)

    print("######Example 2######")
    n2, W2 = 4, 50
    w2 = [10, 20, 30, 40]
    p2 = [60, 100, 120, 240]
    test_knapsack_01_dp(n2, W2, w2, p2, expected=300)

    print("######Example 3######")
    n3, W3 = 5, 15
    w3 = [2, 3, 4, 5, 9]
    p3 = [3, 4, 5, 8, 10]
    test_knapsack_01_dp(n3, W3, w3, p3, expected=20)

    print("######Example 4######")
    n4, W4 = 8, 35
    w4 = [3, 8, 7, 6, 12, 4, 5, 10]
    p4 = [8, 20, 18, 14, 30, 10, 12, 25]
    test_knapsack_01_dp(n4, W4, w4, p4, expected=88)

########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 5 (Custom)
# test_knapsack_01_dp(n, W, w_input, p_input, expected)