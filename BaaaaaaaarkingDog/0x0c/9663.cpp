#include <iostream>
#include <vector>

using namespace std;

int Q_Count = 0;
int N;
vector<int> isused1(40);
vector<int> isused2(40);
vector<int> isused3(40);

void func(int K) {
	if (N == K) {
		Q_Count++;
		return;
	}

	for (int row = 0; row < N; row++) {
		if (isused1[row] || isused2[row+K]||isused3[K-row+N-1]) {
			continue;
		}
		isused1[row] = 1;
		isused2[row+K] = 1;
		isused3[K - row + N - 1] = 1;
		func(K + 1);
		isused1[row] = 0;
		isused2[row + K] = 0;
		isused3[K - row + N - 1] = 0;

	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	func(0);
	cout << Q_Count;
}