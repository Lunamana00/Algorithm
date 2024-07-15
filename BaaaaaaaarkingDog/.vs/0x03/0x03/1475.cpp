#include<iostream>
#include<vector>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	vector<float> v(10);

	cin >> input;
	float count = 0;

	for (float i = 0; i < input.length(); i++) {
		int digit = input[i] - '0';
		v[digit] += 1;

	}
	v[6] += v[9];
	v[6] /= 2;
	v[9] = 0;

	for (auto x : v) {
		if (x > count) {
			count = x;
		}
	}

	if (!(int(count) == count)) {
		count = int(count) + 1;
	}
	cout << count;

}