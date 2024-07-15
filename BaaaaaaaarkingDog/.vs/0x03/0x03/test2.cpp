#include <iostream>
#include <vector>

int func2(int arr[], int N) {

	int bool_arr [100];
	int flag = 0;
	for (int i = 0; i < sizeof(arr);i++) {

		if (bool_arr[100-arr[i]] == 0) {
			bool_arr[arr[i]] = 1;
		}
		else {
			break;
			flag = 1;
		}
		return flag;
	}

}

int main() {

	

}