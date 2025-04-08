#include <iostream>

using namespace std;
int N,x;
int board[2000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0;i < N;i++) {
		cin >> x;
		x = x + 1000000;
		board[x]++;
	}
	for (int i = 0;i <= 2000000;i++){
		while (board[i] > 0) {
			board[i]--;
			cout << i-1000000 << "\n";
		}
	}
}