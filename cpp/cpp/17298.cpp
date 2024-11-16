#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;
	vector<int> arr(n), result(n, -1);
	stack<int> s;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) cout << result[i] << " ";
	return 0;
}
