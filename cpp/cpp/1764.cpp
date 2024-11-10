#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string s_temp;
    set<string> set_v1;
    set<string> set_v2;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s_temp;
        set_v1.insert(s_temp);
    }

    for (int i = 0; i < M; i++) {
        cin >> s_temp;
        if (set_v1.find(s_temp) != set_v1.end()) {
            set_v2.insert(s_temp);
        }
    }

    cout << set_v2.size() << '\n';
    for (auto& x : set_v2) {
        cout << x << '\n';
    }
}

