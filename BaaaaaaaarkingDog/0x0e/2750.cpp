#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int arr[1000];

void Qsort(int st, int en){
	if (en - st <= 1) {
		return;
	}

	int l = st + 1;
	int r = en -1;

	while (true) {
		while (l <= r && arr[st] >= arr[l]) {
			l++;
		}
		while (l <= r && arr[st] <= arr[r]) {
			r--;
		}
		if (l > r) {
			break;
		}
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]);
	Qsort(st, r);
	Qsort(r + 1, en);


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,x;
	cin >> N;

	for(int i = 0 ; i<N;i++) {
		cin >> x;
		arr[i] = x;
	}

	Qsort(0,N);

	for (int i = 0; i < N; i++) {
		cout << arr[i]<<'\n';
	}
}