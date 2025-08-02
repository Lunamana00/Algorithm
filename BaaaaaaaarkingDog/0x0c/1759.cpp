#include <vector>
#include <iostream>
#include <algorithm>

int checkList[10001];

using namespace std;

void func(vector<char> V, int M, int cur, vector<char>& printV) {

	if (printV.size() == M) {
		int flag1 = 0;
		int flag2 = 0;
		vector<char> printer;

		for (auto x : printV) {
			if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
				flag1 = 1;
			}
			else {
				flag2++;
			}
		}


		if(flag1 == 1&&flag2 >=2){
			for (auto x : printV) {
				cout << x ;
			}
			cout << '\n';
		}
		return;
	}

	for (int i = cur; i < V.size(); i++) {

		printV.push_back(V[i]);
		func(V, M, i+1, printV);
		printV.pop_back();

	}

	return;

}

int main() {

	int L, C;
	vector<char> V;
	char x;

	cin >> L >> C;

	for (int i = 0; i < C; i++) {

		cin >> x;
		V.push_back(x);;

	}

	vector<char> printV;
	sort(V.begin(), V.end());

	func(V, L, 0, printV);

}