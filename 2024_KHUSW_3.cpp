#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define SETTING std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using namespace std;
int main() {

	SETTING;

	int N, X, count = 0, buffer = 0;
	double sum;
	string calc;
	char ch;
	vector<int> v_num, v_plus, v_len, v_multilist;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> X;
		v_num.push_back(X);
	}
	sort(v_num.begin(), v_num.end());

	while (cin >> ch) {

		if (ch == '+') {
			v_plus.push_back(count);
		}
		count += 1;
		calc.push_back(ch);
	}

	for (auto x : v_plus) {
		v_len.push_back(x - buffer);
		buffer = x + 1;
	}

	v_len.push_back(calc.size() - v_plus[v_plus.size() - 1] - 1);

	for (auto x : v_len) {
		while (x > 0) {
			v_multilist.push_back(pow(10, x - 1));
			x -= 1;
		}
	}

	sort(v_multilist.begin(), v_multilist.end());

	for (int i = 0; i < v_num.size(); ++i) {
		sum += v_multilist[i] * v_num[i];
	}
	cout << sum;
}