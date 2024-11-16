#include <iostream>
#include <stack>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<pair<int, int>> s;
    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        int height, count = 1;
        cin >> height;

        while (!s.empty() && s.top().first <= height) {
            ans += s.top().second;
            if (s.top().first == height) {
                count += s.top().second;
            }
            s.pop();
        }

        if (!s.empty()) {
            ans += 1;
        }

        s.push({ height, count });
    }

    cout << ans;
}
