#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        string commands, arrayStr;
        int n;
        cin >> commands >> n >> arrayStr;

        deque<int> dq;
        int num = 0;
        bool isNumber = false;

        for (char c : arrayStr) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                isNumber = true;
            }
            else if (isNumber) {
                dq.push_back(num);
                num = 0;
                isNumber = false;
            }
        }

        bool reverse = false, error = false;

        for (char cmd : commands) {
            if (cmd == 'R') {
                reverse = !reverse;
            }
            else if (cmd == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (reverse) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }

        if (error) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if (!dq.empty()) {
                if (reverse) {
                    for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                        cout << *it;
                        if (it + 1 != dq.rend()) {
                            cout << ",";
                        }
                    }
                }
                else {
                    for (auto it = dq.begin(); it != dq.end(); ++it) {
                        cout << *it;
                        if (it + 1 != dq.end()) {
                            cout << ",";
                        }
                    }
                }
            }
            cout << "]\n";
        }
    }
}

