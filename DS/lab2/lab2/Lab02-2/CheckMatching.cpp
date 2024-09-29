//
//  CheckMatching.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/09/24.
//

#include "CheckMatching.h"
#include <iostream>

bool checkMatching(char string[], int length) {
    StackType<char> tempStack;


    /* Implement the function here (Lab 02-2) */
    // This function checks if the "string" has MATCHED parentheses USING STACK
    // There are three kinds of parentheses (), [], {} and they are NOT INTERCHANGEABLE
    // For example,
    // "()" --> True
    // "(())" --> True
    // "()()" --> True  
    // "())" --> False
    // "(()" --> False
    // "(]" --> False
    // "([])" --> True
    // "({}()[])" --> True
    // Ignore all non-parenthesis characters.
    // "(abc)" --> True
    // "((abc)" --> False
    // it returns true, if it has MATCHED parentheses
    // Otherwise it returns false.

    for (int i = 0; i < length; i++) {
        char obj = string[i];

        if ((obj == '(') || (obj == '{') || (obj == '[')) {

            tempStack.push(obj);
        }
        else if ((obj == ')') || (obj == '}') || (obj == ']')) {

            if (tempStack.isEmpty()) {

                return false;
            }
            char look = tempStack.pop();

            if ((obj == ')' && look != '(') || (obj == '}' && look != '{') || (obj == ']' && look != '[')) {
                return false;
            }
        }
    }
    return tempStack.isEmpty();
}

