# CSE304-2025-2-Algorithms
# Week05-3.6.minmatrixmult_problem.py

def minimum(i, j, M, d):
    minvalue, mink = float("inf"), 0
    for k in range(i, j):
        cost = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]
        if cost < minvalue:
            minvalue = cost
            mink = k

    return minvalue, mink 


def minmult(n, d):
    M = [[float("inf")] * (n + 1) for _ in range(n + 1)]
    P = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        M[i][i] = 0
    for diagonal in range(1, n):
        for j in range(1, n + 1):
            i = j - diagonal
            if i >= 1:
                M[i][j], P[i][j] = minimum(i, j, M, d)


    return M[1][n], M, P 


def order(i, j, P):
    if i == j:
        return "A" + str(i)
    else:
        # Complete the code here  
        return "(" + order(i, P[i][j], P) + " x " + order(P[i][j] + 1, j, P) + ")"



########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_minmult(n, d, expected=None):
    print("Before computation")
    print(f"n = {n}")
    print(f"d = {d}")

    minvalue, M, P = minmult(n, d)

    print("After computation")
    print("M = ")
    for i in range(1, n + 1):
        print(M[i][i:])
    print("P = ")
    for i in range(1, n + 1):
        print(P[i][i:])
    print("minmult =", minvalue)

    multorder = order(1, n, P)
    print("Order of multiplication:", multorder)

    if expected is not None:
        if minvalue == expected:
            print("✅Test Passed!")
        else:
            print("❌Test Failed!")
            print(f"Expected result: {expected}")
            print(f"Your Result: {minvalue}")
    print("-" * 40)


print("**************Testing minmult()**************")

print("######Example 1######")
test_minmult(6, [5, 2, 3, 4, 6, 7, 8], expected=348)

print("######Example 2######")
test_minmult(4, [10, 20, 30, 40, 30], expected=30000)

print("######Example 3######")
test_minmult(3, [10, 100, 5, 50], expected=7500)

########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 4 (Custom)
# test_minmult(n, d, expected)