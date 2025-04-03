#include <iostream>
#include <vector>


using namespace std;

int N, S, _count=0;
int v_input[30];


void func(int cur,int Tsum) {
	if (cur== N) {
		if(S == Tsum)
		_count++;
		return;
	}

	func(cur+1, Tsum);
	func(cur + 1, Tsum + v_input[cur]);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> N >> S;
	for (int i = 0;i < N;i++) {
		cin >> v_input[i];
	}
	func(0,0);
	if (S == 0) {
		_count--;
	}
	cout << _count;
}