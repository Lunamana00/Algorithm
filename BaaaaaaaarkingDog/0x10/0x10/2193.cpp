#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int arr0[91];
	int arr1[91];

	arr0[1] = 0;
	arr0[2] = 1;
	arr0[3] = 1;
	
	arr1[1] = 1;
	arr1[2] = 0;
	arr1[3] = 1;


	for (int i = 3; i < N; i++) {

		arr0[i + 1] = arr1[i] + arr0[i];
		arr1[i + 1] = arr0[i];

	}

	cout << arr0[N] + arr1[N];

}