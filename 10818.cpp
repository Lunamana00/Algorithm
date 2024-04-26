#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v;
	int a,b;
	cin >> b;
	for (int i = 0; i < b; ++i) {
		cin >> a;
		v.push_back(a);
	}

	int min = v[0], max = v[0];

	for (auto x : v) {

		if (x < min) min = x;
		if (x > max) max = x;

	}
	cout << min << " " << max;

}