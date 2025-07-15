#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,sum = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	vector<int> aBoard(n);
	vector<int> bBoard(n);

	for (int i = 0; i < n; i++) {
		cin >> aBoard[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> bBoard[i];
	}
	sort(aBoard.begin(), aBoard.end());
	sort(bBoard.begin(), bBoard.end());
	reverse(bBoard.begin(),bBoard.end());

	for (int i = 0; i < n; i++) {
		sum += aBoard[i] * bBoard[i];
	}

	cout << sum;	
}