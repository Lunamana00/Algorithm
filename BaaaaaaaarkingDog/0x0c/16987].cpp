#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> egg_list;
int N;
int max_broken = 0;


void egg(int k) {

    if (k == N) {
        int broken_count = 0;
        for (int i = 0; i < N; i++) {
            if (egg_list[i].first <= 0) {
                broken_count++;
            }
        }
        max_broken = max(max_broken, broken_count);
        return;
    }

    if (egg_list[k].first <= 0) {
        egg(k + 1);
    }

    bool target_exists = false;

    for (int target = 0; target < N; target++) {

        if (k == target) continue;

        if (egg_list[target].first > 0) {
            target_exists = true;

            egg_list[k].first -= egg_list[target].second;
            egg_list[target].first -= egg_list[k].second;

            egg(k + 1);

            egg_list[k].first += egg_list[target].second;
            egg_list[target].first += egg_list[k].second;
        }
    }

    if (!target_exists) {
        egg(k + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int S, W;
        cin >> S >> W;
        egg_list.push_back({ S, W });
    }

    egg(0);

    cout << max_broken << "\n";

    return 0;
}