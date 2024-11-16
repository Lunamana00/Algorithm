#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> q;
    string command;

    for (int i = 0; i < N; ++i) {
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (command == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (command == "size") {
            cout << q.size() << '\n';
        }
        else if (command == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else if (command == "front") {
            if (!q.empty()) {
                cout << q.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (command == "back") {
            if (!q.empty()) {
                cout << q.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}
