#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, n;
    cin >> T;

    int dp[11];
    dp[1] = 1; // 1을 만드는 경우의 수
    dp[2] = 2; // 2를 만드는 경우의 수
    dp[3] = 4; // 3을 만드는 경우의 수

    for (int i = 4; i <= 10; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

}