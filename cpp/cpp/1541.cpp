#include <iostream>
#include <string>
using namespace std;

int main() {
    string expression;
    cin >> expression;

    int result = 0;
    int currentNumber = 0;
    bool isMinus = false;

    for (char c : expression) {
        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        }
        else {
            if (isMinus) {
                result -= currentNumber;
            }
            else {
                result += currentNumber;
            }
            currentNumber = 0;
            if (c == '-') {
                isMinus = true;
            }
        }
    }

    if (isMinus) {
        result -= currentNumber;
    }
    else {
        result += currentNumber;
    }

    cout << result << '\n';
    return 0;
}
