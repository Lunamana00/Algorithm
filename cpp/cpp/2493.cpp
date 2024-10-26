#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights(N);
    vector<int> result(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    stack<int> stack;  

    for (int i = 0; i < N; ++i) {

        while (!stack.empty() && heights[stack.top()] < heights[i]) {
            stack.pop();
        }

        if (!stack.empty()) {
            result[i] = stack.top() + 1;
        }

        stack.push(i);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
}
