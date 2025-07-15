#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string inputString;

    std::cin >> inputString;

    std::stack<char> stack;
    std::vector<int> v1;

    int count2 = 0;
    int count3 = 0;
    int calc2;
    int calc3;
    int pop_count = 0;
    int sum = 0;

    for (int i = 0; i < inputString.size(); i++) {

        if (inputString[i] == '(' ){
            stack.push(inputString[i]);
            count2++;
        }
        else if (inputString[i] == '[') {
            stack.push(inputString[i]);
            count3++;
        }
        else if (inputString[i] == ')') {

            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
                count2--;
                if(inputString[i-1] != ')' && inputString[i - 1] != ']'){
                    sum += 2 * std::pow(2, count2) * std::pow(3, count3);
                }
            }
            else {
                std::cout << 0;
                return 0;
            }
        }
        else {
            if (!stack.empty() && stack.top() == '[') {
                stack.pop();
                count3--;
                if (inputString[i - 1] != ')' && inputString[i - 1] != ']') {
                    sum += 3 * std::pow(2, count2) * std::pow(3, count3);
                }
            }
            else {
                std::cout << 0;
                return 0;
            }
        }
        //std::cout << count2 << ' '<< count3 <<' '<< sum << '\n';
    }
    if (!stack.empty()) {
        std::cout << 0;
        return 0;
    }
    std::cout << sum;
}