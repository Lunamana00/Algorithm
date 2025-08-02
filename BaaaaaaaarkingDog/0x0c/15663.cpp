#include <vector>
#include <iostream>
#include <algorithm>

int checkList[10001];

using namespace std;

void func(vector<int> V, int M, vector<int>& printV) {

	if (printV.size() == M) {

		for (auto x : printV) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < V.size(); i++) {

		if(checkList[V[i]]){
			checkList[V[i]]--;
			printV.push_back(V[i]);
			func(V, M, printV);
			printV.pop_back();
			checkList[V[i]]++;
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
		if (checkList[x]==0) {
			V.push_back(x);
		}
		checkList[x]++;
		
		

	}

	vector<int> printV;
	sort(V.begin(), V.end());

	func(V, M, printV);

}