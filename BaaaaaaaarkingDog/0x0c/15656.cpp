#include <vector>
#include <iostream>
#include <algorithm>

int checkList[10001];

using namespace std;

void func(vector<int> V, int M, int cur, vector<int>& printV) {

	if (printV.size() == M) {

		for (auto x : printV) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < V.size(); i++) {


		printV.push_back(V[i]);
		func(V, M, i + 1, printV);
		printV.pop_back();

	}

	return;

}

int main() {

	int N, M, x;
	vector<int> V;


	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> x;
		V.push_back(x);

	}
	vector<int> printV;
	sort(V.begin(), V.end());



	func(V, M, 0, printV);

}