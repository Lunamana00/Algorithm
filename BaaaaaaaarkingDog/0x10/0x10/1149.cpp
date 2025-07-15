#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int memo[3000007];
int route[3000007];
int N, save;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;
	memo[4] = 2;

	while (!memo[N]) {
		for (int i = 1; i < N;i++) {
			if (memo[3 * i] > memo[i] || !memo[3 * i]) {
				memo[3 * i] = memo[i] + 1;
				route[3 * i] = i;
			}
			if (memo[2 * i] > memo[i] || !memo[2 * i]) {
				memo[2 * i] = memo[i] + 1;
				route[2 * i] = i;
			}
			if (memo[i+1] > memo[i] || !memo[i+1]) {
				memo[i+1] = memo[i] + 1;
				route[i+1] = i;
			}
		}
	}
	cout << memo[N] << '\n' << N << ' ';
	save = route[N];
	for (int i = memo[N];i > 0; i--) {
		cout << save << ' ';
		save = route[save];
	}	
	return 0;
}