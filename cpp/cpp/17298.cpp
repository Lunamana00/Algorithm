#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,temp;
	

	cin >> N;
	vector<int> v_input(N), v_masking(N);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v_input[i] = temp;
	}
	v_masking[-1] = -1;
	int before_val,before_top;
	for (int i = N - 2; i > 0; i--) {
		int x = i;
		for (int j = x; j + 1 < i; j++) {
			before_val = v_input[j + 1];
			before_top = v_masking[j + 1];
			if (before_val > )
		}
		
	}
}