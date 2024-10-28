#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int n, x;
    cin >> n;
    string order;

    while (n--) {
        cin >> order;
        if (order == "push") {
            cin >> x;
            v.push_back(x);
        }
        else if (order == "pop") {
            if (!v.empty()) {
                cout << v.front() << "\n";
                v.erase(v.begin());
            }
            else {
                cout << "-1\n";
            }
        }
        else if (order == "size") {
            cout << v.size() << "\n";
        }
        else if (order == "empty") {
            cout << (v.empty() ? "1" : "0") << "\n";
        }
        else if (order == "front") {
            if (!v.empty()) {
                cout << v.front() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (order == "back") {
            if (!v.empty()) {
                cout << v.back() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
    }
}