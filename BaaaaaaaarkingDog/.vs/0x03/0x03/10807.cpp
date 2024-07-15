#include<iostream>
#include<vector>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,x,ans;
	vector<int> v(201);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v[x + 100] += 1;
	}

	cin >> ans;
	cout << v[ans + 100];
}