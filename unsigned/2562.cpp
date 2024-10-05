#include <iostream>

using namespace std;

int main() {

	int n, count = 0, max = 0,max_num;
	while (cin >> n) {
		count += 1;
		if (max < n) {
			max = n;
			max_num = count;
		}

	}
	cout << max << "\n";
	cout << max_num;

}