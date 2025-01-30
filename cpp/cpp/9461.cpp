#include <iostream>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    cin >> T;

    long long dp[101] = { 0 };
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    while (T--) {
        cin >> N;
        for (int i = 6; i <= N; ++i) {
            if (dp[i] == 0)
            {
                dp[i] = dp[i - 1] + dp[i - 5];
            }
        }
        cout << dp[N] << "\n";
    }
}
