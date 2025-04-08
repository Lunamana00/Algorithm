#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int N;
string x;
vector<string> vSerial;

bool cmp(const string &a, const string &b) {
	if (a.size() < b.size()) {
		return true;
	}
	else if (a.size() > b.size()) {
		return false;
	}

	int aSum = 0, bSum = 0;
	for (auto x : a) {
		if (isdigit(x)) {
			aSum += x-'0';
		}
	}
	for (auto x : b) {
		if (isdigit(x)) {
			bSum += x - '0';
		}
	}
	
	if (aSum < bSum) {
		return true;
	}
	else if (bSum < aSum) {
		return false;
	}

	return a < b;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N;i++) {
		cin >> x;
		vSerial.push_back(x);
	}
	sort(vSerial.begin(),vSerial.end(), cmp);

	for (auto x : vSerial) {
		cout << x << '\n';
	}
}