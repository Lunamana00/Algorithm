#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>


using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int M;
	string input;
	cin >> input >> M;
	list<char> L;
	for (auto k : input) {
		L.push_back(k);
	}
	auto cursor = L.end();

	for (int i = 0; i < M; i++) {

		char order;
		cin >> order;

		if (order == 'L') {
			if (cursor != L.begin()) {
				cursor--;
			}
		}
		else if (order == 'D') {
			if (cursor != L.end()) {
				cursor++;
			}
		}
		else if (order == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		else {
			char _x;
			cin >> _x;

			L.insert(cursor, _x);

		}

	}
	for (auto k : L) {
		cout << k;
	}
}