#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    list<int> circle;
    vector<int> result;

    for (int i = 1; i <= N; ++i) {
        circle.push_back(i);
    }

    auto it = circle.begin();

    while (!circle.empty()) {
        for (int i = 1; i < K; ++i) {
            ++it;
            if (it == circle.end()) {
                it = circle.begin();
            }
        }
        result.push_back(*it);
        it = circle.erase(it);
        if (it == circle.end()) {
            it = circle.begin();
        }
    }
    cout << '<';
    for (int i = 0; i < N - 1;i++) {
        cout << result[i] << ", ";
    }
    cout << result[N-1] <<'>';
}
