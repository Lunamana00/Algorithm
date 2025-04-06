#include <iostream>
#include <vector>

using namespace std;

int n, m, x, curA=0,curB=0;

vector<int> vA;
vector<int> vB;
vector<int> vC;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		vA.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		vB.push_back(x);
	}
	for (int i = 0; i < n+m; i++) {
		if (curB >= m || vA[curA] >= vB[curB]) {
			vC.push_back(vA[curA]);
			curA++;
		}
		else if (curA >= n || vB[curB] >= vA[curA]) {
			vC.push_back(vB[curB]);
			curB++;
		}
	}
	for (auto x : vC) {
		cout << x << ' ';
	}
}