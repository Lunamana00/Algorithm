#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define SETTING std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using namespace std;
int main() {
	SETTING;
	int N, k, count = 0;
	vector<vector<double>> v_tree;
	vector<double> v_temp, v_tempX, v_tempY;
	double X, Y;


	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int s = 0; s < 3; ++s) {
			cin >> k;
			v_temp.push_back(k);
		}
		v_tree.push_back(v_temp);
		v_temp.clear();
	}


	for (double i = 0; i<double(v_tree.size()); ++i) {
		v_tempX.clear();
		v_tempY.clear();
		X = v_tree[i][0]; Y = v_tree[i][1];
		for (double s = 0; s<double(v_tree.size()); ++s) {
			if (X == v_tree[s][0] && (v_tree[i][2] < v_tree[s][2])) v_tempY.push_back(v_tree[s][1]);
			if (Y == v_tree[s][1] && (v_tree[i][2] < v_tree[s][2])) v_tempX.push_back(v_tree[s][0]);
		}

		if (!v_tempX.empty() && !v_tempY.empty()) {
			auto minX = *min_element(v_tempX.begin(), v_tempX.end());
			auto maxX = *max_element(v_tempX.begin(), v_tempX.end());
			auto minY = *min_element(v_tempY.begin(), v_tempY.end());
			auto maxY = *max_element(v_tempY.begin(), v_tempY.end());
			if (((minX < X) && (X < maxX)) && ((minY < Y) && (Y < maxY)))
				count += 1;
		}

	}
	cout << count;
}