#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    for (int coin : coins) {
        count += k / coin;
        k %= coin;
        if (k == 0) break;
    }
    cout << count << endl;
}