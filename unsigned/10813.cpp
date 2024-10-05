#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v;
	int a, b,c , d;
	cin >> a >> b;

	for (int i = 1; i <= a; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < b; i++) {
		int temp;
		cin >> c >> d;
		temp = v[d - 1];
		v[d - 1] = v[c - 1];
		v[c - 1] = temp;
	}

	for (int x : v) {
		cout << x << " ";
	}

}