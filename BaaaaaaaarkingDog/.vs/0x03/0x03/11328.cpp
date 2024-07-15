#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, flag;
	cin >> N;

	string s1, s2;

	for (int i = 0; i < N; i++) {
		flag = 0;
		cin >> s1 >> s2;

		if (s1.length() != s2.length()) {
			cout << "Impossible" << endl;
			continue;
		}

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		for (int s = 0; s < s1.length(); s++) {
			if (!(s1[s] == s2[s])) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Possible" << endl;
		}
		else {
			cout << "Impossible" << endl;
		}
	}

}
