#include <vector>
#include <iostream>
#include <algorithm>

int checkList[10001];

using namespace std;

void func(vector<int> V, int M, vector<int> &printV) {

	if (printV.size() == M) {

		for (auto x : printV) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}
	
	for (int i = 0; i < V.size(); i++) {
		

		if (checkList[V[i]] == 0) {
			checkList[V[i]] = 1;
			printV.push_back(V[i]);
			func(V, M, printV);
			printV.pop_back();
			checkList[V[i]] = 0;
		}
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

	

	func(V, M, printV);

}