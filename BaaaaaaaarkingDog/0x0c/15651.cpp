#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> vStack;


void func(int k, int cur) {


	if (vStack.size() == M) {
		for (auto x:vStack){
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1;i < N + 1;i++) {
		vStack.push_back(i);
		func(k + 1, i);
		vStack.pop_back();
	}
}

int main() {
	cin >> N >> M;
	func(0, 0);
}