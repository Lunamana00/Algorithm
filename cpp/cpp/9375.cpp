#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        unordered_map<string, int> clothes;
        string type, name;

        for (int i = 0; i < n; ++i) {
            cin >> name >> type;
            clothes[type]++;
        }

        int result = 1;

        for (auto it = clothes.begin(); it != clothes.end(); ++it) {
            result *= (it->second + 1);
        }

        cout << result - 1 << '\n';
    }
}
