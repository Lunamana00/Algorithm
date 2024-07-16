#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        list<char> L;
        string s;
        cin >> s;
        auto cursor = L.end();
        for (int i = 0; i < s.length(); i++) {
            if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] < '9')) {
                L.insert(cursor, s[i]);
            }
            else if (cursor != L.begin() && s[i] == '<') {
                cursor--;
            }
            else if (cursor != L.end() && s[i] == '>') {
                cursor++;
            }
            else if (cursor != L.begin() && s[i] == '-') {
                cursor = L.erase(--cursor);
            }
        }
        for (auto x : L) {
            cout << x;
        }
        cout << '\n';
    }
}
