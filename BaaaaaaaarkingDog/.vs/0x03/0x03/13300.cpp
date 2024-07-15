#include<iostream>
#include<vector>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k, _gender, _class,count=0;
	cin >> n >> k;
	vector<int> male(7,0);
	vector<int> female(7,0);

	for (int i = 0; i < n; i++) {
		cin >> _gender >> _class;

		if (_gender == 0) {
			female[_class]++;
		}
		else {
			male[_class]++;
		}
	}
	for (auto x: male) {
		if (x % k) {
			count += (x / k + 1);
		}
		else {
			count += x / k;
		}
	}

	for (auto x : female) {
		if (x % k) {
			count += (x / k + 1);FileName
		}
		else {
			count += x / k;
		}
	}
	
	cout << count;

}