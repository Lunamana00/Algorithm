#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count=0,n,x;
	vector<int> v(10000);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v[x-1] += 1;
	}
	for (auto x : v) {
		count += 1;
		if (x) {
			for (int i = 0; i < x; i++) {
				cout << count << '\n';
			}
		}
	}
}