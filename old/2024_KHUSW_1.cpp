#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define SETTING std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using namespace std;
int main() {

	SETTING;

	vector<string> v_n, v_t;
	vector<double> v_s;
	int N, point = 0;
	double score, max = -1;
	string name, temp_s = "11111111111";

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> name;
		cin >> score;
		v_n.push_back(name);
		v_s.push_back(score);
	}

	for (auto x : v_s) {
		if (x > max) {
			v_t.clear();
			max = x;
			v_t.push_back(v_n[point]);
		}
		else if (x == max) {
			v_t.push_back(v_n[point]);
		}
		point += 1;
	}

	for (auto x : v_t) {
		if (x.size() < temp_s.size())
			temp_s = x;
	}
	cout << temp_s;
}