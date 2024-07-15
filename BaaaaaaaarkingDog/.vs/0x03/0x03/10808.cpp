#include<iostream>
#include<vector>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	
	std::cin >> s;
	
	int len = s.size();

	for (char c = 'a'; c <= 'z'; c++) {
		int count = 0;
		for (char c_2 : s) {
			if (c == c_2) {
				count++;
			}
		}
		cout << count << ' ';
	}
}