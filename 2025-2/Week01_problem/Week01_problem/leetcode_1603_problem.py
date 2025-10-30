# CSE304-2025-2-Algorithms
# Week01-leetcode_1603.py
# https://leetcode.com/problems/design-parking-system

class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.slot_big = big
        self.slot_mid = medium
        self.slot_small = small

    def addCar(self, carType: int) -> bool:
        # Complete the code here
        if(carType == 1):
            
            if(self.slot_big > 0):
                self.slot_big = self.slot_big-1
                return True
            else:
                return False
        elif(carType == 2):
            if(self.slot_mid > 0):
                self.slot_mid = self.slot_mid-1
                return True
            else:
                return False
        elif(carType == 3):
            if(self.slot_small > 0):
                self.slot_small = self.slot_small-1
                return True
            else:
                return False

########################################################################################
# DO NOT MODIFY THIS AREA!!
########################################################################################
def test_case(init_args, operations, expected):
    obj = ParkingSystem(*init_args)
    result = [None]
    for op, arg in operations:
        if op == "addCar":
            result.append(obj.addCar(*arg))
    if result == expected:
        print("Test Passed!")
    else:
        print("Test Failed!")
    print(f"Init args: {init_args}")
    print(f"Operations: {operations}")
    print(f"Expected result: {expected}")
    print(f"Your result: {result}")
    print("-" * 40)

# Example 1 
print("###### Example 1 ######")
init_args = (1, 1, 0)
operations = [("addCar", [1]), ("addCar", [2]), ("addCar", [3]), ("addCar", [1])]
expected = [None, True, True, False, False]
test_case(init_args, operations, expected)

# Example 2 
print("###### Example 2 ######")
init_args = (1, 1, 1)
operations = [("addCar", [1]), ("addCar", [2]), ("addCar", [3])]
expected = [None, True, True, True]
test_case(init_args, operations, expected)

# Example 3 
print("###### Example 3 ######")
init_args = (0, 0, 0)
operations = [("addCar", [1]), ("addCar", [2]), ("addCar", [3])]
expected = [None, False, False, False]
test_case(init_args, operations, expected)

# Example 4 
print("###### Example 4 ######")
init_args = (1, 1, 1)
operations = [
    ("addCar", [1]), ("addCar", [1]),
    ("addCar", [2]), ("addCar", [2]),
    ("addCar", [3]), ("addCar", [3]),
]
expected = [None, True, False, True, False, True, False]
test_case(init_args, operations, expected)

# Example 5 
print("###### Example 5 ######")
init_args = (2, 2, 1)
operations = [
    ("addCar", [1]), ("addCar", [2]), ("addCar", [3]),
    ("addCar", [1]), ("addCar", [2]),
    ("addCar", [3]), ("addCar", [1]), ("addCar", [2]),
]
expected = [None, True, True, True, True, True, False, False, False]
test_case(init_args, operations, expected)

# Example 6
print("###### Example 6 ######")
init_args = (0, 0, 0)
operations = [("addCar", [1]), ("addCar", [2]), ("addCar", [3])]
expected = [None, False, False, False]
test_case(init_args, operations, expected)

# Example 7 
print("###### Example 7 ######")
init_args = (1000, 1000, 1000)
operations = []
for _ in range(1000):
    operations.append(("addCar", [1]))
    operations.append(("addCar", [2]))
    operations.append(("addCar", [3]))
operations += [("addCar", [1]), ("addCar", [2]), ("addCar", [3])]
expected = [None] + [True, True, True] * 1000 + [False, False, False]
test_case(init_args, operations, expected)
########################################################################################
# END OF TEST CODE
########################################################################################

# You can add more cases
# Example 8 (Custom)
# init_args = (...)
# operations = [...]
# expected = [...]
# test_case(init_args, operations, expected)
