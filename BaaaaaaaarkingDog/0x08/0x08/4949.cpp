#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string input;
        getline(cin, input);

        if (input == ".") break;

        stack<char> _stack;
        bool flag = false;

        for (char _input : input) {
            if (_input == '(' || _input == '[') {
                _stack.push(_input);
            }
            else if (_input == ')') {
                if (_stack.empty() || _stack.top() != '(') {
                    flag = true;
                    break;
                }
                _stack.pop();
            }
            else if (_input == ']') {
                if (_stack.empty() || _stack.top() != '[') {
                    flag = true;
                    break;
                }
                _stack.pop();
            }
        }

        if (!_stack.empty()) flag = true;

        cout << (flag ? "no" : "yes") << '\n';
    }
}

