#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> isused(9);


void func(int k, int cur) {


	if (k == M) {
		for (int i = 1;i < N + 1;i++) {
			if (isused[i]) {
				cout << i << ' ';
			}
		}
		cout << '\n';
		return;
	}

	for (int i = cur + 1;i < N+1;i++) {
		isused[i] = 1;
		func(k + 1, i);
		isused[i] = 0;
	}
}

int main() {
	cin >> N >> M;
	func(0, 0);
}