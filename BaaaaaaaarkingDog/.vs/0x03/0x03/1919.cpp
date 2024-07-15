#include<iostream>
#include<vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int digit,count=0;
	string s1, s2;
	vector<int>v1(26);
	vector<int>v2(26);
	cin >> s1 >> s2;

	for (int i = 0; i < s1.length(); i++) {
		digit = s1[i] - 'a';
		v1[digit] += 1;
	}
	for (int i = 0; i < s2.length(); i++) {
		digit = s2[i] - 'a';
		v2[digit] += 1;
	}
	for (int i = 0; i < 26; i++) {
		count += abs(v1[i] - v2[i]);

	}
	cout << count;
}