# CSE304-2025-2-Algorithms
# Week08-4.5.huffman_problem.py

from heapq import heappush, heappop

class Node:
    def __init__(self, symbol, freq):
        self.symbol = symbol
        self.freq = freq
        self.left = None
        self.right = None
        
    def preorder(self, path):
        path.append((self.symbol, self.freq))
        if self.left != None:
            self.left.preorder(path)
        if self.right != None:
            self.right.preorder(path)

    def inorder(self, path):
        if self.left != None:
            self.left.inorder(path)
        path.append((self.symbol, self.freq))
        if self.right != None:
            self.right.inorder(path)

def huffman(n, s, f):
    heap = []
    for i in range(n):
        heappush(heap, (f[i], Node(s[i], f[i])))

    while len(heap) > 1:
        freq1, left_node = heappop(heap)
        freq2, right_node = heappop(heap)

        new_node = Node('*', freq1 + freq2)
        new_node.left = left_node
        new_node.right = right_node

        heappush(heap, (new_node.freq, new_node))

    return heappop(heap)[1]

########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################

def print_huffman_tree(root):
    path = []
    root.preorder(path)
    print("preorder =", path)
    path = []
    root.inorder(path)
    print("inorder =", path)


def test_huffman(n, s, f, expected_preorder=None, expected_inorder=None):
    print(f"문자 개수: {n}")
    print(f"문자: {s}")
    print(f"빈도: {f}")
    root = huffman(n, s, f)

    path_pre = []
    root.preorder(path_pre)
    print(f"preorder: {path_pre}")
    path_in = []
    root.inorder(path_in)
    print(f"inorder: {path_in}")

    if expected_preorder is not None:
        if path_pre == expected_preorder:
            print("✅ preorder 일치")
        else:
            print("❌ preorder 불일치")

    if expected_inorder is not None:
        if path_in == expected_inorder:
            print("✅ inorder 일치")
        else:
            print("❌ inorder 불일치")

    print("-" * 40)


if __name__ == "__main__":
    print("**************Testing huffman()**************")

    print("######Example 1######")
    n1 = 6
    s1 = ['b', 'e', 'c', 'a', 'd', 'f']
    f1 = [5, 10, 12, 16, 17, 25]
    expected_pre1 = [('*', 85), ('*', 33), ('a', 16), ('d', 17), ('*', 52), ('f', 25), ('*', 27), ('c', 12), ('*', 15), ('b', 5), ('e', 10)]
    expected_in1 = [('a', 16), ('*', 33), ('d', 17), ('*', 85), ('f', 25), ('*', 52), ('c', 12), ('*', 27), ('b', 5), ('*', 15), ('e', 10)]
    test_huffman(n1, s1, f1, expected_pre1, expected_in1)

    print("######Example 2######")
    n2 = 4
    s2 = ['x', 'y', 'z', 'w']
    f2 = [3, 7, 8, 12]
    expected_pre2 = [('*', 30), ('w', 12), ('*', 18), ('z', 8), ('*', 10), ('x', 3), ('y', 7)]
    expected_in2 = [('w', 12), ('*', 30), ('z', 8), ('*', 18), ('x', 3), ('*', 10), ('y', 7)]
    test_huffman(n2, s2, f2, expected_pre2, expected_in2)

    print("######Example 3######")
    n3 = 5
    s3 = ['m', 'n', 'o', 'p', 'q']
    f3 = [2, 3, 7, 9, 13]
    expected_pre3 = [('*', 34), ('q', 13), ('*', 21), ('p', 9), ('*', 12), ('*', 5), ('m', 2), ('n', 3), ('o', 7)]
    expected_in3 = [('q', 13), ('*', 34), ('p', 9), ('*', 21), ('m', 2), ('*', 5), ('n', 3), ('*', 12), ('o', 7)]
    test_huffman(n3, s3, f3, expected_pre3, expected_in3)

########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 4 (Custom)
# test_huffman(n, s, f, expected_preorder, expected_inorder)
